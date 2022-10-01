#include <vector>
#include "vector.hpp"

//Resize

//Need copy constructor and copy assignment operator

template<typename T>
void print( T &vec )
{
	for (unsigned int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

int main( void )
{
	{
		std::cout << "--------STD--------" << std::endl;
		std::vector<int> test;

		test.reserve(5);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		std::cout << "Size = " << test.size() << std::endl;
		std::cout << "Capacity " << test.capacity() << std::endl;
		test.resize(9, -1);
		std::cout << "Size = " << test.size() << std::endl;
		std::cout << "Capacity = " << test.capacity() << std::endl;
		print(test);
	}
	{
		std::cout << "--------FT--------" << std::endl;
		ft::vector<int> test;

		test.reserve(5);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		std::cout << "Size = " << test.size() << std::endl;
		std::cout << "Capacity = " << test.capacity() << std::endl;
		test.resize(9, -1);
		std::cout << "Size = " << test.size() << std::endl;
		std::cout << "Capacity = " << test.capacity() << std::endl;
		print(test);
	}
    return 0;
}