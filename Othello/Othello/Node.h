#ifndef NODE_H
#define NODE_H
#include "pch.h"
#include <string>
using namespace std;
class Node {
private:
	int num; //�洢������
	string note; //�ýڵ�����λ��
public:
	Node() = default;
	Node(const int &, const string &);
	~Node();
	Node(const Node &);
	Node(Node &&);
	Node & operator=(const Node &);
	Node & operator=(Node &&);
	int num_return(); //����num����
	string note_return(); //����note����
};
#endif // !NODE_H
