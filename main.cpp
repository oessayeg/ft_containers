#include <vector>
#include "vector.hpp"

//Added swap member function

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
	
		bar.push_back(1);
		bar.push_back(2);
		bar.push_back(3);
		bar.push_back(4);

		std::cout << "Foo size = " << foo.size() << std::endl;
		std::cout << "Foo capaciy = " << foo.capacity() << std::endl;
		std::cout << "Foo : ";
		print(foo);
		std::cout << "Bar size = " << bar.size() << std::endl;
		std::cout << "Bar capaciy = " << bar.capacity() << std::endl;
		foo.swap(bar);

		std::cout << std::endl << "-----------AFTER-----------"  << std::endl << std::endl;

		std::cout << "Foo size = " << foo.size() << std::endl;
		std::cout << "Foo capaciy = " << foo.capacity() << std::endl;
		std::cout << "Foo : ";
		print(foo);
		std::cout << "Bar size = " << bar.size() << std::endl;
		std::cout << "Bar capaciy = " << bar.capacity() << std::endl;
	}
	
	{
		std::cout << std::endl << "--------FT--------" << std::endl << std::endl;
		std::vector<int> foo;
		std::vector<int> bar; 
	
		bar.push_back(1);
		bar.push_back(2);
		bar.push_back(3);
		bar.push_back(4);

		std::cout << "Foo size = " << foo.size() << std::endl;
		std::cout << "Foo capaciy = " << foo.capacity() << std::endl;
		std::cout << "Foo : ";
		print(foo);
		std::cout << "Bar size = " << bar.size() << std::endl;
		std::cout << "Bar capaciy = " << bar.capacity() << std::endl;
		foo.swap(bar);

		std::cout << std::endl << "-----------AFTER-----------"  << std::endl << std::endl;

		std::cout << "Foo size = " << foo.size() << std::endl;
		std::cout << "Foo capaciy = " << foo.capacity() << std::endl;
		std::cout << "Foo : ";
		print(foo);
		std::cout << "Bar size = " << bar.size() << std::endl;
		std::cout << "Bar capaciy = " << bar.capacity() << std::endl;
}
    return 0;
}