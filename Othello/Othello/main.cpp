﻿#include "pch.h"
//#include "OthellO.h"
//#include "Cube.h"
//#include "Flooded.h"
//#include "Unixls.h"
//#include "Database.h"
//#include "Urban.h"
//#include "Visual.h"
//#include "Ducci.h"
//#include "Exchange.h"
//#include "Location.h"
//#include "Map.h"
//#include "Topic.h"
//#include "Kehu.h"
//#include "Processing.h"
//#include "Operatorhome.h"
//#include "Recoverhome.h"
//#include "Hospital.h"
#include "Node.h"
#include "TreeLeveling.h"
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
int fun(int a, int b) {
	return a + b;
}
int main()
{
	shared_ptr<string> p = make_shared<string>("C:\\Users\\xiaosong\\Desktop\\text.txt");
	shared_ptr<TreeLeveling> t = make_shared<TreeLeveling>(*p);
	t->print(cout);
	return 0;
}

