#include <vector>
#include "vector.hpp"
#include <algorithm>

//OK : Resize, reserve

//KO : Assign

//Print what is inside the vector

//assign range, erase

template<typename T>
void print( T &vec )
{
	for (unsigned int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

class test
{
	public :
		int x;
		test() { x = 0; }
		void change ( void )
		{
			std::cout << "Hello\n";
		}
		~test( void ) {}
};

int main( void )
{
	{
		std::vector<int> v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.assign(32, -10);

		std::cout << "Size = " << v.size() << ", Capacity = " << v.capacity() << std::endl;
		print(v);
	}

	std::cout << "---------FT---------" << std::endl;
	
	{
        std::vector<char> v(10);

        v.assign(0, 'c');
        print(v);
        // v.assign(64, 'A');

        // v.assign(32, 'A');

	}

	return 0;
}