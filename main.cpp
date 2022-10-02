#include <vector>
#include "vector.hpp"

//Added second parameter for the parameterized constructor
//Copy constructor and copy assignment operator

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
		std::cout << "--------STD--------" << std::endl;
		std::vector<int> test2;
		std::vector<int> test1;

		test1.push_back(1);
		test1.push_back(2);
		
		test2.push_back(10);
		test2.push_back(20);
		test2.push_back(30);
		test2.push_back(40);
		test2.push_back(50);
		std::cout << "Test2 Size = " << test2.size() << std::endl;
		std::cout << "Test2 Capacity = " << test2.capacity() << std::endl;
		test1 = test2;
		std::cout << "Test1 Size = " << test1.size() << std::endl;
		std::cout << "Test1 Capacity = " << test1.capacity() << std::endl;
		print(test1);
	}
	{
		std::cout << "--------STD--------" << std::endl;
		ft::vector<int> test1;
		ft::vector<int> test2;

		test1.push_back(1);
		test1.push_back(2);
		
		test2.push_back(10);
		test2.push_back(20);
		test2.push_back(30);
		test2.push_back(40);
		test2.push_back(50);
		std::cout << "Test2 Size = " << test2.size() << std::endl;
		std::cout << "Test2 Capacity = " << test2.capacity() << std::endl;
		test1 = test2;
		std::cout << "Test1 Size = " << test1.size() << std::endl;
		std::cout << "Test1 Capacity = " << test1.capacity() << std::endl;
		print(test1);
	}
    return 0;
}