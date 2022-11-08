#include <vector>
#include "vector.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <iterator>
#include <sys/time.h>

template < class vector >
void print( vector vect )
{
	for (typename vector::iterator b = vect.begin(); b != vect.end(); b++)
		std::cout << *b << " ";
	std::cout << std::endl;
}

template < class vector >
void printSize( vector vec )
{
	std::cout << "Size = " << vec.size() << std::endl;
	std::cout << "Capacity = " << vec.capacity() << std::endl;
	print(vec);
}

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

#include <utility>

int main( void )
{
	ft::pair<std::string, int>("hello", -123);

    return 0;
}