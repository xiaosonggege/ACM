#ifndef RECOVERHOME_H
#define RECOVERHOME_H
#include "pch.h"
#include <string>
using namespace std;
class Recoverhome {
private:
	int num; //�ָ��ұ��
	int spare_time; //�ָ��ҿ���ʱ���
	int prepare_time; //�ָ���׼��ʱ��
public:
	Recoverhome() = default;
	Recoverhome(const int &, int &, const int &);
	~Recoverhome();
	Recoverhome(const Recoverhome &);
	Recoverhome(Recoverhome &&);
	Recoverhome & operator=(const Recoverhome &);
	Recoverhome & operator=(Recoverhome &&);
	int num_op(); //����num����ֵ
	int spare_time_op(const int &); //�޸Ĳ�����spare_time����ֵ
	int prepare_time_op(); //����prepare_time����ֵ
};
#endif // !RECOVERHOME_H

