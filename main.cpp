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
		std::vector<int>::iterator b;

		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);

		b = test.end();
		print(test);

		--b;
		std::cout << *b-- << std::endl;
		--b;
		std::cout << *b-- << std::endl;
	}
	std::cout << "---------FT---------" << std::endl;
	{
		ft::vector<int> test;
		ft::vector<int>::iterator b;

		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);

		b = test.end();
		print(test);
		
		b--;
		std::cout << *b-- << std::endl;
		b--;
		std::cout << *b-- << std::endl;
	}
	return 0;
}