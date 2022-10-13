#include <vector>
#include "vector.hpp"

//Next member functions : assign, insert, erase, emplace, emplace_back

template<typename T>
void print( T vec )
{
	for (unsigned int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

int main( void )
{
	// {
	// 	std::vector<int> foo;
	// 	std::vector<int> bar; 
	
	// 	bar.push_back(1);
	// 	bar.push_back(2);
	// 	bar.push_back(3);
	// 	bar.push_back(4);
	// 	bar.__emplace_back(1000);
	// 	// bar.emplace_back(-1000);
	// 	// bar.emplace_back(2000);
	// 	// bar.emplace_back(-2000);

	// 	bar.reserve(100);
	// 	std::cout << "Foo size = " << foo.size() << std::endl;
	// 	std::cout << "Foo capaciy = " << foo.capacity() << std::endl;
	// 	std::cout << "Foo : ";
	// 	print(foo);
	// 	std::cout << "Bar size = " << bar.size() << std::endl;
	// 	std::cout << "Bar capaciy = " << bar.capacity() << std::endl;
	// 	foo.swap(bar);

	// 	std::cout << std::endl << "-----------AFTER-----------"  << std::endl << std::endl;

	// 	std::cout << "Foo size = " << foo.size() << std::endl;
	// 	std::cout << "Foo capaciy = " << foo.capacity() << std::endl;
	// 	std::cout << "Foo : ";
	// 	print(foo);
	// 	std::cout << "Bar size = " << bar.size() << std::endl;
	// 	std::cout << "Bar capaciy = " << bar.capacity() << std::endl;
	// }
	
	{
		std::vector<int> test1;
		std::vector<int> test2(10);

		test2.clear();
		test1.resize(4);
		test1[0] = 1;
		test1[1] = 2;
		test1[2] = 3;
		test1[3] = 4;
		
		std::cout << "---BEFORE---" << std::endl;
		std::cout << "Size of test2 : " << test2.size() << std::endl;
		std::cout << "Capacity of test2 : " << test2.capacity() << std::endl;

		// vector<int>::iterator b = test1.end();
		// std::cout << *(b - 1) <<  std::endl;
		test2.assign(test1.begin(), test1.end());
		print(test2);
		std::cout << "---AFTER---" << std::endl;
		std::cout << "Size of test2 : " << test2.size() << std::endl;
		std::cout << "Capacity of test2 : " << test2.capacity() << std::endl;

	}	

    return 0;
}