#ifndef UNIXLS
#define UNIXLS
#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Unixls {
private:
	string p;
public:
	Unixls() = default;
	Unixls(const string &);
	Unixls(const Unixls &);
	Unixls(Unixls &&);
	~Unixls();
	Unixls & operator=(const Unixls &);
	Unixls & operator=(Unixls &&);
	ostream & output(ostream &);
};
#endif // !UNIXLS

