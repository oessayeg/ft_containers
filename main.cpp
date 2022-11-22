#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "utils/tree.hpp"
#include <iterator>
#include <sys/time.h>
#include <map>
#include <cmath>
#include "map.hpp"
#include "utils/functional.hpp"
#include <utility>
#include "vector.hpp"

int main( void )
{
	{
		ft::map< int, std::string > test1;
		ft::map<int, std::string> test2;

		test1.insert(ft::make_pair(20, "Bob"));
		test1.insert(ft::make_pair(30, "Doc"));
		test1.insert(ft::make_pair(10, "Aot"));
		test2 = test1;

		// for (ft::map< int, std::string >::iterator b = test2.begin(); b != test2.end(); b++)
		// 	std::cout << b->first << ", " << b->second << std::endl;
	};

	return 0;
}