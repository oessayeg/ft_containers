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
		std::map< int, std::string > m1, m2;
 
		m1.insert(std::make_pair(100, "Hello1"));
		m1.insert(std::make_pair(200, "Hello1"));
		m1.insert(std::make_pair(300, "Hello1"));
		m1.insert(std::make_pair(400, "Hello1"));
		m1.insert(std::make_pair(500, "Hello1"));

        m2.insert(std::make_pair(2147483647, "zxcvzx"));
		m2.insert(std::make_pair(7, "Hello"));
		m2.insert(std::make_pair(8, "Hello"));
		m2.insert(std::make_pair(1, "Hello"));
		m2.insert(std::make_pair(0, "Hello"));
		std::cout << (m1 <= m2) << std::endl;
	}
	{
		ft::map< int, std::string > m1, m2;

		m1.insert(ft::make_pair(100, "Hello1"));
		m1.insert(ft::make_pair(200, "Hello1"));
		m1.insert(ft::make_pair(300, "Hello1"));
		m1.insert(ft::make_pair(400, "Hello1"));
		m1.insert(ft::make_pair(500, "Hello1"));

        m2.insert(ft::make_pair(2147483647, "zxcvzx"));
		m2.insert(ft::make_pair(7, "Hello"));
		m2.insert(ft::make_pair(8, "Hello"));
		m2.insert(ft::make_pair(1, "Hello"));
		m2.insert(ft::make_pair(0, "Hello"));

		std::cout << (m1 <= m2) << std::endl;
	}
	return 0;
}