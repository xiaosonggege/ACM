#include "pch.h"
#include "OthellO.h"
#include <vector>
#include <iostream>
#include <map>
using namespace std;
OthellO::OthellO(const vector<vector<char>> &qipans, const map<char, vector<int>> &choices) :
	qipan(qipans), choice(choices) {}
OthellO::~OthellO() {}
OthellO::OthellO(const OthellO &o) {
	this->qipan = o.qipan;
	this->choice = o.choice;
}
OthellO::OthellO(OthellO &&o) {
	this->qipan = o.qipan;
	this->choice = o.choice;
	o.qipan.clear();
	o.choice.clear();
}
OthellO & OthellO::operator=(const OthellO &o) {
	this->qipan = o.qipan;
	this->choice = o.choice;
	return *this;
}
OthellO & OthellO::operator=(OthellO &&o) {
	this->qipan = o.qipan;
	this->choice = o.choice;
	o.qipan.clear();
	o.choice.clear();
	return *this;
}
ostream & OthellO::operator()(ostream &os) const {
	os << "����:" << endl;
	for (const auto &r : qipan) {
		for (const auto &v : r)
			os << v << " ";
		os << endl;
	}
	return os;
}
int OthellO::row(const vector<int> &pos) {//�������ұ�������
	//����������Ӹõ�����һ���㿪ʼ
	if (pos[1] != 0)
		for (int j = *(pos.end() - 1) - 1; j >= 0; --j) {
			if (qipan[*pos.begin()][j] == ' ') break;
			if (qipan[*pos.begin()][j] != qipan[*pos.begin()][*(pos.end() - 1)])
				qipan[*pos.begin()][j] = qipan[*pos.begin()][*(pos.end() - 1)];
			else break;
		}
	//���ұ������Ӹõ��Ҳ��һ���㿪ʼ
	if (pos[1] != qipan[0].size()-1)
		for (int j = *(pos.end() - 1) + 1; j != qipan[0].size(); ++j) {
			if (qipan[*pos.begin()][j] == ' ') break;
			if (qipan[*pos.begin()][j] != qipan[*pos.begin()][*(pos.end() - 1)])
				qipan[*pos.begin()][j] = qipan[*pos.begin()][*(pos.end() - 1)];
			else break;
		}
	return 0;
}
int OthellO::vertial(const vector<int> &pos) {//�������±�������
	//���ϱ������Ӹõ������һ���㿪ʼ
	if (pos[0] != 0)
		for (int i = pos[0] - 1; i >= 0; --i) {
			if (qipan[i][pos[1]] == ' ') break;
			if (qipan[i][pos[1]] != qipan[pos[0]][pos[1]])
				qipan[i][pos[1]] = qipan[pos[0]][pos[1]];
			else break;
		}
	//���±������Ӹõ������һ���㿪ʼ
	if (pos[0] != qipan[0].size()-1)
		for (int i = pos[0] + 1; i != qipan[0].size(); ++i) {
			if (qipan[i][pos[1]] == ' ') break;
			if (qipan[i][pos[1]] != qipan[pos[0]][pos[1]])
				qipan[i][pos[1]] = qipan[pos[0]][pos[1]];
			else break;
		}
	return 0;
}
int OthellO::leftfollowing(const vector<int> &pos) {//��б���²���
	//�����ϱ������Ӹõ����ϵ�һ���㿪ʼ
	if (pos[0] != 0 && pos[1] != qipan[0].size()-1)
		for (int i = pos[0]-1, j = pos[1] + 1; i >= 0 && j != qipan[0].size(); --i, ++j){
			if (qipan[i][j] == ' ') break;
			if (qipan[i][j] != qipan[pos[0]][pos[1]])
				qipan[i][j] = qipan[pos[0]][pos[1]];
			else break;
		}
	//�����±������Ӹõ����µ�һ���㿪ʼ
	if (pos[0] != qipan[0].size()-1 && pos[1] != 0)
		for (int i = pos[0] + 1, j = pos[1] - 1; i != qipan[0].size(), j >= 0; ++i, --j){
			if (qipan[i][j] == ' ') break;
			if (qipan[i][j] != qipan[pos[0]][pos[1]])
				qipan[i][j] = qipan[pos[0]][pos[1]];
			else break;
		}
	return 0;
}
int OthellO::rightfollowing(const vector<int> &pos) {//��б���²���
	//�����ϱ������Ӹõ����ϵ�һ���㿪ʼ
	if (pos[0] != 0 && pos[1] != 0)
		for (int i = pos[0] - 1, j = pos[1] - 1; i >= 0, j >= 0; --i, ++j) {
			if (qipan[i][j] == ' ') break;
			if (qipan[i][j] != qipan[pos[0]][pos[1]])
				qipan[i][j] = qipan[pos[0]][pos[1]];
			else break;
		}
	//�����±������Ӹõ����µ�һ���㿪ʼ
	if (pos[0] != qipan[0].size() - 1 && pos[1] != qipan[0].size() - 1)
		for (int i = pos[0] + 1, j = pos[1] + 1; i != qipan[0].size(), j != qipan[0].size(); ++i, ++j) {
			if (qipan[i][j] == ' ') break;
			if (qipan[i][j] != qipan[pos[0]][pos[1]])
				qipan[i][j] = qipan[pos[0]][pos[1]];
			else break;
		}
	return 0;
}
int OthellO::set(const vector<int> &pos) {//���������������������и���λ��
	qipan[pos[0]][pos[1]] = 'w';
	this->row(pos);
	this->vertial(pos);
	this->leftfollowing(pos);
	this->rightfollowing(pos);
	return 0;
}