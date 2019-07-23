#include "pch.h"
#include "Hospital.h"
#include "Operatorhome.h"
#include "Recoverhome.h"
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <map>
#include <iostream>
#include <sstream>
#include <utility>
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
			shared_ptr<vector<int>> vecp = make_shared<vector<int>>();
			istringstream istr2(s);
			istream_iterator<int> iter_in(istr2), eof;
			vecp->assign(iter_in, eof);
			this->patients.push_back({ *strp, *vecp });
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

	return os;
}