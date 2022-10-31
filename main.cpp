#include <vector>
#include "vector.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>

//Performance check for 'ctor_range', 'insert_range'
//Check assign_range, insert_range
//Erase mixed

template<typename T>
void print( T &vec )
{
	for (unsigned int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

#include <iterator>
int main( void )
{
	{
		std::vector<int> test1(64);

		print(test1);
		test1.erase(test1.begin(), test1.begin());
		test1.erase(test1.end(), test1.end());
		test1.erase(test1.begin());
		test1.erase(test1.end() - 1);
		print(test1);
	}

	std::cout << "---------FT---------" << std::endl;

	{
		ft::vector<int> test1(64);

		print(test1);
		test1.erase(test1.begin(), test1.begin());
		test1.erase(test1.end(), test1.end());
		test1.erase(test1.begin());
		test1.erase(test1.end() - 1);
		print(test1);
	}
}