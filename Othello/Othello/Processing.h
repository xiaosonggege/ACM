#ifndef PROCESSING_H
#define PROCESSING_H
#include "pch.h"
#include "Kehu.h"
#include "Topic.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;
class Processing {
private:
	vector<Topic> v_topic; //主题序列
	vector<Kehu<int>> v_kehu; //用户序列
	vector<int> wait_rank; //主题等待队列
	map<int, vector<Kehu<int>>> topic_kehu; //待处理主题到可处理该主题的用户列表的散列
public:
	Processing() = default;
	Processing(const string &); //参数为文件绝对路径
	~Processing();
	Processing(const Processing &);
	Processing(Processing &&);
	Processing & operator=(const Processing &);
	Processing & operator=(Processing &&);
	ostream & chuli(ostream &);
	bool is_finishing();
	static bool comparing(const Kehu<int> &, const Kehu<int> &);
	
};
#endif // !PROCESSING_H
