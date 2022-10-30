#include <vector>
#include "vector.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>

template<typename T>
void print( T &vec )
{
	for (unsigned int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

#include <cmath>

class test
{
	public :
		test() {};
		void print() { std::cout << "Hello from print" << std::endl; };
		~test() {};
};

int main( void )
{
	{
		std::vector<int> t(10);
		std::vector<int>::iterator iter1 = t.begin();
		std::vector<int>::const_iterator cIter(iter1);


		// std::cout << *(1 + const_iter) << std::endl;
	}

	std::cout << "---------FT---------" << std::endl;
	{
		ft::vector<int> t(10);
		ft::vector<int>::const_iterator const_iter = t.begin();
		ft::vector<int>::iterator iter = t.end();

		std::cout << (const_iter == iter) << std::endl;
		std::cout << (const_iter != iter) << std::endl;
		std::cout << (const_iter > iter) << std::endl;
		std::cout << (const_iter >= iter) << std::endl;
		std::cout << (const_iter < iter) << std::endl;
		std::cout << (const_iter <= iter) << std::endl;

		std::cout << (iter == const_iter) << std::endl;
		std::cout << (iter != const_iter) << std::endl;
		std::cout << (iter > const_iter) << std::endl;
		std::cout << (iter >= const_iter) << std::endl;
		std::cout << (iter < const_iter) << std::endl;
		std::cout << (iter <= const_iter) << std::endl;
	}
}