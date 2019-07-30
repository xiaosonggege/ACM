#include "pch.h"
#include "Operatorhome.h"
#include <sstream>
#include <string>
#include <sstream>
using namespace std;
Operatorhome::Operatorhome(const int &nums, int &spare_times, const int &prepare_times) :
	num(nums), spare_time(spare_times), prepare_time(prepare_times) {}
Operatorhome::~Operatorhome() {}
Operatorhome::Operatorhome(const Operatorhome &op) {
	this->num = op.num;
	this->spare_time = op.spare_time;
	this->prepare_time = op.prepare_time;
}
Operatorhome::Operatorhome(Operatorhome &&op) {
	this->num = op.num;
	this->spare_time = op.spare_time;
	this->prepare_time = op.prepare_time;
	op.num = 0;
	op.spare_time = 0;
	op.prepare_time = 0;
}
Operatorhome & Operatorhome::operator=(const Operatorhome &op) {
	this->num = op.num;
	this->spare_time = op.spare_time;
	this->prepare_time = op.prepare_time;
	return *this;
}
Operatorhome & Operatorhome::operator=(Operatorhome &&op) {
	this->num = op.num;
	this->spare_time = op.spare_time;
	this->prepare_time = op.prepare_time;
	op.num = 0;
	op.spare_time = 0;
	op.prepare_time = 0;
	return *this;
}
int Operatorhome::num_op() {
	return this->num;
}
int Operatorhome::spare_time_op(const int &time) {
	if (time == 0) return this->spare_time;
	else this->spare_time = time+this->prepare_time;
	return this->spare_time;
}
int Operatorhome::prepare_time_op() {
	return this->spare_time;
}