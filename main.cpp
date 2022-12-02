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
    ft::set < int > test;
    ft::set< int >::const_iterator cb;
    ft::set< int >::iterator b;
    
    // cb = test.begin();

    // test.insert(50);
    // test.insert(40);
    // test.insert(60);
    // test.insert(30);
    // test.insert(45);

    // cb = test.begin();
    // for (b = test.begin(); b != test.end(); b++)
    //     std::cout << *b << " ";
    
    // b = test.find(40);
    // std::cout << *test.insert(210).first << std::endl;
	return (0);
}
