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
	const string &p = ""; //文件路径 不可复制
	vector<Urban<double>> v_urban; //城市中建筑群列表
	vector<double> qujian; //去重复后的x坐标区间
	vector<int> number; //主视图可视的建筑编号
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

