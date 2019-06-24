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
	os << "棋盘:" << endl;
	for (const auto &r : qipan) {
		for (const auto &v : r)
			os << v << " ";
		os << endl;
	}
	return os;
}
int OthellO::row(const vector<int> &pos) {//横向左右遍历操作
	//向左遍历，从该点左侧第一个点开始
	if (pos[1] != 0)
		for (int j = *(pos.end() - 1) - 1; j >= 0; --j) {
			if (qipan[*pos.begin()][j] == ' ') break;
			if (qipan[*pos.begin()][j] != qipan[*pos.begin()][*(pos.end() - 1)])
				qipan[*pos.begin()][j] = qipan[*pos.begin()][*(pos.end() - 1)];
			else break;
		}
	//向右遍历，从该点右侧第一个点开始
	if (pos[1] != qipan[0].size()-1)
		for (int j = *(pos.end() - 1) + 1; j != qipan[0].size(); ++j) {
			if (qipan[*pos.begin()][j] == ' ') break;
			if (qipan[*pos.begin()][j] != qipan[*pos.begin()][*(pos.end() - 1)])
				qipan[*pos.begin()][j] = qipan[*pos.begin()][*(pos.end() - 1)];
			else break;
		}
	return 0;
}
int OthellO::vertial(const vector<int> &pos) {//纵向上下遍历操作
	//向上遍历，从该点上面第一个点开始
	if (pos[0] != 0)
		for (int i = pos[0] - 1; i >= 0; --i) {
			if (qipan[i][pos[1]] == ' ') break;
			if (qipan[i][pos[1]] != qipan[pos[0]][pos[1]])
				qipan[i][pos[1]] = qipan[pos[0]][pos[1]];
			else break;
		}
	//向下遍历，从该点下面第一个点开始
	if (pos[0] != qipan[0].size()-1)
		for (int i = pos[0] + 1; i != qipan[0].size(); ++i) {
			if (qipan[i][pos[1]] == ' ') break;
			if (qipan[i][pos[1]] != qipan[pos[0]][pos[1]])
				qipan[i][pos[1]] = qipan[pos[0]][pos[1]];
			else break;
		}
	return 0;
}
int OthellO::leftfollowing(const vector<int> &pos) {//左斜上下操作
	//向右上遍历，从该点左上第一个点开始
	if (pos[0] != 0 && pos[1] != qipan[0].size()-1)
		for (int i = pos[0]-1, j = pos[1] + 1; i >= 0 && j != qipan[0].size(); --i, ++j){
			if (qipan[i][j] == ' ') break;
			if (qipan[i][j] != qipan[pos[0]][pos[1]])
				qipan[i][j] = qipan[pos[0]][pos[1]];
			else break;
		}
	//向左下遍历，从该点左下第一个点开始
	if (pos[0] != qipan[0].size()-1 && pos[1] != 0)
		for (int i = pos[0] + 1, j = pos[1] - 1; i != qipan[0].size(), j >= 0; ++i, --j){
			if (qipan[i][j] == ' ') break;
			if (qipan[i][j] != qipan[pos[0]][pos[1]])
				qipan[i][j] = qipan[pos[0]][pos[1]];
			else break;
		}
	return 0;
}
int OthellO::rightfollowing(const vector<int> &pos) {//右斜上下操作
	//向左上遍历，从该点左上第一个点开始
	if (pos[0] != 0 && pos[1] != 0)
		for (int i = pos[0] - 1, j = pos[1] - 1; i >= 0, j >= 0; --i, ++j) {
			if (qipan[i][j] == ' ') break;
			if (qipan[i][j] != qipan[pos[0]][pos[1]])
				qipan[i][j] = qipan[pos[0]][pos[1]];
			else break;
		}
	//向右下遍历，从该点左下第一个点开始
	if (pos[0] != qipan[0].size() - 1 && pos[1] != qipan[0].size() - 1)
		for (int i = pos[0] + 1, j = pos[1] + 1; i != qipan[0].size(), j != qipan[0].size(); ++i, ++j) {
			if (qipan[i][j] == ' ') break;
			if (qipan[i][j] != qipan[pos[0]][pos[1]])
				qipan[i][j] = qipan[pos[0]][pos[1]];
			else break;
		}
	return 0;
}
int OthellO::set(const vector<int> &pos) {//根据输入点坐标更新棋盘中各点位置
	qipan[pos[0]][pos[1]] = 'w';
	this->row(pos);
	this->vertial(pos);
	this->leftfollowing(pos);
	this->rightfollowing(pos);
	return 0;
}