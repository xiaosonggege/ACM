#ifndef VISUAL_H
#define VISUAL_H
#include "pch.h"
#include "Urban.h"
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Visual {
private:
	const string &p = ""; //�ļ�·�� ���ɸ���
	vector<Urban<double>> v_urban; //�����н���Ⱥ�б�
	vector<double> qujian; //ȥ�ظ����x��������
	vector<int> number; //����ͼ���ӵĽ������
public:
	Visual() = default;
	Visual(const string &);
	~Visual();
	Visual(const Visual &);
	Visual(Visual &&);
	Visual & operator=(const Visual &);
	Visual & operator=(Visual &&);
	ostream & findvisual(ostream &);
};
#endif // !VISUAL_H

