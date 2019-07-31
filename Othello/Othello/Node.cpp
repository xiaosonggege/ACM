#include "pch.h"
#include "Node.h"
#include <string>
using namespace std;
Node::Node(const int &nums, const string &notes) :
	num(nums), note(notes) {}
Node::~Node() {}
Node::Node(const Node &n) {
	this->num = n.num;
	this->note = n.note;
}
Node::Node(Node &&n) {
	this->num = n.num;
	this->note = n.note;
	n.num = 0;
	n.note.clear();
}
Node & Node::operator=(const Node &n) {
	this->num = n.num;
	this->note = n.note;
	return *this;
}
Node & Node::operator=(Node &&n) {
	this->num = n.num;
	this->note = n.note;
	n.num = 0;
	n.note.clear();
	return *this;
}
int Node::num_return() const {
	return this->num;
}
string Node::note_return() const {
	return this->note;
}