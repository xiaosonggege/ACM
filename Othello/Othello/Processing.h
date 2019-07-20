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
	vector<Topic> v_topic; //��������
	vector<Kehu<int>> v_kehu; //�û�����
	vector<int> wait_rank; //����ȴ�����
	map<int, vector<Kehu<int>>> topic_kehu; //���������⵽�ɴ����������û��б��ɢ��
public:
	Processing() = default;
	Processing(const string &); //����Ϊ�ļ�����·��
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
