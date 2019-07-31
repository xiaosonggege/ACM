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
	string p; //文件路径
	vector<Node> v_n; //节点向量
public:
	TreeLeveling() = default;
	TreeLeveling(const string &);
	~TreeLeveling();
	TreeLeveling(const TreeLeveling &);
	TreeLeveling(TreeLeveling &&);
	TreeLeveling & operator=(const TreeLeveling &);
	TreeLeveling & operator=(TreeLeveling &&);
	ostream & print(ostream &);
	static bool compare(const Node &, const Node &); //比较函数
};
#endif // !TREELEVELING_H

