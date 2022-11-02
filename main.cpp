#include <vector>
#include "vector.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <iterator>

//fixed today : erase, erase_range, swap

template < class vector >
void checkIter( vector vect )
{
	for (typename vector::iterator b = vect.begin(); b != vect.end(); b++)
		std::cout << *b << " ";
	std::cout << std::endl;
}

int main( void )
{
	std::cout << "---------STD---------" << std::endl;
	{
		ft::vector<int> v1;
		ft::vector<int> v2;

		v1.push_back(10);
		v1.push_back(20);
		v1.push_back(30);
		v1.push_back(40);
		v1.push_back(50);

		v2.push_back(10);
		v2.push_back(20);
		v2.push_back(30);
		v2.push_back(40);
		v2.push_back(50);

		std::cout << ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
		std::cout << (v1 <= v2) << std::endl;
	}

	std::cout << "---------FT---------" << std::endl;

	{
		// ft::vector<int> v1;
		// ft::vector<int>::const_iterator b1 = v1.begin();
		// ft::vector<int>::iterator b2;

		// b2 = b1;
		// std::cout << "Int : " << sizeof(int) << ", Const Int : " << sizeof(const int) << std::endl;
		// (void)b1;
		// (void)b2;
		// (void)b3;
		// b2 = b1;
	}
}