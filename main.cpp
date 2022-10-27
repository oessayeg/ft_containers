#include <vector>
#include "vector.hpp"
#include <algorithm>

//Ctor_range, Ctor_copy, Ctor_size

//Print what is inside the vector

template<typename T>
void print( T &vec )
{
	for (unsigned int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

class test
{
	public :
		int x;
		test() { x = 0; }
		void change ( void )
		{
			std::cout << "Hello\n";
		}
		~test( void ) {}
};

int main( void )
{
	{
		std::vector<int> v;

	}

	std::cout << "---------FT---------" << std::endl;
	
	{	
		ft::vector<int> v;

		std::cout << "Size = " << v.size() << ", capacity = " << v.capacity() << std::endl;
	}

	return 0;
}