#ifndef COMPARING_H
#define COMPARING_H
#include "pch.h"
#include <string>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;
class Comparing {
private:
	vector<double> pairr;
public:
	Comparing(const vector<double> &pairrs) : pairr(pairrs) {}
	bool operator()(pair<string, vector<double>> p1, pair<string, vector<double>> p2) const {
		double p1_x1 = p1.second[0], p1_x2 = p1.second[1], p1_y1 = p1.second[2], p1_y2 = p1.second[3],
			p2_x1 = p2.second[0], p2_x2 = p2.second[1], p2_y1 = p2.second[2], p2_y2 = p2.second[3], EOP = 1e-6;
		if (abs((p1_x2 - p1_x1)*(p1_y2 - p1_y1) - (p2_x2 - p2_x1)*(p2_y2 - p2_y1)) > EOP)
			return (p1_x2 - p1_x1)*(p1_y2 - p1_y1) > (p2_x2 - p2_x1)*(p2_y2 - p2_y1);
		else {
			//计算p1和p2中点
			double mid1_x = (p1_x1 + p1_x2) / 2, mid1_y = (p1_y1 + p1_y2) / 2, mid2_x = (p2_x1 + p2_x2) / 2, mid2_y = (p2_y1 + p2_y2) / 2;
			//判断离目标位置最近的中点
			double dis1 = sqrt(pow(mid1_x - pairr[0], 2) + pow(mid1_y - pairr[1], 2)),
				dis2 = sqrt(pow(mid2_x - pairr[0], 2) + pow(mid2_y - pairr[1], 2));
			if (abs(dis1 - dis2) > EOP) return dis1 < dis2;
			else {
				if (abs(abs((p1_y2 - p1_y1) / (p1_x2 - p1_x1) - 0.75) - abs((p2_y2 - p2_y1) / (p2_x2 - p2_x1) - 0.75)) > EOP)
					return abs((p1_y2 - p1_y1) / (p1_x2 - p1_x1) - 0.75) < abs((p2_y2 - p2_y1) / (p2_x2 - p2_x1) - 0.75);
				else
				{
					//计算地图右下角坐标和目标位置距离
					double dis1_r = sqrt(pow(p1_x2 - pairr[0], 2) + pow(p1_y1 - pairr[1], 2)),
						dis2_r = sqrt(pow(p2_x2 - pairr[0], 2) + pow(p2_y1 - pairr[1], 2));
					if (abs(dis1_r - dis2_r) > EOP) return dis1_r > dis2_r;
					else
					{
						return p1_x2 < p2_x2;
					}
				}
			}
		}
	}
};
#endif // !COMPARING_H

