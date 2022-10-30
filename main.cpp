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
		// std::vector<int> t;
		// std::vector<int>::iterator non_const_iter1, non_const_iter2;
		// std::vector<int>::const_iterator const_iter, to_assign;

		// t.push_back(1);
		// t.push_back(2);
		// t.push_back(3);
		// t.push_back(4);

		// to_assign = t.begin();
		// non_const_iter1 = 2 + to_assign;

		// std::cout << *non_const_iter1 << std::endl;
	}

	std::cout << "---------FT---------" << std::endl;
	{
		ft::vector<int> t;
		ft::vector<int>::const_iterator iter1;

		t.push_back(1);
		t.push_back(2);
		t.push_back(3);
		t.push_back(4);

		iter1 = t.end();


		// std::cout << *++iter1 << std::endl;
		// std::cout << *(1 + iter1) << std::endl;

	}
}