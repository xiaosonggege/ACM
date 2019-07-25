#include "pch.h"
#include "Hospital.h"
#include "Operatorhome.h"
#include "Recoverhome.h"
#include "patient_compare.h"
#include "Patient.h"
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <map>
#include <iostream>
#include <sstream>
#include <utility>
#include <algorithm>
using namespace std;
Hospital::Hospital(const string &p) {
	ifstream ifstrm;
	ifstrm.open(p, ios::in);
	string s;
	getline(ifstrm, s);
	istringstream istr(s);
	//��ֵ7������
	istr >> n >> m >> T >> t1 >> t2 >> t3 >> k;
	//Ϊ���߶��и�ֵ
	int flag_name = 1, flag_times = 0;
	shared_ptr<string> strp = make_shared<string>();
	while (getline(ifstrm, s)) {
		if (flag_name) {
			*strp = s;
			flag_name = 0;
			flag_times = 1;
		}
		else if (flag_times) {
			istringstream istr2(s);
			string name;
			int oper_time, reco_time;
			istr2 >> oper_time >> reco_time;
			shared_ptr<Patient> pp = make_shared<Patient>(*strp, oper_time, reco_time);
			this->patients.push_back(*pp);
			flag_name = 1;
  			flag_times = 0;
		}

	}
	//Ϊ�����Ҷ��и�ֵ
	int spare_time_init = 0;
	for (int i = 1; i != this->n + 1; ++i) {
		shared_ptr<Operatorhome> o_p = make_shared<Operatorhome>(i, spare_time_init, this->t2);
		this->operatorhomes.push_back(*o_p);
	}
	//Ϊ�ָ��Ҷ��и�ֵ
	for (int i = 1; i != this->m + 1; ++i) {
		shared_ptr<Recoverhome> r_p = make_shared<Recoverhome>(i, spare_time_init, this->t3);
		this->recoverhomes.push_back(*r_p);
	}
	ifstrm.close();
}
Hospital::~Hospital() {}
Hospital::Hospital(const Hospital &h) {
	this->n = h.n;
	this->m = h.m;
	this->T = h.T;
	this->t1 = h.t1;
	this->t2 = h.t2;
	this->t3 = h.t3;
	this->k = h.k;
	this->patients = h.patients;
	this->operatorhomes = h.operatorhomes;
	this->recoverhomes = h.recoverhomes;
}
Hospital::Hospital(Hospital &&h) {
	this->n = h.n;
	this->m = h.m;
	this->T = h.T;
	this->t1 = h.t1;
	this->t2 = h.t2;
	this->t3 = h.t3;
	this->k = h.k;
	this->patients = h.patients;
	this->operatorhomes = h.operatorhomes;
	this->recoverhomes = h.recoverhomes;
	h.patients.clear();
	h.operatorhomes.clear();
	h.recoverhomes.clear();
	h.n = 0;
	h.m = 0;
	h.T = 0;
	h.t1 = 0;
	h.t2 = 0;
	h.t3 = 0;
	h.k = 0;
}
Hospital & Hospital::operator=(const Hospital &h) {
	this->n = h.n;
	this->m = h.m;
	this->T = h.T;
	this->t1 = h.t1;
	this->t2 = h.t2;
	this->t3 = h.t3;
	this->k = h.k;
	this->patients = h.patients;
	this->operatorhomes = h.operatorhomes;
	this->recoverhomes = h.recoverhomes;
	return *this;
}
Hospital & Hospital::operator=(Hospital &&h) {
	this->n = h.n;
	this->m = h.m;
	this->T = h.T;
	this->t1 = h.t1;
	this->t2 = h.t2;
	this->t3 = h.t3;
	this->k = h.k;
	this->patients = h.patients;
	this->operatorhomes = h.operatorhomes;
	this->recoverhomes = h.recoverhomes;
	h.patients.clear();
	h.operatorhomes.clear();
	h.recoverhomes.clear();
	h.n = 0;
	h.m = 0;
	h.T = 0;
	h.t1 = 0;
	h.t2 = 0;
	h.t3 = 0;
	h.k = 0;
	return *this;
}
ostream & Hospital::work(ostream &os) {
	//��ʼ�����ߵڶ�����
	vector<Patient> v_p;
	int time = 0;
	while (judge(time)) {
		if (!patients.empty()) //���patients�ǿ�
			for (auto iter_operhome = operatorhomes.begin(); iter_operhome != operatorhomes.end(); ++iter_operhome) {
				if (iter_operhome->spare_time_op(0) <= time) {
					//���»��߶��е�һ�����ߵ��������ʱ��
					patients.begin()->finish_operator_time(time);
					//���»��߶��е�һ�����ߵ������ұ��
					patients.begin()->num_pr(iter_operhome->num_op());
					//���뻼�ߵڶ�����
					v_p.push_back(*patients.begin());
					//���������ҿ���ʱ��
					iter_operhome->spare_time_op(time + patients.begin()->operatoration_time());
					//�ӻ��ߵ�һ������ɾ��
					patients.erase(patients.begin());
				}
			}
		if (!v_p.empty())
			//�Ի��ߵڶ���������
			sort(v_p.begin(), v_p.end(), patient_compare());
			for (auto iter_recohome = recoverhomes.begin(); iter_recohome != recoverhomes.end(); ++iter_recohome) {
				if (iter_recohome->spare_time_op(0) <= time) {
					for (auto iter_p = v_p.begin(); iter_p != v_p.end(); ++iter_p) {
						if (iter_p->finish_operator_time(0) <= time) {
							//���»ָ��ҵĿ���ʱ��
							iter_recohome->spare_time_op(iter_p->recovery_time());
							//����ָ��ҵĻ��ߴӵڶ����߶����г���
							v_p.erase(iter_p);
							break;
						}
					}
				}
			}
		++time;
	}
	os << time << endl;
	return os;
}
bool Hospital::judge(const int &time) {
	for (auto iter = recoverhomes.begin(); iter != recoverhomes.end(); ++iter) {
		if (iter->spare_time_op(0) >= time) return 1;
	}
	return 0;
}