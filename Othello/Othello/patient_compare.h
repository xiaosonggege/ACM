#ifndef PATIENT_COMPARE_H
#define PATIENT_COMPARE_H
#include "pch.h"
#include "Patient.h"
using namespace std;
class patient_compare {
public:
	bool operator()(Patient p1, Patient p2) const {
		if (p1.finish_operator_time(0) == p2.finish_operator_time(0))
			return p1.num_pr(0) < p2.num_pr(0);
		else return p1.finish_operator_time(0) < p2.finish_operator_time(0);
	}
};
#endif // !PATIENT_COMPARE_H

