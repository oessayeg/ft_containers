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
#include "set.hpp"
#include "utils/redBlackTree.hpp"

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    return (msecs_time);
}

// CASE 1 : FIXED WITH TESTS
// CASE 2 : FIXED WITH TESTS
// CASE 3 : FIXED WITH TEST
// CASE 4 : FIXED WITH TESTS
// CASE 5 : FIXED NO TEST
// CASE 6 : FIXED WITH TESTS

// CASE 2_PRIME : FIXED NO TEST
// CASE 3_PRIME : FIXED NO TEST
// CASE 5_PRIME : FIXED NO TEST

#include <set>
int		main(void)
{
    ft::redBlackTree< int, ft::less< int >, std::allocator< int > > root;
    ft::set < int > test;

    // left
    root.insert(60);
    root.insert(50);
    root.insert(65);
    root.insert(70);
    root.insert(62);
    root.erase(70);
    root.erase(62);
    // root.insert(55);
    // root.insert(40);
    // root.insert(52);

    root.erase(65);
    root.erase(50);
    root.erase(60);
    std::cout << "-----------" << std::endl;
    root.printLevels();
	return (0);
}
