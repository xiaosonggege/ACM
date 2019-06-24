#include "pch.h"
#include "Database.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
Database::Database(const string &ps): p(ps) {}
Database::~Database() {}
Database::Database(const Database &d) {
	this->p = d.p;
}
Database::Database(Database &&d) {
	this->p = d.p;
	d.p.clear();
}
Database & Database::operator=(const Database &d) {
	this->p = d.p;
	return *this;
}
Database & Database::operator=(Database &&d) {
	this->p = d.p;
	d.p.clear();
	return *this;
}
vector<int> Database::judge(const vector<string> &v1, const vector<string> &v2) const {
	for (int pre = 0; pre != v1.size()-1; ++pre) {
		for (int lat = pre + 1; lat != v1.size(); ++lat) {
			if (v1[pre] == v1[lat])
				if (v2[pre] == v2[lat]) {
					vector<int> position = { pre, lat };
					return position;
				}
		}
	}
	vector<int> v_finally = { 0, 0 };
	return v_finally;
}
ostream & Database::print(ostream &os, const vector<vector<string>> &metric) const {
	vector<int> v_temp = { 0, 0 };
	for (int pos = 0; pos != metric[0].size() - 1; ++pos) {
		for (int j = pos + 1; j != metric[0].size(); ++j) {
			shared_ptr<vector<string>> s1 = make_shared<vector<string>>(), s2 = make_shared<vector<string>>();
			for (int i = 0; i != metric.size(); ++i) { s1->push_back(metric[i][pos]); s2->push_back(metric[i][j]); }
			shared_ptr<vector<int>> v_p = make_shared<vector<int>>();
			*v_p = judge(*s1, *s2);
			if (*v_p != v_temp) {
				os << (*v_p)[0] << " " << (*v_p)[1] << " " << pos << " " << j << endl;
				return os;
			}
		}
	}
	return os;
}
ostream & Database::operator()(ostream &os) const {
	shared_ptr < vector<vector<string>>> metric_p = make_shared < vector<vector<string>>>();
	shared_ptr<vector<string>> vp = make_shared<vector<string>>();
	int flag = 0;
	shared_ptr<string> temp_s = make_shared<string>();
	ifstream fstrm;
	fstrm.open(this->p, ios::in);
	while (getline(fstrm, *temp_s)) {
		if (flag == 3) {
			metric_p->push_back(*vp);
			flag = 0;
			vp->clear();
		}
		vp->push_back(*temp_s);
		++flag;
	}
	metric_p->push_back(*vp);
	fstrm.close();
	return print(os, *metric_p);
}
int Database::show() {
	return 0;
}