#ifndef URBAN_H
#define URBAN_H
#include "pch.h"
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
template <typename T>
class Urban {
private:
	const string &str = ""; //�ļ��д洢������Ϣ���ַ��� ���ɿ����͸�ֵ
public:
	int num; //�������
	T x; //����x����
	T y; //����y����
	T weigh; //�������
	T deep; //�������
	T high; //�����߶�
	Urban() = default;
	~Urban();
	Urban(const string &, const int &);
	Urban(const Urban &);
	Urban(Urban &&);
	Urban & operator=(const Urban &);
	Urban & operator=(Urban &&);
	ostream & print(ostream &);
};
template <typename T>
Urban<T>::Urban(const string &strs, const int &nums) : str(strs), num(nums) {
	istringstream istrm(this->str, ios::in);
	istrm >> this->x >> this->y >> this->weigh >> this->deep >> this->high;
}
template <typename T>
Urban<T>::~Urban() {}
template <typename T>
Urban<T>::Urban(const Urban &u) {
	this->num = u.num;
	this->x = u.x;
	this->y = u.y;
	this->weigh = u.weigh;
	this->deep = u.deep;
	this->high = u.high;
}
template <typename T>
Urban<T>::Urban(Urban &&u) {
	this->num = u.num;
	this->x = u.x;
	this->y = u.y;
	this->weigh = u.weigh;
	this->deep = u.deep;
	this->high = u.high;
	u.num = 0, u.x = 0, u.y = 0, u.weigh = 0, u.deep = 0, u.high = 0;
}
template <typename T>
Urban<T> & Urban<T>::operator=(const Urban &u) {
	this->num = u.num;
	this->x = u.x;
	this->y = u.y;
	this->weigh = u.weigh;
	this->deep = u.deep;
	this->high = u.high;
	return *this;
}
template <typename T>
Urban<T> & Urban<T>::operator=(Urban &&u) {
	this->num = u.num;
	this->x = u.x;
	this->y = u.y;
	this->weigh = u.weigh;
	this->deep = u.deep;
	this->high = u.high;
	u.num = 0, u.x = 0, u.y = 0, u.weigh = 0, u.deep = 0, u.high = 0;
	return *this;
}
template <typename T>
ostream & Urban<T>::print(ostream &os) {
	os << "�������Ϊ: " << this->num << endl;
	os << "����������Ϊ: (" << this->x << ", " << this->y << ")" << endl;
	os << "�����Ŀ�ȸ߶���ȷֱ�Ϊ: " << this->weigh << " " << this->deep << " " << this->high << endl;
	return os;
}
#endif // !URBAN_H

