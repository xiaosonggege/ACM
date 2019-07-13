#include "pch.h"
#include "Kehu.h"
#include "Topic.h"
#include "Processing.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
using namespace std;
Processing::Processing(const string &p) {
	ifstream ifstrm;
	string s;
	ifstrm.open(p, ios::in);
	int flag1 = 0, flag2 = 0;
	while (getline(ifstrm, s)) {
		if (s == "3") {
			flag1 = 1;
			continue;
		}
		if (s == "4") {
			flag2 = 1;
			continue;
		}
		if (s == "0") break;
		if (flag1 && (!flag2)) v_topic.push_back(Topic(s));
		if (flag1 && flag2) v_kehu.push_back(Kehu<int>(s));
	}
	ifstrm.close();
}
Processing::~Processing() {}
Processing::Processing(const Processing &pro) {
	this->v_topic = pro.v_topic;
	this->v_kehu = pro.v_kehu;
	this->wait_rank = pro.wait_rank;
	this->topic_kehu = pro.topic_kehu;
}
Processing::Processing(Processing &&pro) {
	this->v_topic = pro.v_topic;
	this->v_kehu = pro.v_kehu;
	this->wait_rank = pro.wait_rank;
	this->topic_kehu = pro.topic_kehu;
	pro.v_topic.clear();
	pro.v_kehu.clear();
	pro.wait_rank.clear();
	pro.topic_kehu.clear();
}
Processing & Processing::operator=(const Processing &pro) {
	this->v_topic = pro.v_topic;
	this->v_kehu = pro.v_kehu;
	this->wait_rank = pro.wait_rank;
	this->topic_kehu = pro.topic_kehu;
	return *this;
}
Processing & Processing::operator=(Processing &&pro) {
	this->v_topic = pro.v_topic;
	this->v_kehu = pro.v_kehu;
	this->wait_rank = pro.wait_rank;
	this->topic_kehu = pro.topic_kehu;
	pro.v_topic.clear();
	pro.v_kehu.clear();
	pro.wait_rank.clear();
	pro.topic_kehu.clear();
	return *this;
}
