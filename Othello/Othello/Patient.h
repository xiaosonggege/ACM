#ifndef PATIENT_H
#define PATIENT_H
#include "pch.h"
#include <string>
using namespace std;
class Patient {
private:
	int num = 0;
	string name;
	int operatoration;
	int recovery;
	int finish_operator = 0;
public:
	Patient() = default;
	Patient(const string &, const int &, const int &);
	~Patient();
	Patient(const Patient &);
	Patient(Patient &&);
	Patient & operator=(const Patient &);
	Patient & operator=(Patient &&);
	int operatoration_time();
	int recovery_time();
	int finish_operator_time(const int &);
	int num_pr(const int &);
};
#endif // !PATIENT_H

