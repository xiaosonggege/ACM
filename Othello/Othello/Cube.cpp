#include "pch.h"
#include "Cube.h"
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
Cube::Cube(const map<int, char> &m1, const map<vector<int>, vector<int>> &m2, const string &p):
	painting(m1), order(m2), p(p) {}
Cube::~Cube() {}
Cube::Cube(const Cube &c) {
	this->painting = c.painting;
	this->order = c.order;
	this->p = c.p;
}
Cube::Cube(Cube &&c) {
	this->painting = c.painting;
	this->order = c.order;
	this->p = c.p;
	c.painting.clear();
	c.order.clear();
	c.p.clear();
}
Cube & Cube::operator=(const Cube &c) {
	this->painting = c.painting;
	this->order = c.order;
	this->p = c.p;
	return *this;
}
Cube & Cube::operator=(Cube &&c) {
	this->painting = c.painting;
	this->order = c.order;
	this->p = c.p;
	c.painting.clear();
	c.order.clear();
	c.p.clear();
	return *this;
}
ostream & Cube::judge(ostream &os) {
    //初始化存储所有情况的向量
	vector<string> v;
	string s;
	for (auto iter = order.begin(); iter != order.end(); ++iter) {
		string s_m, s_mm;
		pair<vector<int>, vector<int>> pairr = *iter;
		//遍历中间循环队列中的值对应的颜色顺序存入s_m和s_mm
		for (int i = 0; i != 4; ++i) {
			//将顺序映射中的顶和底部编号对应颜色存入临时字符串s_m和s_mm中
			s_mm.push_back(painting[pairr.first[0]]);
			s_m.push_back(painting[pairr.first[1]]);
			for (int j = i; j != i + 4; ++j) {
				s_m.push_back(painting[pairr.second[j % 4]]);
				s_mm.push_back(painting[pairr.second[j % 4]]);
			}
			s_mm.push_back(painting[pairr.first[1]]);
			s_m.push_back(painting[pairr.first[0]]);
			//将两种情况存入v
			v.push_back(s_m);
			v.push_back(s_mm);
			//清空s_m和s_mm
			s_m.clear();
			s_mm.clear();
		}
	}
	//open the textfile
	fstream fstrm;
	fstrm.open(p, ios::in);
	while (getline(fstrm, s)) {
		string s1(s.begin(), s.begin() + 6), s2(s.begin() + 6, s.end());
		auto pos1 = find(v.begin(), v.end(), s1);
		auto pos2 = find(v.begin(), v.end(), s2);
		if (pos1 != v.end() && pos2 != v.end()) os <<  1<< endl;
		else os << 0 << endl;
	}
	fstrm.close();
	return os;
}