#include <vector>
#include "vector.hpp"

//resize, reserve, shrink_to_fit

template<typename T>
void print( T vec )
{
	for (unsigned int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

int main( void )
{
	{
		std::vector<int> test;

		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		std::cout << "Size = " << test.size() << ", Capacity = " << test.capacity() << std::endl;	
		test.resize(10);
		std::cout << "Size = " << test.size() << ", Capacity = " << test.capacity() << std::endl;	
		print(test);
	}

	{
		std::cout << "-----------------------" << std::endl;
		ft::vector<int> test;

		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		std::cout << "Size = " << test.size() << ", Capacity = " << test.capacity() << std::endl;	
		test.resize(10);
		std::cout << "Size = " << test.size() << ", Capacity = " << test.capacity() << std::endl;	
		print(test);
	}
	return 0;
}