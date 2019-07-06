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
	const string &p = ""; //�ļ�·�����ɸ��ƺ��ƶ�
	vector<pair<string, vector<double>>> mm; //��ͼ���У��������º����ϽǶ˵�����
	map<string, vector<double>> loc; //�ص�������У�����λ������
	vector<Location<int>> lv; //����ѯ����
public:
	Map() = default;
	Map(const string &);
	~Map();
	Map(const Map &);
	Map(Map &&);
	Map & operator=(const Map &);
	Map & operator=(Map &&);
	ostream & finding(ostream &); //���ļ������д���ѯ�ص��ҵ���Ӧ�ȼ���ͼ
};
#endif // !MAP_H

