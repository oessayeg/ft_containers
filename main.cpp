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
		const int size = 5;
		std::vector<int> vct(size);
		std::vector<int>::reverse_iterator it(vct.rbegin());
		std::vector<int>::const_reverse_iterator ite(vct.rend());

		for (int i = 1; it != ite; ++i)
			*it++ = (i * 7);

		it = vct.rbegin();
		ite = vct.rbegin();

		std::cout << *(++ite) << std::endl;
		std::cout << *(ite++) << std::endl;
		std::cout << *ite++ << std::endl;
		std::cout << *++ite << std::endl;

		it->m();
		// ite->m();

		// std::cout << *(++it) << std::endl;
		// std::cout << *(it++) << std::endl;
		// std::cout << *it++ << std::endl;
		// std::cout << *++it << std::endl;

		// std::cout << *(--ite) << std::endl;
		// std::cout << *(ite--) << std::endl;
		// std::cout << *--ite << std::endl;
		// std::cout << *ite-- << std::endl;

		// (*it).m();
		// (*ite).m();

		// std::cout << *(--it) << std::endl;
		// std::cout << *(it--) << std::endl;
		// std::cout << *it-- << std::endl;
		// std::cout << *--it << std::endl;
	}

	std::cout << "---------FT---------" << std::endl;
	
	{
		const int size = 5;
		ft::vector<int> vct(size);
		ft::vector<int>::reverse_iterator it(vct.rbegin());
		ft::vector<int>::const_reverse_iterator ite(vct.rend());

		for (int i = 1; it != ite; ++i)
			*it++ = (i * 7);

		it = vct.rbegin();
		ite = vct.rbegin();

		std::cout << *(++ite) << std::endl;
		std::cout << *(ite++) << std::endl;
		std::cout << *ite++ << std::endl;
		std::cout << *++ite << std::endl;

		it->m();
		// ite->m();

		// std::cout << *(++it) << std::endl;
		// std::cout << *(it++) << std::endl;
		// std::cout << *it++ << std::endl;
		// std::cout << *++it << std::endl;

		// std::cout << *(--ite) << std::endl;
		// std::cout << *(ite--) << std::endl;
		// std::cout << *--ite << std::endl;
		// std::cout << *ite-- << std::endl;

		// (*it).m();
		// (*ite).m();

		// std::cout << *(--it) << std::endl;
		// std::cout << *(it--) << std::endl;
		// std::cout << *it-- << std::endl;
		// std::cout << *--it << std::endl;
	}
	return 0;
}