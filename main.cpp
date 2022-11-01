#include <vector>
#include "vector.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <sstream>

//fixed today : assign range
//to fix : erase, erase_mixed, erase_range, insert_mixed, insert_range

template < class vector >
void checkIter( vector vect )
{
	for (typename vector::iterator b = vect.begin(); b != vect.end(); b++)
		std::cout << *b << " ";
	std::cout << std::endl;
}

template < class T, class U >
struct is_same
{
	static const bool value = false;
};

template<class T>
struct is_same<T, T>
{
	static const bool value = true;
};

int main( void )
{
	{
	    std::istringstream str("1 2 3 4 5 6 7 8 9 0 A B C D E F");
        std::istreambuf_iterator<char> it(str), end;
		std::vector<char> v;

		std::cout << (is_same<std::input_iterator_tag, ft::iterator_traits< std::istreambuf_iterator<char> >::iterator_category >::value) << std::endl;
	}

	std::cout << "---------FT---------" << std::endl;

	{

	}
}