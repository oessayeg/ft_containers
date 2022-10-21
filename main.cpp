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
		std::vector<int>::iterator b;

		t1.reserve(5);
		t1.push_back(1);
		t1.push_back(2);
		b = t1.end() - t1.begin();
		std::cout << *b << std::endl;
	}

	std::cout << "---------FT---------" << std::endl;
	
	{
		ft::vector<int> t1;
		ft::vector<int>::iterator b;
		
		t1.reserve(5);
		t1.push_back(1);
		t1.push_back(2);
		b = t1.end() - t1.begin();
		std::cout << *b << std::endl;
	}
	return 0;
}