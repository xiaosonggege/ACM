#include "pch.h"
#include "Node.h"
#include "TreeLeveling.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;
TreeLeveling::TreeLeveling(const string &ps): p(ps) {
	ifstream ifstrm;
	ifstrm.open(this->p, ios::in);
	string s;
	while (ifstrm >> s) {
		s.erase(s.begin());
		s.erase(s.end() - 1);
		if (s.size()) {
			int i;
			string s2;
			istringstream istr(s);
			istr >> i >> s2;
			s2.erase(s2.begin());
			v_n.emplace_back(i, s2);
			cout << i << " " << s2 << endl;
		}
	}
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
	sort(this->v_n.begin(), this->v_n.end(), this->compare);
	for (vector<Node>::const_iterator iter = v_n.cbegin(); iter != v_n.cend(); ++iter)
		os << iter->num_return() << " ";
	os << endl;
	return os;
}
bool TreeLeveling::compare(const Node &n1, const Node &n2) {
	if (n1.note_return().size() != n2.note_return().size())
		return n1.note_return().size() < n2.note_return().size();
	else
	{
		for (int i = 0; i != n1.note_return().size(); ++i) {
			if (n1.note_return()[i] != n2.note_return()[i])
				return n1.note_return()[i] < n2.note_return()[i];
		}
	}
}