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

typedef ft::avlTree< ft::pair< int, std::string > > avl;

int main( void )
{
	{
		ft::map< int, std::string > test;
		ft::map< int, std::string >::iterator b;

		test.insert(ft::make_pair(50, "Bob"));
		test.insert(ft::make_pair(40, "Iel"));
		test.insert(ft::make_pair(60, "Coco"));
		test.insert(ft::make_pair(3, "Alice"));
		test.insert(ft::make_pair(45, "Xor"));
		test.insert(ft::make_pair(65, "Coco"));
		test.insert(ft::make_pair(70, "Coco"));
		test.insert(ft::make_pair(2, "Coco"));
		test.insert(ft::make_pair(5, "Coco"));

		b = test.end();
		--b;
		std::cout << b->first << std::endl;
		--b;
		std::cout << b->first << std::endl;
		--b;
		std::cout << b->first << std::endl;
		--b;
		std::cout << b->first << std::endl;
		--b;
		std::cout << b->first << std::endl;
		--b;
		std::cout << b->first << std::endl;
		--b;
		std::cout << b->first << std::endl;
		--b;
		std::cout << b->first << std::endl;
		--b;
		std::cout << b->first << std::endl;
		--b;
		// test.print();

		// *b = ft::make_pair(50, "Ok");
	}
	return 0;
}