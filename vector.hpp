#include <iostream>
#include <exception>

namespace ft{

template<class T, class Allocator = std::allocator<T> >
class vector
{
	private :
		T *arr;
		unsigned int sizeOfVec;
		unsigned int capacityOfVec;
	public :
		vector( void );
		// vector( vector const &rhs );
		~vector( void );
		// vector &operator=( vector const &rhs );
		T &operator[]( unsigned int idx );
		T &at( unsigned int idx );
		unsigned int size( void ) const;
		unsigned int capacity( void ) const;
		//test
		unsigned int max_size() const
		{
			return Allocator::max_size();
		}
		//test
};

//Default constructor
template< class T, class Allocator >
vector< T, Allocator >::vector( void ) : arr(NULL), sizeOfVec(0), capacityOfVec(0){}

//Destructor
template< class T, class Allocator >
vector< T, Allocator >::~vector( void )
{
	if (arr)
		delete arr;
}

//Subscript operator
template< class T, class Allocator >
T &vector< T, Allocator >::operator[]( unsigned int idx )
{
	return arr[idx];
}

//At
template< class T, class Allocator >
T &vector< T, Allocator >::at( unsigned int idx )
{
	if (idx > sizeOfVec || (idx == 0 && sizeOfVec == 0))
		throw std::out_of_range("vector");
	return arr[idx];
}

//Size
template< class T, class Allocator >
unsigned int vector< T, Allocator >::size( void ) const
{
	return sizeOfVec;
}

//Capacity
template< class T, class Allocator >
unsigned int vector< T, Allocator >::capacity( void ) const
{
	return capacityOfVec;
}




}