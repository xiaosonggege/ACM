#ifndef TOPIC_H
#define TOPIC_H
#include "pch.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Topic {
public:
	int tid; //�����Ψһ��ʶ��
	int  num; //������������
	int t0; //��һ������ʱ��
	int t; //����һ�������ʱ��
	int dt; //�������������ļ��
	int count = 0; //�ѽ�����������ļ�����
	int next_time = 0; //��������һ������ʱ��
	Topic() = default;
	Topic(const string &); //�����ַ��������ַ����н�������������
	~Topic();
	Topic(const Topic &);
	Topic(Topic &&);
	Topic & operator=(const Topic &);
	Topic & operator=(Topic &&);
	int change(int); //��ʾcount������,����Ϊ��ʱ�̵�ʱ�� 
};
#endif // !TOPIC_H

