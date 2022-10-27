#include <iostream>
#include <set>
#include "utils.hpp"


template < class T >
T test( T a, T b )
{
	return a + b;
}

template <>
int test< int >( int a, int b )
{
	return a * b;
}

class B
{
	void print( void ) { std::cout << "Hello from B" << std::endl; }
};

class D1
{
	void print( void ) { std::cout << "Hello from D1" << std::endl; }
}

class D2
{
	void print( void ) { std::cout << "Hello from D2" << std::endl; };
};

int main( void )
{
	std::cout << test(2.33f, 2.132f) << std::endl;
	std::cout << test(5, 2) << std::endl;
	return 0;
}