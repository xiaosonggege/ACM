#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "pch.h"
#include "Operatorhome.h"
#include "Recoverhome.h"
#include "Patient.h"
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <map>
#include <iostream>
#include <utility>
using namespace std;
class Hospital {
private:
	//手术室个数、恢复室个数、手术室开放时间、从手术室到恢复室时间、准备手术室时间、准备恢复室时间和病人个数
	int n, m, T, t1, t2, t3, k;
	vector<Patient> patients; //所有病人的名字、手术时间、恢复时间
	vector<Operatorhome> operatorhomes; //手术室按编号从小到大排列
	vector<Recoverhome> recoverhomes; //恢复室按编号从小到大排列
public:
	Hospital() = default;
	Hospital(const string &);
	~Hospital();
	Hospital(const Hospital &);
	Hospital(Hospital &&);
	Hospital & operator=(const Hospital &);
	Hospital & operator=(Hospital &&);
	ostream & work(ostream &); //医院设备运作流程
	bool judge(const int &);
};
#endif // !HOSPITAL_H

