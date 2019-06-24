#ifndef FLOODED_H
#define FLOODED_H
#include "pch.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
using namespace std;
template <typename T>
class Flooded {
private:
	vector<typename vector<T>> surround;
	vector<T> tall;
	T volumn;
	T high_max = 0;
	double percent = 0;
public:
	Flooded() = default;
	Flooded(const vector<typename vector<T>> &, const T &);
	~Flooded();
	Flooded(const Flooded<T> &);
	Flooded(Flooded<T> &&);
	Flooded<T> & operator=(const Flooded<T> &);
	Flooded<T> & operator=(Flooded<T> &&);
	int contribute(T &v_total, vector<typename vector<T>> &);
	T highmax();
	double perc() const;
	int fun(const T &, vector<T> &);
};
template <typename T>
Flooded<T>::Flooded(const vector<typename vector<T>> &surrounds, const T &volumns) :
	surround(surrounds), volumn(volumns) {}
template <typename T>
Flooded<T>::~Flooded() {}
template <typename T>
Flooded<T>::Flooded(const Flooded<T> &f) {
	this->surround = f.surround;
	this->tall = f.tall;
	this->volumn = f.volumn;
	this->high_max = f.high_max;
	this->percent = f.percent;
}
template <typename T>
Flooded<T>::Flooded(Flooded<T> &&f) {
	this->surround = f.surround;
	this->tall = f.tall;
	this->volumn = f.volumn;
	this->high_max = f.high_max;
	this->percent = f.percent;
	f.surround.clear();
	f.tall.clear();
	f.volumn = 0;
	f.high_max = 0;
	f.percent = 0;
}
template <typename T>
Flooded<T> & Flooded<T>::operator=(const Flooded<T> &f) {
	this->surround = f.surround;
	this->tall = f.tall;
	this->volumn = f.volumn;
	this->high_max = f.high_max;
	this->percent = f.percent;
	return *this;
}
template <typename T>
Flooded<T> & Flooded<T>::operator=(Flooded<T> &&f) {
	this->surround = f.surround;
	this->tall = f.tall;
	this->volumn = f.volumn;
	this->high_max = f.high_max;
	this->percent = f.percent;
	f.surround.clear();
	f.tall.clear();
	f.volumn = 0;
	f.high_max = 0;
	f.percent = 0;
	return *this;
}
template <typename T>
int Flooded<T>::contribute(T &v_total, vector<typename vector<T>> &surround_real) {
	T tall_min = 100;
	//找到所有格子中隔板高度的最小值替换tall_min
	for (auto iter_s = surround_real.begin(); iter_s != surround_real.end(); ) {
		typename vector<T>::const_iterator iter = min_element(iter_s->cbegin(), iter_s->cend());
		if (*iter < tall_min)
			if (*iter == 0) iter_s = surround_real.erase(iter_s);
			else {
				tall_min = *iter;
				++iter_s;
			}
		else ++iter_s;
	}
	this->high_max += tall_min;
	T v_total_real = tall_min * 1 * 1 * (surround_real.size());
	if (v_total_real <= v_total) {
		v_total -= v_total_real;
		//所有墙壁高度都减去当前最小高度
		for (auto iter = surround_real.begin(); iter != surround_real.end(); ++iter)
			fun(tall_min, *iter);
		this->contribute(v_total, surround_real);
	}
	else {
		this->high_max -= tall_min;
		tall_min = v_total / (surround_real.size() * 1 * 1);
		for (auto iter = surround_real.begin(); iter != surround_real.end(); ++iter)
			fun(tall_min, *iter);
		this->high_max += tall_min;
	}
	return 0;
}
template <typename T>
T Flooded<T>::highmax() {
	this->contribute(this->volumn, this->surround);
	return this->high_max;
}
template <typename T>
double Flooded<T>::perc() const {
	double total = 0;
	for (const auto &e : this->tall) {
		if (e != 0) ++total;
	}
	return (total / this->tall.size());
}
template <typename T>
int Flooded<T>::fun(const T &h, vector<T> &v) {
	for (auto iter = v.begin(); iter != v.end(); ++iter) *iter -= h;
	return 0;
}
#endif // !FLOODED_H

