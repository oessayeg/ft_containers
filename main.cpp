#include <vector>
#include "vector.hpp"

//Print what is inside the vector
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
		std::vector<int> t1;
		std::vector<std::string> t2;

		t2.push_back("hello");
		// std::vector<int>::iterator b;
		// int arr[10] = {1, 2, 3, 4};

		// std::cout << (t2.begin() < t1.begin()) << std::endl;
		// std::cout << *b << std::endl;
	}

	std::cout << "---------FT---------" << std::endl;
	
	{
		ft::vector<int> t1;
		ft::vector<std::string> t2;

		t2.push_back("hello");
		std::vector<int>::iterator b;
		// int arr[10] = {1, 2, 3, 4};

		std::cout << (t2.begin() < t1.begin()) << std::endl;
		// std::cout << *b << std::endl;
	}
	return 0;
}