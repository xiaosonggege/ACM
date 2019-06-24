#ifndef OTHELLO_H
#define OTHELLO_H
#include "pch.h"
#include <vector>
#include <iostream>
#include <map>
using namespace std;
class OthellO {
private:
	vector<vector<char>> qipan;
	map<char, vector<int>> choice;
public:
	OthellO() = default;
	OthellO(const vector<vector<char>> &, const map<char, vector<int>> &);
	~OthellO();
	OthellO(const OthellO &);
	OthellO(OthellO &&);
	OthellO & operator=(const OthellO &);
	OthellO & operator=(OthellO &&);
	ostream & operator()(ostream &) const;
	int row(const vector<int> &);
	int vertial(const vector<int> &);
	int leftfollowing(const vector<int> &);
	int rightfollowing(const vector<int> &);
	int set(const vector<int> &);
};
#endif // !OTHELLO_H
