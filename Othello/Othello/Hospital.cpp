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
	//赋值7个常量
	istr >> n >> m >> T >> t1 >> t2 >> t3 >> k;
	//为患者队列赋值
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
	//为手术室队列赋值
	int spare_time_init = 0;
	for (int i = 1; i != this->n + 1; ++i) {
		shared_ptr<Operatorhome> o_p = make_shared<Operatorhome>(i, spare_time_init, this->t2);
		this->operatorhomes.push_back(*o_p);
	}
	//为恢复室队列赋值
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
	//初始化患者第二队列
	vector<Patient> v_p;
	int time = 0;
	while (judge(time)) {
		if (!patients.empty()) //如果patients非空
			for (auto iter_operhome = operatorhomes.begin(); iter_operhome != operatorhomes.end(); ++iter_operhome) {
				if (iter_operhome->spare_time_op(0) <= time) {
					//更新患者队列第一个患者的手术完成时间
					patients.begin()->finish_operator_time(time);
					//更新患者队列第一个患者的手术室编号
					patients.begin()->num_pr(iter_operhome->num_op());
					//存入患者第二队列
					v_p.push_back(*patients.begin());
					//更新手术室空闲时间
					iter_operhome->spare_time_op(time + patients.begin()->operatoration_time());
					//从患者第一队列中删除
					patients.erase(patients.begin());
				}
			}
		if (!v_p.empty())
			//对患者第二队列排序
			sort(v_p.begin(), v_p.end(), patient_compare());
			for (auto iter_recohome = recoverhomes.begin(); iter_recohome != recoverhomes.end(); ++iter_recohome) {
				if (iter_recohome->spare_time_op(0) <= time) {
					for (auto iter_p = v_p.begin(); iter_p != v_p.end(); ++iter_p) {
						if (iter_p->finish_operator_time(0) <= time) {
							//更新恢复室的空闲时间
							iter_recohome->spare_time_op(iter_p->recovery_time());
							//进入恢复室的患者从第二患者队列中出队
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