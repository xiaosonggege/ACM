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
#include <cmath>
#include <algorithm>
#include <memory>
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
			if (e.next_time == time)
				wait_rank.push_back(e.tid);
		}
		//�ҵ��˿̿��е��û�,�����ݿ����û������������ȼ��б���´�����ɢ�б�
		for (auto &e2 : this->v_kehu) {
			if (e2.next_sparetime <= time) {
				//�����û�ִ����������ȼ���������ȴ��������ҵ��˿��û����Դ�������⣬����ɢ��
				for (auto iter = e2.tids.begin(); iter != e2.tids.end(); ++iter) {
					if (find(wait_rank.begin(), wait_rank.end(), *iter) != wait_rank.end()) {
						pair<map<int, vector<Kehu<int>>>::iterator, bool> pairr = topic_kehu.insert({*iter , {e2} });
						if (!pairr.second) pairr.first->second.push_back(e2);
						//flag_finish = 1;
						break;
					}
				}
			}
		}
		//����ɢ�У����Ȱ��������Ӧ��ǰ�����û���
		for (auto iter = topic_kehu.begin(); iter != topic_kehu.end(); ) {
			//���տͻ�����������������
			sort(iter->second.begin(), iter->second.end(), &comparing);
			//��ÿ���ִ�д�����Ŀͻ�id������id
			int k_pid = iter->second.begin()->pid;
			int t_tid = iter->first;
			auto is_topic = [&](const Topic &t)->bool {return t.tid == t_tid; };
			auto is_kehu = [&](const Kehu<int> &k)->bool {return k.pid == k_pid; };
			vector<Topic>::iterator tt = find_if(v_topic.begin(), v_topic.end(), is_topic);
			vector<Kehu<int>>::iterator kk = find_if(v_kehu.begin(), v_kehu.end(), is_kehu);
			//�ı�tt������λ�õ������count��next_time����
			tt->change(time);
			//�ı�kk������λ�õ��û���
			kk->change_next_sparetime(tt->t);
			kk->change_next(time, 1);
			//�����д���õ����������˳��ȴ����к�ɢ�б�
			auto t_tid_pos = find(wait_rank.begin(), wait_rank.end(), t_tid);
			this->wait_rank.erase(t_tid_pos);
			iter = this->topic_kehu.erase(iter);
		}
		++time;
		//os << time << endl;
	}
	os << "ִ�������������󹲻���ʱ��Ϊ: " << time << endl;
	return os;
}
bool Processing::is_finishing() {
	for (auto iter = v_topic.cbegin(); iter != v_topic.cend(); ++iter)
		if (iter->count != iter->num) return 1;
	return 0;
}
bool Processing::comparing(const Kehu<int> &k1, const Kehu<int> &k2) {
	if (abs(k1.last_sparetime - k2.last_sparetime) > 1e-6)
		return k1.last_sparetime > k2.last_sparetime;
	else return k1.pid < k2.pid;
}
