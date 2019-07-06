#include "pch.h"
#include "Map.h"
#include "Location.h"
#include "Comparing.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <utility>
#include <iterator>
using namespace std;
Map::Map(const string &ps) : p(ps) {
	//为m和loc赋值
	ifstream ifstrm;
	string s;
	int flag1 = 0, flag2 = 0, flag3 = 0; //读文件标志
	ifstrm.open(this->p, ios::in);
	while (getline(ifstrm, s)) {
		if (s == "MAPS") {
			flag1 = 1;
			continue;
		}
		if (s == "LOCATIONS") {
			flag1 = 0, flag2 = 1;
			continue;
		}
		if (s == "REQUESTS") {
			flag2 = 0, flag3 = 1;
			continue;
		}
		if (s == "END") break;
		istringstream istr(s);
		string mapp;
		int level;
		vector<double> v_4;
		istr >> mapp;
		if (flag1) {//mm
			istream_iterator<double> iter_in(istr), eof;
			v_4.assign(iter_in, eof);
			this->mm.push_back({ mapp, v_4 });
		}
		if (flag2) {//loc
			istream_iterator<double> iter_in(istr), eof;
			v_4.assign(iter_in, eof);
			this->loc[mapp] = v_4;
		}
		if (flag3) {//lv
			istr >> level;
			this->lv.push_back(Location<int>(mapp, level));
		}
	}
	ifstrm.close();
}
Map::~Map() {}
Map::Map(const Map &m) {
	this->lv = m.lv;
	this->mm = m.mm;
	this->loc = m.loc;
}
Map::Map(Map &&m) {
	this->lv = m.lv;
	this->mm = m.mm;
	this->loc = m.loc;
	m.lv.clear();
	m.mm.clear();
	m.loc.clear();
}
Map & Map::operator=(const Map &m) {
	this->lv = m.lv;
	this->mm = m.mm;
	this->loc = m.loc;
	return *this;
}
Map & Map::operator=(Map &&m) {
	this->lv = m.lv;
	this->mm = m.mm;
	this->loc = m.loc;
	m.lv.clear();
	m.mm.clear();
	m.loc.clear();
	return *this;
}
ostream & Map::finding(ostream &os) {
	//采集location中的名字
	vector<string> locations;
	for (auto iter = loc.begin(); iter != loc.end(); ++iter) locations.push_back(iter->first);
	//遍历requests中的所有请求
	for (const auto &e : this->lv) {
		//如果requests中有，但是locations中没有
		if (find(locations.begin(), locations.end(), e.name) == locations.end()) os << e.name << " at detail level " <<  
			e.level << " unknown location" << endl;
		//如果requests和locations中都有，但是等级序号大于mm长度
		else if (e.level > this->mm.size())
			os << e.name << " at detail level " << e.level << " no map at that detail level; using " << this->mm[mm.size()-1].first << endl;
		else {
			//对mm进行排序
			Comparing comp(this->loc[e.name]);
			sort(this->mm.begin(), this->mm.end(), comp);
			os << e.name << " at detail level " << e.level << " using " << this->mm[e.level-1].first << endl;
		}
	}
	return os;
}
