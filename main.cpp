#include <vector>
#include "vector.hpp"

//Objective : Relational operators

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
		std::vector<int> foo;
		std::vector<int> bar; 

		foo.push_back(1);
		foo.push_back(2);
		foo.push_back(3);

		bar.push_back(1);
		bar.push_back(2);
		bar.push_back(4);
		std::cout << (foo <= bar) << std::endl;
	}
	{
		ft::vector<int> foo;
		ft::vector<int> bar; 

		foo.push_back(1);
		foo.push_back(2);
		foo.push_back(3);

		bar.push_back(1);
		bar.push_back(2);
		bar.push_back(4);
		std::cout << (foo <= bar) << std::endl;
	}
    return 0;
}