#include "pch.h"
//#include "OthellO.h"
//#include "Cube.h"
//#include "Flooded.h"
//#include "Unixls.h"
//#include "Database.h"
//#include "Urban.h"
//#include "Visual.h"
#include "Ducci.h"
#include <iostream>
#include <memory>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iterator>
#include <omp.h>
#include <utility>
#include <tuple>
using namespace std;
int main()
{
	//shared_ptr<string> p = make_shared<string>("C:\\Users\\xiaosong\\Desktop\\text.txt");
	vector<int> v = { 8, 1, 1, 2, 7 };
	vector<vector<int>> v1;
	shared_ptr<Ducci> d = make_shared<Ducci>(v);
	tuple<vector<int>, bool> tup = d->print();
	d->judge(get<0>(tup), v1);
	tup = d->print();
	cout << get<1>(tup) << endl;
	return 0;
}

