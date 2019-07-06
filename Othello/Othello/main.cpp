#include "pch.h"
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
#include "Map.h"
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
	shared_ptr<string> p = make_shared<string>("C:\\Users\\xiaosong\\Desktop\\text.txt");
	shared_ptr<Map> m = make_shared<Map>(*p);
	m->finding(cout);
	return 0;
}

