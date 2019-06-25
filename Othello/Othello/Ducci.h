#ifndef DUCCI_H
#define DUCCI_H
#include "pch.h"
#include <vector>
#include <tuple>
using namespace std;
class Ducci {
private:
	vector<int> sequence;
	bool is_becoming_zero = 0;
public:
	Ducci() = default;
	Ducci(const vector<int> &);
	~Ducci();
	Ducci(const Ducci &);
	Ducci(Ducci &&);
	Ducci & operator=(const Ducci &);
	Ducci & operator= (Ducci &&);
	int judge(vector<int> &, vector<vector<int>> &); //�ݹ��жϣ����������ֱ�ӽ�is_becoming_zero��1�󷵻�
	tuple<vector<int>, bool> print() const;
};
#endif // !DUCCI_H

