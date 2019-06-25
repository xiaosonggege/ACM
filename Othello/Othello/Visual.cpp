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
	//提取文件中的建筑信息
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
	//提取出v_urban中各个建筑的主视图宽度端点，并按照降序排列,删除重复区间端点
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
	//对每一区间生成遮挡序列，先按y值升序排列，取第一个，再从第二个开始判断高度
	for (auto iter = qujian.begin(); iter != qujian.end() - 1; ++iter) {
		shared_ptr<vector<Urban<double>>> v_u = make_shared<vector<Urban<double>>>();
		//计算区间中点值
		double mid = (*iter + *(iter + 1)) / 2;
		//找出所有在此区间内备选可见建筑
		for (const auto &e : this->v_urban) {
			if (mid >= e.x && mid < (e.x + e.weigh)) {
				v_u->push_back(e);
			}
		}
		if (v_u->size()) {
			//将v_u中元素按照y值升序排列
			auto key = [](const Urban<double> &u1, const Urban<double> &u2)->bool {return u1.y < u2.y; };
			sort(v_u->begin(), v_u->end(), key);
			//取第一个
			auto pos = find(this->number.begin(), this->number.end(), v_u->begin()->num);
			if (pos == this->number.end()) this->number.push_back(v_u->begin()->num);
			double high_max = (v_u->begin())->high; //此区间内最高建筑高度值初始化为首元素高度
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