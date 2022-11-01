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

template < class iter >
void checkIter( iter iterator )
{
	if (typeid(typename ft::iterator_traits< iter >::iterator_category) == typeid(std::random_access_iterator_tag))
		std::cout << "Random access" << std::endl;
	else if (typeid(typename ft::iterator_traits< iter >::iterator_category) == typeid(std::input_iterator_tag))
		std::cout << "Input iterator" << std::endl;
	std::cout << *iterator << std::endl;
}

int main( void )
{
	{
        // std::vector<char> v(2, 'U');
		// std::istringstream str("1 2 3 4 5 6 7 8 9 0 A B C D E F");
        // std::istreambuf_iterator<char> it(str), end;
        // // std::istreambuf_iterator<char> itCopy = it, endCopy = end;

		// checkIter(it);
		// // for (; itCopy != endCopy; itCopy++)
		// // 	std::cout << *itCopy << " ";
		
		// // std::cout << std::endl;

		// // for (; it != end; it++)
		// // 	std::cout << *it << " ";

		// std::cout << std::endl;


	    // v.insert(v.end(), it, end);
	
		// std::vector<char> v(20);
        
        // std::istringstream str("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22");
        // std::istreambuf_iterator<char> it(str), end;

		// v.assign(it, end);
		// std::cout << "Capacity = " << v.capacity() << std::endl;
		// std::cout << "Size = " << v.size() << std::endl;
		// print(v);
	}

	std::cout << "---------FT---------" << std::endl;

	{
        ft::vector v(2, 'U');
		std::istringstream str("1 2 3 4 5 6 7 8 9 0 A B C D E F");
        std::istreambuf_iterator<char> it(str), end;
		
		ft::iterDistance(it, end);

        // v.insert(v.end(), it, end);
		// ft::vector<char> v;
        
        // std::istringstream str("1 2 3 4 5 6 7");
        // std::istreambuf_iterator<char> it(str), end;

		// v.assign(it, end);
		// print(v);
	}
}