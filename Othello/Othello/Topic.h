#ifndef TOPIC_H
#define TOPIC_H
#include "pch.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Topic {
public:
	int tid; //主题的唯一标识符
	int  num; //主题的请求个数
	int t0; //第一个请求时刻
	int t; //处理一个请求的时间
	int dt; //相邻两个请求间的间隔
	int count = 0; //已解决请求数量的计数器
	int next_time = 0; //该主题下一请求到来时间
	Topic() = default;
	Topic(const string &); //读入字符串，从字符串中解析出所有属性
	~Topic();
	Topic(const Topic &);
	Topic(Topic &&);
	Topic & operator=(const Topic &);
	Topic & operator=(Topic &&);
	int change(int); //显示count计数器,参数为此时刻的时间 
};
#endif // !TOPIC_H

