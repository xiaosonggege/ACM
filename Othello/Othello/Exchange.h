#ifndef EXCHANGE_H
#define EXCHANGE_H
#include "pch.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;
template <typename T>
class Exange {
private:
	const string &p = ""; //文件路径
	vector<T> v;
public:
	Exange() = default;
	Exange(const string &);
	~Exange();
	Exange(const Exange &);
	Exange(Exange &&);
	Exange & operator=(const Exange &);
	Exange & operator=(Exange &&);
	ostream & judge(ostream &);
};
template <typename T>
Exange<T>::Exange(const string &ps): p(ps) {
	T s;
	ifstream ifstrm;
	ifstrm.open(p, ios::in);
	while (ifstrm >> s) {
		this->v.push_back(s);
	}
	ifstrm.close();
}
template <typename T>
Exange<T>::~Exange() {}
template <typename T>
Exange<T>::Exange(const Exange &e) {
	this->v = e.v;
}
template <typename T>
Exange<T>::Exange(Exange &&e) {
	this->v = e.v;
	e.v.clear();
}
template <typename T>
Exange<T> & Exange<T>::operator=(const Exange &e) {
	this->v = e.v;
	return *this;
}
template <typename T>
Exange<T> & Exange<T>::operator=(Exange &&e) {
	this->v = e.v;
	e.v.clear();
	return *this;
}
template <typename T>
ostream & Exange<T>::judge(ostream &os) {
	sort(this->v.begin(), this->v.end());
	typename vector<T>::iterator iter = unique(this->v.begin(), this->v.end());
	if (iter == this->v.end()) os << "配对成功!";
	else os << "无法成功配对!";
	return os;
}
#endif // !EXCHANGE_H

