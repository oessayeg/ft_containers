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
	{
		std::vector<int> v1(10);
		std::vector<int> v2(20);
		std::vector<int>::iterator it;

		std::cout << "Before" << std::endl;
		std::cout << "Size of v1 = " << v1.size() << ", Capacity of v1 = " << v1.capacity() << std::endl;
		std::cout << "Size of v2 = " << v2.size() << ", Capacity of v2 = " << v2.capacity() << std::endl;

		v1.swap(v2);

		std::cout << "After" << std::endl;
		std::cout << "Size of v1 = " << v1.size() << ", Capacity of v1 = " << v1.capacity() << std::endl;
		std::cout << "Size of v2 = " << v2.size() << ", Capacity of v2 = " << v2.capacity() << std::endl;	
	}

	std::cout << "---------FT---------" << std::endl;

	{
		std::vector<int> v1(10);
		std::vector<int> v2(20);
		std::vector<int>::iterator it;

		std::cout << "Before" << std::endl;
		std::cout << "Size of v1 = " << v1.size() << ", Capacity of v1 = " << v1.capacity() << std::endl;
		std::cout << "Size of v2 = " << v2.size() << ", Capacity of v2 = " << v2.capacity() << std::endl;

		v1.swap(v2);

		std::cout << "After" << std::endl;
		std::cout << "Size of v1 = " << v1.size() << ", Capacity of v1 = " << v1.capacity() << std::endl;
		std::cout << "Size of v2 = " << v2.size() << ", Capacity of v2 = " << v2.capacity() << std::endl;	
	}
}