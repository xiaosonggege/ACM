#ifndef NODE_H
#define NODE_H
#include "pch.h"
#include <string>
using namespace std;
class Node {
private:
	int num; //存储的数字
	string note; //该节点所处位置
public:
	Node() = default;
	Node(const int &, const string &);
	~Node();
	Node(const Node &);
	Node(Node &&);
	Node & operator=(const Node &);
	Node & operator=(Node &&);
	int num_return(); //返回num属性
	string note_return(); //返回note属性
};
#endif // !NODE_H
