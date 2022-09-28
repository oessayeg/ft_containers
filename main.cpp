#include <vector>
#include "vector.hpp"

int main( void )
{
    std::vector<int> test;
	ft::vector<int> test1;

    // test.push_back(1);
    // test.push_back(2);
    // test.push_back(3);
    // test.push_back(4);
    // test.push_back(5);

    std::cout << test.max_size() << std::endl;
    std::cout << test1.max_size() << std::endl;
    return 0;
}