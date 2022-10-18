#include <vector>
#include "vector.hpp"

//resize, reserve, shrink_to_fit

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
		// std::vector<int> test;
		// std::vector<int>::iterator b, e;

		// test.push_back(0);
		// test.push_back(1);
		// test.push_back(2);
		// test.push_back(3);
		// test.push_back(4);

		// std::vector<int> t(test.begin(), test.end());
		// std::cout << "Size of test = " << test.size() << ", capacity of test = " << test.capacity() << std::endl;
		// print(t);
		// std::cout << "Size of t = " << t.size() << ", capacity of t = " << t.capacity() << std::endl;
	}
	std::cout << "---------FT---------" << std::endl;
	{
		ft::vector<int> test;
		ft::vector<int>::iterator b, e;

		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);

		std::cout << test.end() - test.begin() << std::endl;
		// ft::vector<int> t(test.begin(), test.end());
		// std::cout << "Size of test = " << test.size() << ", capacity of test = " << test.capacity() << std::endl;
		// print(t);
		// std::cout << "Size of t = " << t.size() << ", capacity of t = " << t.capacity() << std::endl;
	}

	return 0;
}