#include "pch.h"
#include "Unixls.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <memory>
#include <vector>
using namespace std;
Unixls::Unixls(const string &ps) : p(ps) {}
Unixls::Unixls(const Unixls &u) {
	this->p = u.p;
}
Unixls::Unixls(Unixls &&u) {
	this->p = u.p;
	u.p.clear();
}
Unixls::~Unixls() {}
Unixls & Unixls::operator=(const Unixls &u) {
	this->p = u.p;
	return *this;
}
Unixls & Unixls::operator=(Unixls &&u) {
	this->p = u.p;
	u.p.clear();
	return *this;
}
ostream & Unixls::output(ostream &os) {
	string s;
	shared_ptr<vector<string>> pv = make_shared<vector<string>>();
	int num = 0; //记录各行文件数
	ifstream fstrm;
	fstrm.open(this->p);
	istream_iterator<string> in_iter(fstrm), eof;
	pv->assign(in_iter, eof);
	fstrm.close();
	//找到读入序列中的最大长度序列
	auto comp = [](const string &l1, const string &l2) {return l1.size() < l2.size(); };
	vector<string>::iterator max_iter = max_element(pv->begin(), pv->end(), comp);
	int length = max_iter->size() + 2;
	for (auto iter = pv->begin(); iter != pv->end(); ++iter) {
		int length_else = length - iter->size();
		os << *iter;
		for (int i = 0; i != length_else; ++i) os << " ";
		if ((++num) == 5) {
			os << endl;
			num = 0;
		}
	}
	return os;
}