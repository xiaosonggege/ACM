#ifndef OPERATORHOME_H
#define OPERATORHOME_H
#include "pch.h"
using namespace std;
class Operatorhome {
private:
	int num; //�����ұ��
	int spare_time; //�����ҿ���ʱ���
	int prepare_time; //������׼��ʱ��
public:
	Operatorhome() = default;
	Operatorhome(const int &, int &, const int &);
	~Operatorhome();
	Operatorhome(const Operatorhome &);
	Operatorhome(Operatorhome &&);
	Operatorhome & operator=(const Operatorhome &);
	Operatorhome & operator=(Operatorhome &&);
	int num_op(); //����num����ֵ
	int spare_time_op(const int &); //�޸Ĳ�����spare_time����ֵ
	int prepare_time_op(); //����prepare_time����ֵ
};
#endif // !OPERATORHOME_H

