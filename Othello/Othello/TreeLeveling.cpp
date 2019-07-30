#include "pch.h"
#include "Node.h"
#include "TreeLeveling.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
TreeLeveling::TreeLeveling(const string &ps): p(ps) {
	ifstream ifstrm;
	ifstrm.open(this->p, ios::in);

	ifstrm.close();
}
TreeLeveling::~TreeLeveling() {}
TreeLeveling::TreeLeveling(const TreeLeveling &t) {
	this->p = t.p;
	this->v_n = t.v_n;
}
TreeLeveling::TreeLeveling(TreeLeveling &&t) {
	this->p = t.p;
	this->v_n = t.v_n;
	t.p.clear();
	t.v_n.clear();
}
TreeLeveling & TreeLeveling::operator=(const TreeLeveling &t) {
	this->p = t.p;
	this->v_n = t.v_n;
	return *this;
}
TreeLeveling & TreeLeveling::operator=(TreeLeveling &&t) {
	this->p = t.p;
	this->v_n = t.v_n;
	t.p.clear();
	t.v_n.clear();
	return *this;
}
ostream & TreeLeveling::print(ostream &os) {

	return os;
}