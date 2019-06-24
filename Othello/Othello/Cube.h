#ifndef CUBE_H
#define CUBE_H
#include "pch.h"
#include <vector>
#include <iostream>
#include <map>
using namespace std;
class Cube {
private:
	map<int, char> painting; //从筛子标号到颜色的映射
	map<vector<int>, vector<int>> order; //从首尾编号到中间编号的映射
    string p;//文件地址
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
