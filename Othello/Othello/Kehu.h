#ifndef KEHU_H
#define KEHU_H
#include "pch.h"
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;
template <typename T>
class Kehu {
public:
	T pid; //用户唯一标识符
	T k; //用户可以处理的主题请求种类
	vector<T> tids; //主题请求按优先级从大到小排列
	int next_sparetime = 0; //标记用户下次空闲时间
	int last_sparetime = 0; //标记用户执行的上一任务所需时间

	Kehu() = default;
	Kehu(const string &); //读入字符串
	~Kehu();
	Kehu(const Kehu &);
	Kehu(Kehu &&);
	Kehu & operator=(const Kehu &);
	Kehu & operator=(Kehu &&);
	int change_next(const int &, const int &); //用户计算用户下次空闲时间，第一个参数为此时时间，第二个参数为执行当前任务所需时间
	int change_next_sparetime(const int &); //用于修改该客户下一空闲时刻值
};
template <typename T>
Kehu<T>::Kehu(const string &str) {
	istringstream istr(str);
	istr >> this->pid >> this->k;
	istream_iterator<int> in_iter(istr), eof;
	this->tids.assign(in_iter, eof);
}
template <typename T>
Kehu<T>::~Kehu() {}
template <typename T>
Kehu<T>::Kehu(const Kehu &ke) {
	this->pid = ke.pid;
	this->k = ke.k;
	this->tids = ke.tids;
	this->next_sparetime = ke.next_sparetime;
	this->last_sparetime = ke.last_sparetime;
}
template <typename T>
Kehu<T>::Kehu(Kehu &&ke) {
	this->pid = ke.pid;
	this->k = ke.k;
	this->tids = ke.tids;
	this->next_sparetime = ke.next_sparetime;
	this->last_sparetime = ke.last_sparetime;
	ke.pid = 0;
	ke.k = 0;
	ke.tids.clear();
	ke.next_sparetime = 0;
	ke.last_sparetime = 0;
}
template <typename T>
Kehu<T> & Kehu<T>::operator=(const Kehu &ke) {
	this->pid = ke.pid;
	this->k = ke.k;
	this->tids = ke.tids;
	this->next_sparetime = ke.next_sparetime;
	this->last_sparetime = ke.last_sparetime;
	return *this;
}
template <typename T>
Kehu<T> & Kehu<T>::operator=(Kehu &&ke) {
	this->pid = ke.pid;
	this->k = ke.k;
	this->tids = ke.tids;
	this->next_sparetime = ke.next_sparetime;
	this->last_sparetime = ke.last_sparetime;
	ke.pid = 0;
	ke.k = 0;
	ke.tids.clear();
	ke.next_sparetime = 0;
	ke.last_sparetime = 0;
	return *this;
}
template <typename T>
int Kehu<T>::change_next(const int &time, const int &flag) {
	if (flag) this->next_sparetime = time + this->last_sparetime;
	else this->next_sparetime = time + 1;
	return 0;
}
template <typename T>
int Kehu<T>::change_next_sparetime(const int &t) {
	this->last_sparetime = t;
	return 0;
}
#endif // !KEHU_H

