#include <vector>
#include "vector.hpp"

//parameterized constructor, clear member function, get_allocator, push_back, back member function
//data member function

int main( void )
{
	{
		std::vector<int> test;

		test.reserve(3);

		std::cout << "Size = " << test.size() << std::endl;
		std::cout << "Capacity = " << test.capacity() << std::endl;
		std::cout << test[0] << std::endl;
		std::cout << test[1] << std::endl;
		std::cout << test[2] << std::endl;
		test.push_back(10);
		test.push_back(20);
		test.push_back(30);
		test.push_back(40);
		std::cout << "Size = " << test.size() << std::endl;
		std::cout << "Capacity = " << test.capacity() << std::endl;
		// i = test.data();
		// i1 = test.data();
		// std::cout << "--------STD--------" << std::endl;
		// std::cout << "Size = " << test.size() << std::endl;
		// std::cout << "Capacity = " << test.capacity() << std::endl;
		// std::cout << *i << std::endl;
		// std::cout << *i1 << std::endl;

	}
	{
		ft::vector<int> test;

		test.push_back(10);
		test.push_back(20);
		test.push_back(30);
		test.push_back(40);
		std::cout << "--------FT--------" << std::endl;
		std::cout << "Size = " << test.size() << std::endl;
		std::cout << "Capacity = " << test.capacity() << std::endl;
	}
    return 0;
}