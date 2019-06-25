#include "pch.h"
#include "Urban.h"
#include "Visual.h"
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
using namespace std;
Visual::Visual(const string &ps) : p(ps) {
	//��ȡ�ļ��еĽ�����Ϣ
	ifstream iftrm;
	iftrm.open(this->p, ios::in);
	shared_ptr<string> s = make_shared<string>();
	int nums = 1;
	while (getline(iftrm, *s)) {
		shared_ptr<Urban<double>> u = make_shared<Urban<double>>(*s, nums);
		this->v_urban.push_back(*u);
		++nums;
	}
	iftrm.close();
	//��ȡ��v_urban�и�������������ͼ��ȶ˵㣬�����ս�������,ɾ���ظ�����˵�
	for (auto iter = v_urban.begin(); iter != v_urban.end(); ++iter) {
		this->qujian.push_back(iter->x);
		this->qujian.push_back(iter->x + iter->weigh);
	}
	sort(this->qujian.begin(), this->qujian.end());
	auto iter_erase = unique(this->qujian.begin(), this->qujian.end());
	this->qujian.erase(iter_erase, this->qujian.end());
}
Visual::~Visual() {}
Visual::Visual(const Visual &v) {
	this->v_urban = v.v_urban;
	this->qujian = v.qujian;
	this->number = v.number;
}
Visual::Visual(Visual &&v) {
	this->v_urban = v.v_urban;
	this->qujian = v.qujian;
	this->number = v.number;
	v.v_urban.clear();
	v.qujian.clear();
	v.number.clear();
}
Visual & Visual::operator=(const Visual &v) {
	this->v_urban = v.v_urban;
	this->qujian = v.qujian;
	this->number = v.number;
	return *this;
}
Visual & Visual::operator=(Visual &&v) {
	this->v_urban = v.v_urban;
	this->qujian = v.qujian;
	this->number = v.number;
	v.v_urban.clear();
	v.qujian.clear();
	v.number.clear();
	return *this;
}
ostream & Visual::findvisual(ostream &os) {
	//��ÿһ���������ڵ����У��Ȱ�yֵ�������У�ȡ��һ�����ٴӵڶ�����ʼ�жϸ߶�
	for (auto iter = qujian.begin(); iter != qujian.end() - 1; ++iter) {
		shared_ptr<vector<Urban<double>>> v_u = make_shared<vector<Urban<double>>>();
		//���������е�ֵ
		double mid = (*iter + *(iter + 1)) / 2;
		//�ҳ������ڴ������ڱ�ѡ�ɼ�����
		for (const auto &e : this->v_urban) {
			if (mid >= e.x && mid < (e.x + e.weigh)) {
				v_u->push_back(e);
			}
		}
		if (v_u->size()) {
			//��v_u��Ԫ�ذ���yֵ��������
			auto key = [](const Urban<double> &u1, const Urban<double> &u2)->bool {return u1.y < u2.y; };
			sort(v_u->begin(), v_u->end(), key);
			//ȡ��һ��
			auto pos = find(this->number.begin(), this->number.end(), v_u->begin()->num);
			if (pos == this->number.end()) this->number.push_back(v_u->begin()->num);
			double high_max = (v_u->begin())->high; //����������߽����߶�ֵ��ʼ��Ϊ��Ԫ�ظ߶�
			for (auto iter = v_u->begin() + 1; iter != v_u->end(); ++iter) {
				if (iter->high > high_max) {
					high_max = iter->high;
					auto pos = find(this->number.begin(), this->number.end(), iter->num);
					if (pos == this->number.end()) this->number.push_back(iter->num);
				}
			}
		}
	}
	for (const auto &e : this->number) os << e << " ";
	os << endl;
	return os;
}