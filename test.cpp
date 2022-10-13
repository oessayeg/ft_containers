#include <iostream>
#include <vector>

int main( void )
{
    std::vector<int> test1;
    ft::vector<int> test2;

    test1.reserve(9);
    test2.reserve(9);

    try
    {
        std::cout << test1.at(10) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // std::cout << *b << std::endl;
    return 0;
}