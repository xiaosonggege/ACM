#include "pch.h"
#include "Topic.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;
Topic::Topic(const string &str) {
	istringstream istr(str);
	istr >> tid >> num >> t0 >> t >> dt;
	next_time = t0;
}
Topic::~Topic() {}
Topic::Topic(const Topic &tt) {
	this->tid = tt.tid;
	this->num = tt.num;
	this->t0 = tt.t0;
	this->t = tt.t;
	this->dt = tt.dt;
}
Topic::Topic(Topic &&tt) {
	this->tid = tt.tid;
	this->num = tt.num;
	this->t0 = tt.t0;
	this->t = tt.t;
	this->dt = tt.dt;
	tt.tid = 0;
	tt.num = 0;
	tt.t0 = 0;
	tt.t = 0;
	tt.dt = 0;
}
Topic & Topic::operator=(const Topic &tt) {
	this->tid = tt.tid;
	this->num = tt.num;
	this->t0 = tt.t0;
	this->t = tt.t;
	this->dt = tt.dt;
	return *this;
}
Topic & Topic::operator=(Topic &&tt) {
	this->tid = tt.tid;
	this->num = tt.num;
	this->t0 = tt.t0;
	this->t = tt.t;
	this->dt = tt.dt;
	tt.tid = 0;
	tt.num = 0;
	tt.t0 = 0;
	tt.t = 0;
	tt.dt = 0;
	return *this;
}
int Topic::change(int time) {
	++count;
	next_time = time + dt;
	return 0;
}