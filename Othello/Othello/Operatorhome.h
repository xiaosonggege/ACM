#ifndef OPERATORHOME_H
#define OPERATORHOME_H
#include "pch.h"
using namespace std;
class Operatorhome {
private:
	int num; //手术室编号
	int spare_time; //手术室空闲时间点
	int prepare_time; //手术室准备时间
public:
	Operatorhome() = default;
	Operatorhome(const int &, int &, const int &);
	~Operatorhome();
	Operatorhome(const Operatorhome &);
	Operatorhome(Operatorhome &&);
	Operatorhome & operator=(const Operatorhome &);
	Operatorhome & operator=(Operatorhome &&);
	int num_op(); //返回num属性值
	int spare_time_op(const int &); //修改并返回spare_time属性值
	int prepare_time_op(); //返回prepare_time属性值
};
#endif // !OPERATORHOME_H

