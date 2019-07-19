#include "pch.h"
#include "Kehu.h"
#include "Topic.h"
#include "Processing.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <iterator>
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
ostream & Processing::chuli(ostream &os) {
	int time = 0; //��¼�������ŵ�ʱ��
	while (this->is_finishing()) {
		//������������������Ƿ��д���������
		for (auto &e : this->v_topic) {
			if (e.next_time == time) wait_rank.push_back(e.tid);
		}
		//�ҵ��˿̿��е��û�,�����ݿ����û������������ȼ��б���´�����ɢ�б�
		for (auto &e : this->v_kehu) {
			if (e.next_sparetime == time) {
				//�����û�ִ����������ȼ���������ȴ��������ҵ��˿��û����Դ�������⣬����ɢ��
				for (auto iter = e.tid.begin(); iter != e.tid.end(); ++iter) {
					if (find(wait_rank.begin(), wait_rank.end(), *iter) != wait_rank.end()) {
						pair<map<int, vector<Kehu<int>>>::iterator, bool> pairr = topic_kehu.insert({*iter , {e} });
						if (!pairr.second) pairr.first->second.push_back(e);
						continue;
					}
				}
			}
		}
		//����ɢ�У����Ȱ��������Ӧ��ǰ�����û���
		++time;
	}
	return os;
}
bool Processing::is_finishing() {
	for (auto iter = v_topic.cbegin(); iter != v_topic.cend(); ++iter)
		if (iter->count != iter->num) return 0;
	return 1;
}
