#include <vector>
#include "vector.hpp"

//adding empty, parameterized constructor
int main( void )
{
    std::vector<int> test(13);
	ft::vector<int> test1;


	// test.push_back(1);
	// test.push_back(2);
	// test.push_back(3);
	// test.push_back(4);

	// test.clear();

	std::cout << test[0] << std::endl;
	std::cout << test[1] << std::endl;
	std::cout << test[2] << std::endl;
	std::cout << test[3] << std::endl;
	std::cout << "Size = " << test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;
    return 0;
}