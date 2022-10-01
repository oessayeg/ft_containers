#include <vector>
#include "vector.hpp"

//Pop_back, Shrink_to_fit

template<typename T>
void print( T vec )
{
	for (unsigned int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << std::endl;
	std::cout << std::endl;
}

int main( void )
{
	{
		std::cout << "--------STD--------" << std::endl;
		std::vector<int> test(10);

		test.push_back(9);
		test.shrink_to_fit();
		
		std::cout << "Size = " << test.size() << std::endl;
		std::cout << "Capacity " << test.capacity() << std::endl;
	}
	{
		std::cout << "--------FT--------" << std::endl;
		ft::vector<int> test(10);

		test.push_back(9);
		test.shrink_to_fit();

		std::cout << "Size = " << test.size() << std::endl;
		std::cout << "Capacity = " << test.capacity() << std::endl;
	}
    return 0;
}