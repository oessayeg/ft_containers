#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "utils/avlTree.hpp"
#include <iterator>
#include <sys/time.h>
#include <map>
#include <cmath>
#include "map.hpp"
#include "utils/functional.hpp"
#include <utility>
#include "vector.hpp"
#include "stack.hpp"
#include "utils/redBlackTree.hpp"

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    return (msecs_time);
}

int		main(void)
{
    ft::redBlackTree< int, ft::less< int >, std::allocator< int > > root;

    root.insert(10);
    root.insert(18);
    root.insert(7);
    root.insert(15);
    root.insert(16);
    root.insert(30);
    root.insert(25);
    root.insert(40);
    root.insert(60);
    root.insert(1);
    root.insert(2);
    root.insert(70);
    root.insert(8);
    root.insert(150);
    root.printLevels();
	return (0);
}
