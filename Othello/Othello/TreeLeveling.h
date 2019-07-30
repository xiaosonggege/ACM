#ifndef TREELEVELING_H
#define TREELEVELING_H
#include "pch.h"
#include "Node.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class TreeLeveling {
private:
	string p; //�ļ�·��
	vector<Node> v_n; //�ڵ�����
public:
	TreeLeveling() = default;
	TreeLeveling(const string &);
	~TreeLeveling();
	TreeLeveling(const TreeLeveling &);
	TreeLeveling(TreeLeveling &&);
	TreeLeveling & operator=(const TreeLeveling &);
	TreeLeveling & operator=(TreeLeveling &&);
	ostream & print(ostream &);
};
#endif // !TREELEVELING_H

