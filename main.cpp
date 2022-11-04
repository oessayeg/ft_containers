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
	std::cout << "---------STD---------" << std::endl;
	{
		const int size = 5;
		std::vector<int> vct(size);
		std::vector<int>::iterator it_0(vct.begin());
		std::vector<int>::iterator it_1(vct.end());
		std::vector<int>::iterator it_mid(vct.end());

		std::vector<int>::const_iterator cit_0 = vct.begin();
		std::vector<int>::const_iterator cit_1;
		std::vector<int>::const_iterator cit_mid;
		for (int i = size; it_0 != it_1; --i)
				*it_0++ = i;

		std::cout << "Size = " << vct.size() << std::endl;
		std::cout << "Capacity = " << vct.size() << std::endl;
		print(vct);

		it_0 = vct.begin();
		cit_1 = vct.end();
		it_mid = it_0 + 3;
		cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

		// std::cout << std::boolalpha;
		std::cout << (it_0 == cit_0 + 3) << " " << (cit_0 + 3 == it_mid) << std::endl;
		std::cout << *it_0 << std::endl;
		std::cout << *(cit_0 + 3) << std::endl;
	}

	std::cout << "---------FT---------" << std::endl;
	
	{
		std::vector<int> x, b;
		std::vector<int>::iterator it1, it2;

		x.push_back(10);
		x.push_back(20);
		x.push_back(30);
		x.push_back(40);

		b.push_back(10);
		b.push_back(20);
		b.push_back(30);
		b.push_back(40);

		
		// const int size = 5;
		// ft::vector<int> vct(size);
		// ft::vector<int>::iterator it_0(vct.begin());
		// ft::vector<int>::iterator it_1(vct.end());
		// ft::vector<int>::iterator it_mid(vct.end());

		// ft::vector<int>::const_iterator cit_0 = vct.begin();
		// ft::vector<int>::const_iterator cit_1;
		// ft::vector<int>::const_iterator cit_mid;
		// for (int i = size; it_0 != it_1; --i)
		// 		*it_0++ = i;

		// std::cout << "Size = " << vct.size() << std::endl;
		// std::cout << "Capacity = " << vct.size() << std::endl;
		// print(vct);

		// it_0 = vct.begin();
		// cit_1 = vct.end();
		// it_mid = it_0 + 3;
		// cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

		// std::cout << (it_0 == cit_0 + 3) << " " << (cit_0 + 3 == it_mid) << std::endl;
		
		// std::cout << *it_0 << std::endl;
		// std::cout << *(cit_0 + 3) << std::endl;
	}
	return 0;
}