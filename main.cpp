#include <vector>
#include "vector.hpp"

int main( void )
{
    std::vector<int> test;
	ft::vector<int> test1;

	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);

	test.clear();

	std::cout << "Size = " << test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;

    return 0;
}