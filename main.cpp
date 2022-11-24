#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "utils/tree.hpp"
#include <iterator>
#include <sys/time.h>
#include <map>
#include <cmath>
#include "map.hpp"
#include "utils/functional.hpp"
#include <utility>
#include "vector.hpp"
#include "stack.hpp"

int	main(void)
{

	ft::map < int, int > mp;
	
	mp.insert(ft::make_pair(5, 12));
	mp.insert(ft::make_pair(50, 12));

	ft::map< int, int >::iterator b = mp.begin();

	b++;
	b++;
	--b;
	std::cout << b->first << std::endl;
	// ft::map < float, int > mp;

	// mp.insert(ft::make_pair(-1.5f, 35));
	// mp.insert(ft::make_pair(-0.5f, 28));
	// mp.insert(ft::make_pair(0.5f, 21));
	// mp.insert(ft::make_pair(1.5f, 14));
	// mp.insert(ft::make_pair(2.5f, 7));
	// // ft::map<float, int>::reverse_iterator it(mp.rbegin());
	// ft::map<float, int>::const_reverse_iterator ite(mp.rbegin());

	// std::cout << ite->first << std::endl;
	// ++ite;
	// std::cout << ite->first << std::endl;
	// ite++;
	// std::cout << ite->first << std::endl;
	// ite++;
	// std::cout << ite->first << std::endl;
	// ++ite;
	// std::cout << ite->first << std::endl;

	// // ++it;
	// // it++;
	// // it++;
	// // ++it;

	// --ite;
	// ite--;
	// ite--;
	// std::cout << "---------\n";
	// std::cout << ite.base().getCurrent()->data.first << std::endl;
	// std::cout << ite->first << std::endl;
	// std::cout << "---------\n";
	// --ite;

	// std::cout << ite->first << std::endl;

	return (0);
}
