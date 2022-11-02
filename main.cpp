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
		ft::vector<int> v(10);

		ft::vector<int>::const_iterator b1 = v.begin();
		ft::vector<int>::iterator b2 = v.begin();

		std::cout << (b2 == b1) << std::endl;
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