#include <vector>
#include "vector.hpp"

//resize, reserve, shrink_to_fit
//Print what is inside the vector
template<typename T>
void print( T &vec )
{
	for (unsigned int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}
//Print what is inside the vector


int main( void )
{
	{
		std::vector<int> t1;
		std::vector<int> t2;

		t2.push_back(10);
		t2.push_back(20);
		t2.push_back(30);
		t2.push_back(40);
		t2.push_back(50);

		t1.reserve(20);
		t1.push_back(1);
		t1.push_back(2);
		t1.push_back(3);
		t1.push_back(4);

		std::cout << "Size = " << t1.size() << ", Capacity = " << t1.capacity() << std::endl;
		t1.insert(t1.begin() + 1, t2.begin(), t2.begin());
		std::cout << "Size = " << t1.size() << ", Capacity = " << t1.capacity() << std::endl;
		print(t1);
	}
	std::cout << "---------FT---------" << std::endl;
	{
		ft::vector<int> t1;
		ft::vector<int> t2;

		t2.push_back(10);
		t2.push_back(20);
		t2.push_back(30);
		t2.push_back(40);
		t2.push_back(50);

		t1.reserve(20);
		t1.push_back(1);
		t1.push_back(2);
		t1.push_back(3);
		t1.push_back(4);

		std::cout << "Size = " << t1.size() << ", Capacity = " << t1.capacity() << std::endl;
		t1.insert(t1.begin() + 1, t2.begin() + 1, t2.begin());
		std::cout << "Size = " << t1.size() << ", Capacity = " << t1.capacity() << std::endl;
		print(t1);
	}

	return 0;
}