#include "pch.h"
#include "Ducci.h"
#include <vector>
#include <algorithm>
#include <memory>
#include <iterator>
#include <tuple>
using namespace std;
Ducci::Ducci(const vector<int> &sequences) : sequence(sequences) {}
Ducci::~Ducci() {}
Ducci::Ducci(const Ducci &d) {
	this->sequence = d.sequence;
	this->is_becoming_zero = d.is_becoming_zero;
}
Ducci::Ducci(Ducci &&d) {
	this->sequence = d.sequence;
	this->is_becoming_zero = d.is_becoming_zero;
	d.sequence.clear();
	d.is_becoming_zero = 0;
}
Ducci & Ducci::operator=(const Ducci &d) {
	this->sequence = d.sequence;
	this->is_becoming_zero = d.is_becoming_zero;
	return *this;
}
Ducci & Ducci::operator=(Ducci &&d) {
	this->sequence = d.sequence;
	this->is_becoming_zero = d.is_becoming_zero;
	d.sequence.clear();
	d.is_becoming_zero = 0;
	return *this;
}
int Ducci::judge(vector<int> &v1, vector<vector<int>> &v) {
	shared_ptr<vector<int>> v_temp = make_shared<vector<int>>();
	for (int i = 0; i != 4; ++i) {
		int diff = abs(v1[(i + 1) % 4] - v1[i % 4]);
		v_temp->push_back(diff);
	}
	 if (all_of(v_temp->begin(), v_temp->end(), [](int a)->bool {return a == 0; }))
		 this->is_becoming_zero = 1; //新序列值全为零，则直接输出标志
	 else if (find(v.begin(), v.end(), *v_temp) != v.end()) 
		 this->is_becoming_zero = 0;  //新序列已经存在于统计序列中，则直接输出标志
	 else {
		 v.push_back(*v_temp);
		 v1 = *v_temp;
		 this->judge(v1, v);
	 }
	return 0;
}
tuple<vector<int>, bool> Ducci::print() const {
	tuple<vector<int>, bool> tup(this->sequence, this->is_becoming_zero);
	return tup;
}