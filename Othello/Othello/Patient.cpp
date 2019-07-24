#include "pch.h"
#include "Patient.h"
#include <string>
using namespace std;
Patient::Patient(const string &names, const int &operatorations, const int &recoverys) :
	name(names), operatoration(operatorations), recovery(recoverys) {
	finish_operator = operatoration;
}
Patient::~Patient() {}
Patient::Patient(const Patient &p) {
	this->num = p.num;
	this->name = p.name;
	this->operatoration = p.operatoration;
	this->recovery = p.recovery;
	this->finish_operator = finish_operator;
}
Patient::Patient(Patient &&p) {
	this->num = p.num;
	this->name = p.name;
	this->operatoration = p.operatoration;
	this->recovery = p.recovery;
	this->finish_operator = p.finish_operator;
	p.num = 0;
	p.name.clear();
	p.operatoration = 0;
	p.recovery = 0;
	p.finish_operator = 0;
}
Patient & Patient::operator=(const Patient &p) {
	this->num = p.num;
	this->name = p.name;
	this->operatoration = p.operatoration;
	this->recovery = p.recovery;
	this->finish_operator = finish_operator;
	return *this;
}
Patient & Patient::operator=(Patient &&p) {
	this->num = p.num;
	this->name = p.name;
	this->operatoration = p.operatoration;
	this->recovery = p.recovery;
	this->finish_operator = p.finish_operator;
	p.num = 0;
	p.name.clear();
	p.operatoration = 0;
	p.recovery = 0;
	p.finish_operator = 0;
	return *this;
}
int Patient::operatoration_time() {
	return this->operatoration;
}
int Patient::recovery_time() {
	return this->recovery;
}
int Patient::finish_operator_time(const int &time) {
	this->finish_operator += time;
	return this->finish_operator;
}
int Patient::num_pr(const int &nums) {
	if (nums == 0) return this->num;
	else this->num = nums;
	return this->num;
}