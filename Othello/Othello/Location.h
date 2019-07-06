#ifndef LOCATION_H
#define LOCATION_H
#include "pch.h"
#include <string>
#include <vector>
using namespace std;
template <typename T>
class Location {
public:
	string name; //地点名称
	T level; //位置等级
	Location() = default;
	Location(const string &, const T &);
	~Location();
	Location(const Location &);
	Location(Location &&);
	Location & operator=(const Location &);
	Location & operator=(Location &&);
};
template <typename T>
Location<T>::Location(const string &names, const T &levels) :
	name(names), level(levels) {}
template <typename T>
Location<T>::~Location() {}
template <typename T>
Location<T>::Location(const Location &l) {
	this->name = l.name;
	this->level = l.level;
}
template <typename T>
Location<T>::Location(Location &&l) {
	this->name = l.name;
	this->level = l.level;
	l.name.clear();
	l.level = 0;
}
template <typename T>
Location<T> & Location<T>::operator=(const Location &l) {
	this->name = l.name;
	this->level = l.level;
	return *this;
}
template <typename T>
Location<T> & Location<T>::operator=(Location &&l) {
	this->name = l.name;
	this->level = l.level;
	l.name.clear();
	l.level = 0;
	return *this;
}
#endif // !LOCATION_H

