#ifndef DATABASE_H
#define DATABASE_H
#include "pch.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
class Database {
private:
	string p;
public:
	Database() = default;
	Database(const string &);
	~Database();
	Database(const Database &);
	Database(Database &&);
	Database & operator=(const Database &);
	Database & operator=(Database &&);
	vector<int> judge(const vector<string> &, const vector<string> &) const;
	ostream & print(ostream &, const vector<vector<string>> &) const;
	ostream & operator()(ostream &) const;
	static int show();
};
#endif // !DATABASE_H

