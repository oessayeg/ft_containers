#include <vector>
#include "vector.hpp"

//added reserve function

int main( void )
{
	{
		std::cout << "--------STD--------" << std::endl;
		std::vector<int> test;


		test.reserve(3);
		std::cout << "Size = " << test.size() << std::endl;
		std::cout << "Capacity = " << test.capacity() << std::endl;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.reserve(10);
		std::cout << "Nb : " << test[0] << std::endl;
		std::cout << "Nb : " << test[1] << std::endl;
		std::cout << "Nb : " << test[2] << std::endl;
		std::cout << "Nb : " << test[3] << std::endl;
		std::cout << "Size = " << test.size() << std::endl;
		std::cout << "Capacity = " << test.capacity() << std::endl;
	}
	{
		std::cout << "--------FT--------" << std::endl;
		ft::vector<int> test;

		test.reserve(3);
		std::cout << "Size = " << test.size() << std::endl;
		std::cout << "Capacity = " << test.capacity() << std::endl;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.reserve(10);
		std::cout << "Nb : " << test[0] << std::endl;
		std::cout << "Nb : " << test[1] << std::endl;
		std::cout << "Nb : " << test[2] << std::endl;
		std::cout << "Nb : " << test[3] << std::endl;
		std::cout << "Size = " << test.size() << std::endl;
		std::cout << "Capacity = " << test.capacity() << std::endl;
	}
    return 0;
}