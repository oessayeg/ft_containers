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
		ft::map< int, std::string > test;
		ft::map< int, std::string >::iterator e;

		test.insert(ft::make_pair(50, "Bob"));
		test.insert(ft::make_pair(40, "Iel"));
		test.insert(ft::make_pair(60, "Coco"));
		test.insert(ft::make_pair(3, "Alice"));
		test.insert(ft::make_pair(45, "Xor"));
		test.insert(ft::make_pair(65, "Coco"));
		test.insert(ft::make_pair(70, "Nurmang"));
		test.insert(ft::make_pair(2, "Balence"));
		test.insert(ft::make_pair(5, "Vlad"));

		ft::map< int, std::string > test2(test.begin(), test.end());

		// ft::map< int, std::string >::iterator b = test2.begin();
		// for (; b != test2.end(); b++)
		// 	std::cout << b->first << ", " << b->second << std::endl;
		// test.print();

		// *b = ft::make_pair(50, "Ok");
	}

	return 0;
}