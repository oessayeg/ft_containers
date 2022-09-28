#include <iostream>
#include <exception>

namespace ft{

//Still need copy constructor and copy assignement operator overload

template<class T, class Allocator = std::allocator<T> >
class vector
{
	private :
		typedef unsigned long size_type;
		T *arr;
		Allocator allocator;
		size_type sizeOfVec;
		size_type capacityOfVec;
		size_type idxLast;
	public :
		//Default contructor
		vector( void ) : arr(NULL), sizeOfVec(0), capacityOfVec(0), idxLast(0) {}

		//Destructor
		~vector( void )
		{
			if (arr)
				delete arr;
		}
		
		//Subscript operator
		T &operator[]( size_type idx ) { return arr[idx]; }

		//At member function
		T &at( size_type idx )
		{
			if (idx > sizeOfVec || (idx == 0 && sizeOfVec == 0))
				throw std::out_of_range("vector");
			return arr[idx];
		}

		//Size member function
		size_type size( void ) const { return sizeOfVec; }

		//Capacity member function
		size_type capacity( void ) const { return capacityOfVec; }

		//Max size to allocate
		size_type max_size( void ) const { return allocator.max_size(); }

		//Front member function
		T &front( void ) { return arr[0]; }

		//Empty member function
		bool empty( void ) const
		{
			if (arr == NULL || (arr != NULL && sizeOfVec == 0))
				return true;
			return false;
		}
};


}