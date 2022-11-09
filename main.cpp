#include <vector>
#include "vector.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <iterator>
#include <sys/time.h>
#include "stack.hpp"

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
#include <algorithm>
#include <stack>
#include <deque>

class test
{
	protected :
		int num;
	public :
		test() : num() {}
		test( int n ) : num(n) {}
		~test() {}
};

class a
{
	private :
		int *i;

	public :
		a()
		{
			std::cout << "+++CONSTRUCTOR+++" << std::endl;;
			i = (int *)malloc(sizeof(int));
		}
		~a()
		{
			std::cout << "---DESTRUCTOR---" << std::endl;
			free(i);
		}
};

int main( void )
{
	std::allocator<a> m_alloc;
	a *arr = m_alloc.allocate(1);

	m_alloc.construct(&arr[0], a());
	// m_alloc.destroy(&arr[0]);
    return 0;
}