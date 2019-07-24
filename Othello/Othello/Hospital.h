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
	//�����Ҹ������ָ��Ҹ����������ҿ���ʱ�䡢�������ҵ��ָ���ʱ�䡢׼��������ʱ�䡢׼���ָ���ʱ��Ͳ��˸���
	int n, m, T, t1, t2, t3, k;
	vector<Patient> patients; //���в��˵����֡�����ʱ�䡢�ָ�ʱ��
	vector<Operatorhome> operatorhomes; //�����Ұ���Ŵ�С��������
	vector<Recoverhome> recoverhomes; //�ָ��Ұ���Ŵ�С��������
public:
	Hospital() = default;
	Hospital(const string &);
	~Hospital();
	Hospital(const Hospital &);
	Hospital(Hospital &&);
	Hospital & operator=(const Hospital &);
	Hospital & operator=(Hospital &&);
	ostream & work(ostream &); //ҽԺ�豸��������
	bool judge(const int &);
};
#endif // !HOSPITAL_H

