#ifndef RECOVERHOME_H
#define RECOVERHOME_H
#include "pch.h"
#include <string>
using namespace std;
class Recoverhome {
private:
	int num; //恢复室编号
	int spare_time; //恢复室空闲时间点
	int prepare_time; //恢复室准备时间
public:
	Recoverhome() = default;
	Recoverhome(const int &, int &, const int &);
	~Recoverhome();
	Recoverhome(const Recoverhome &);
	Recoverhome(Recoverhome &&);
	Recoverhome & operator=(const Recoverhome &);
	Recoverhome & operator=(Recoverhome &&);
	int num_op(); //返回num属性值
	int spare_time_op(const int &); //修改并返回spare_time属性值
	int prepare_time_op(); //返回prepare_time属性值
};
#endif // !RECOVERHOME_H

