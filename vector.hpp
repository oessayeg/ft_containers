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
		size_type vectorSize;
		size_type vectorCapacity;
		size_type idxLast;
	public :
		//Default contructor
		vector( void ) : arr(NULL), vectorSize(0), vectorCapacity(0), idxLast(0) {}

		//Parameterized constructor
		vector( size_type n )
		{
			arr = allocator.allocate(n);
			vectorSize = n;
			vectorCapacity = n;
			idxLast = n;
			for (size_type i = 0; i < n; i++)
				allocator.construct(&arr[i], 0);
		}

		//Destructor
		~vector( void )
		{
			if (!arr)
				return;
			for (size_type i = 0; i < vectorSize; i++)
				allocator.destroy(&arr[i]);
			allocator.deallocate(arr, vectorSize);
		}
		
		//-------------ELEMENT ACCESS-------------
		//Subscript operator
		T &operator[]( size_type idx ) { return arr[idx]; }

		//At member function
		T &at( size_type idx )
		{
			if (idx > vectorSize || (idx == 0 && vectorSize == 0))
				throw std::out_of_range("vector");
			return arr[idx];
		}

		//Front member function
		T &front( void ) { return arr[0]; }

		//Back member function
		T &back( void ) { return arr[idxLast - 1]; }

		//Data member function
		T *data( void ) { return arr; }
		T const *data( void ) const { return arr; } //Const
		
		//-------------Capacity-------------
		//Size member function
		size_type size( void ) const { return vectorSize; }

		//Max size to allocate
		size_type max_size( void ) const { return allocator.max_size(); }

		//Capacity member function
		size_type capacity( void ) const { return vectorCapacity; }

		//Empty member function
		bool empty( void ) const
		{
			if (arr == NULL || (arr != NULL && vectorSize == 0))
				return true;
			return false;
		}

		//Reserve member function
		void reserve( size_type n )
		{
			T *tmp;

			if (n <= vectorCapacity)
				return ;
			tmp = arr;
			arr = allocator.allocate(n);
			for (size_type i = 0; i < vectorSize; i++)
			{
				allocator.construct(&arr[i], tmp[i]);
				allocator.destroy(tmp);
			}
			allocator.deallocate(tmp, vectorSize);
			vectorCapacity = n;
		}
		
		//Push_back
		void push_back( const T &value )
		{
			if (vectorCapacity == 0)
			{
				arr = allocator.allocate(1);
				vectorCapacity = 1;
			}
			else if (idxLast == vectorCapacity)
			{
				T *tmp = arr;

				arr = allocator.allocate(vectorCapacity * 2);
				for (size_type i = 0; i < vectorSize; i++)
				{
					allocator.construct(&arr[i], tmp[i]);
					allocator.destroy(&tmp[i]);
				}
				allocator.deallocate(tmp, vectorSize);
				vectorCapacity *= 2;
			}
			allocator.construct(&arr[idxLast], value);
			idxLast++;
			vectorSize++;
		}

		//Get allocator (copy)
		Allocator get_allocator( void ) const { return Allocator(allocator); }

		//Clear member function
		void clear( void )
		{
			for (size_type i = 0; i < vectorSize; i++)
				allocator.destroy(&arr[i]);
			vectorSize = 0;
			idxLast = 0;
		}
};

}