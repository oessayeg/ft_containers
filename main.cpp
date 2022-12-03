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

template <typename ForwardIt, typename T>
void iota(ForwardIt first, ForwardIt last, T value = T())
{
    while (first != last) {
        *first++ = value;
        ++value;
    }
}

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    return (msecs_time);
}

template <typename T>
void init_array(T* arr, std::size_t size)
{
    iota(arr, arr + size, (T)rand());
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
    int int_arr[64];

    ft::set < int > m;
    ft::set< int >::iterator b;

    init_array(int_arr, 64);
    m.insert(int_arr, int_arr + 25);

    // for (int i = 0; i < 25; i++)
    //     std::cout << int_arr[i] << " ";
    // std::cout << std::endl;

    b = m.begin();
    m.erase(b);

    b = m.begin();
    std::advance(b, 21);
    m.erase(b);

    b = m.end();
    std::advance(b, -10);
    // std::cout << *b << std::endl;
    m.erase(b);

    b = m.end();
    std::advance(b, -3);
    m.erase(b);

    b = m.end();
    std::advance(b, -1);
    m.erase(b);
    
    // std::cout << *b << std::endl;
    // 16831
    // m.erase(16809);
    // m.erase(16810);
    // m.erase(16811);
    // m.erase(16812);
    // m.erase(16813);
    // m.erase(16814);
    // m.erase(16815);
    // m.erase(16816);

    // m.erase(16813);
    // m.erase(m.begin(), m.end());
    m.base.printLevels();
	return (0);
}
