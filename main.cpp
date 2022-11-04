#include <vector>
#include "vector.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <iterator>

template < class vector >
void print( vector vect )
{
	for (typename vector::iterator b = vect.begin(); b != vect.end(); b++)
		std::cout << *b << " ";
	std::cout << std::endl;
}

int main( void )
{
	{
		std::vector<int> vec;
		std::vector<int>::reverse_iterator rit;
		std::vector<int>::iterator it;
		
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);

		rit = vec.rend();

		// std::cout << *rit << std::endl;
		std::cout << *(rit.base()) << std::endl;
		--rit;
		std::cout << *(rit.base()) << std::endl;
	}
	std::cout << "---------FT---------" << std::endl;
	{
		ft::vector<int> vec;
		ft::vector<int>::reverse_iterator rit;
		ft::vector<int>::iterator it;
		
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);

		rit = vec.rend();

		// std::cout << *rit << std::endl;
		std::cout << *(rit.base()) << std::endl;
		--rit;
		std::cout << *(rit.base()) << std::endl;
	}
	return 0;
}