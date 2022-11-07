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


template < class T >
void testFunction( void )
{
}

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

int main( void )
{
	time_t start, end;

    ft::vector<std::string> v1(1e6, "string2");
    v1.reserve(1e6 + 1);
	start = get_time();
	v1.insert(v1.begin() + 1e5, "string1");
	end = get_time();
	std::cout << (end - start) << std::endl;
	return 0;
}