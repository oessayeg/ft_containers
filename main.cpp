#include <vector>
#include "vector.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <iterator>

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
		std::vector<int> vec;
		std::vector<int>::reverse_iterator iter1;
		std::vector<int>::reverse_iterator iter2;
		std::vector<int>::const_reverse_iterator citer1;
		std::vector<int>::const_reverse_iterator citer2;

		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		vec.push_back(50);
		vec.push_back(60);
		vec.push_back(70);

		iter1 = vec.rbegin();
		iter2 = vec.rbegin();
		citer2 = vec.rbegin();
		citer2 = vec.rbegin();

		// std::cout << (iter1 < iter1 + 1) << std::endl;
		std::cout << (iter1 < iter1 ) << std::endl;
		// std::cout << (iter1 != citer1) << std::endl;
	}

	std::cout << "---------FT---------" << std::endl;
	
	{
		ft::vector<int> vec;
		ft::vector<int>::reverse_iterator iter1;
		ft::vector<int>::reverse_iterator iter2;
		ft::vector<int>::const_reverse_iterator citer1;
		ft::vector<int>::const_reverse_iterator citer2;

		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		vec.push_back(50);
		vec.push_back(60);
		vec.push_back(70);

		iter1 = vec.rbegin();
		iter2 = vec.rbegin();
		citer2 = vec.rbegin();
		citer2 = vec.rbegin();

		// std::cout << (iter1 < iter1 + 1) << std::endl;
		std::cout << (iter1 < iter1) << std::endl;
		// std::cout << (iter1 != citer1) << std::endl;
	}
}