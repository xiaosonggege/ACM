#ifndef MAP_H
#define MAP_H
#include "pch.h"
#include "Map.h"
#include "Location.h"
#include "Comparing.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;
class Map {
private:
	const string &p = ""; //文件路径不可复制和移动
	vector<pair<string, vector<double>>> mm; //地图序列，包含左下和右上角端点坐标
	map<string, vector<double>> loc; //地点关联序列，包含位置坐标
	vector<Location<int>> lv; //待查询序列
public:
	Map() = default;
	Map(const string &);
	~Map();
	Map(const Map &);
	Map(Map &&);
	Map & operator=(const Map &);
	Map & operator=(Map &&);
	ostream & finding(ostream &); //对文件中所有待查询地点找到对应等级地图
};
#endif // !MAP_H

