#ifndef CUBE_H
#define CUBE_H
#include "pch.h"
#include <vector>
#include <iostream>
#include <map>
using namespace std;
class Cube {
private:
	map<int, char> painting; //��ɸ�ӱ�ŵ���ɫ��ӳ��
	map<vector<int>, vector<int>> order; //����β��ŵ��м��ŵ�ӳ��
    string p;//�ļ���ַ
public:
	Cube() = default;
	Cube(const map<int, char> &, const map<vector<int>, vector<int>> &, const string &);
	~Cube();
	Cube(const Cube &);
	Cube(Cube &&);
	Cube & operator=(const Cube &);
	Cube & operator=(Cube &&);
	ostream & judge(ostream &);
};
#endif // !CUBE_H
