#include "pch.h"
#include "Recoverhome.h"
#include <string>
#include <sstream>
using namespace std;
Recoverhome::Recoverhome(const int &nums, int &spare_times, const int &prepare_times) :
	num(nums), spare_time(spare_times), prepare_time(prepare_times) {}
Recoverhome::~Recoverhome() {}
Recoverhome::Recoverhome(const Recoverhome &r) {
	this->num = r.num;
	this->spare_time = r.spare_time;
	this->prepare_time = r.prepare_time;
}
Recoverhome::Recoverhome(Recoverhome &&r) {
	this->num = r.num;
	this->spare_time = r.spare_time;
	this->prepare_time = r.prepare_time;
	r.num = 0;
	r.spare_time = 0;
	r.prepare_time = 0;
}
Recoverhome & Recoverhome::operator=(const Recoverhome &r) {
	this->num = r.num;
	this->spare_time = r.spare_time;
	this->prepare_time = r.prepare_time;
	return *this;
}
Recoverhome & Recoverhome::operator=(Recoverhome &&r) {
	this->num = r.num;
	this->spare_time = r.spare_time;
	this->prepare_time = r.prepare_time;
	r.num = 0;
	r.spare_time = 0;
	r.prepare_time = 0;
	return *this;
}
int Recoverhome::num_op() {
	return this->num;
}
int Recoverhome::spare_time_op(const int &time) {
	if (time == 0) return this->spare_time;
	else this->spare_time += time + this->prepare_time;
	return this->spare_time;
}
int Recoverhome::prepare_time_op() {
	return this->prepare_time;
}