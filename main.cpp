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
// #include "containers_test/srcs/map/common.hpp"

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

int		main(void)
{
	{
		time_t start, end;
		ft::map< int, std::string > mp, mp2;

		start = get_time();
		for (int i = 0; i < 30000; i++)
			mp.insert(ft::make_pair(i, "hello"));
		end = get_time();
		std::cout << end - start << std::endl;

		start = get_time();
		mp2.insert(mp.begin(), mp.end());
		end = get_time();
		std::cout << end - start << std::endl;
		// mp2.insert(mp.begin(), mp.end());
	}

	// ft::map< int, std::string > mp;
	// ft::map< int, std::string >::iterator b;

	// mp.insert(ft::make_pair(1, "Hi"));
	// mp.insert(ft::make_pair(3, "Hi"));
	// mp.insert(ft::make_pair(5, "Hi"));
	// mp.insert(ft::make_pair(3, "Hi"));
	// mp.insert(ft::make_pair(7, "Hi"));
	// mp.insert(ft::make_pair(8, "Hi"));
	// mp.insert(ft::make_pair(2, "Hi"));

	// for (b = mp.begin(); b != mp.end(); b++)
	// 	std::cout << b->first << std::endl;
	return (0);
}
