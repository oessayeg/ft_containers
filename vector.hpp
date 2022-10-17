#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>

// To implement :

//Constructors(4), Destructor, Assignment operator

// --ITERATORS--
// _begin
// _end
// _rbegin
// _rend

// --CAPACITY--
// _size : done
// _max_size : done
// _resize : done
// _capacity : done
// _empty : done
// _reserve : done

// --ELEMENT ACCESS--
// _[] : done
// _at : done
// _front : done
// _back : done
// _data : done

// --MODIFIERS--
// _assign : not yet
// _push_back : done
// _pop_back : done
// _insert : not yet
// _erase : not yet
// _swap : not yet
// _clear : done

// --ALLOCATOR--
// _get_allocator : done

// --NON MEMBER FUNCTION OVERLOAD--
// _relational operators
// _swap

namespace ft
{
    template< class T, class allocator = std::allocator< T > >
    class vector
    {
        public :
            typedef T value_type;
            typedef value_type* pointer;
            typedef value_type& reference;
            typedef const value_type* const_pointer;
            typedef const value_type& const_reference;
            typedef allocator allocator_type;
            typedef unsigned long size_type;

        private :
            value_type *arr;
            size_type vecSize;
            size_type vecCapacity;
            allocator_type m_allocator;

        public :
            vector( void ) : arr(NULL), vecSize(0), vecCapacity(0) {}
            
            //-------------CAPACITY-------------
            //Size of vector (member function)
            size_type size( void ) const { return vecSize; }

            //Max_size member function (max size to allocate)
            size_type max_size( void ) const { return m_allocator.max_size(); }

            //Resize member function
            void resize( size_type n, value_type val = value_type() )
            {
                if (n < vecSize)
                    while (vecSize != n)
                        pop_back();
                else if (n > vecSize)
                    while (vecSize != n)
                        push_back(val);
            }

            //Capacity member function (blocks allocated)
            size_type capacity( void ) const { return vecCapacity; }

            //Empty member function
            bool empty( void ) const { return vecSize == 0; }

            //Reserve member function
            void reserve( size_type n )
            {
                if (n > max_size())
                    throw(std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size"));
                else if (n > vecCapacity)
                {
                    pointer tmp = arr;

                    arr = m_allocator.allocate(n);
                    for (size_type i = 0; i < vecSize; i++)
                        arr[i] = tmp[i];
                    vecCapacity = n;
                }
            }

            //-------------ELEMENT ACCESS-------------
            //Subscript operator
            reference operator[]( size_type idx ) { return arr[idx]; }
            const_reference operator[]( size_type idx ) const { return arr[idx]; }

            //At member function
            reference at( size_type idx )
            {
                if ( idx >= vecSize)
                    throw std::out_of_range("vector");
                return arr[idx];
            }
            const_reference at( size_type idx ) const
            {
                if ( arr == NULL || idx >= vecSize )
                    throw std::out_of_range("vector");
                return arr[idx];
            }

            //Front member function
            reference front( void ) { return arr[0]; }
            const_reference front( void ) const { return arr[0]; }

            //Back member function
            reference back( void ) { return arr[vecSize - 1]; }
            const_reference back( void ) const { return arr[vecSize - 1]; }

            //Data member function
            pointer data( void ) throw() { return arr; }
            const_pointer data( void ) const throw() { return arr; }


            //-------------MODIFIERS-------------
            //Push_back member function
            void push_back( const_reference val )
            {
                if (vecCapacity == 0)
                {
                    arr = m_allocator.allocate(1);
                    vecCapacity = 1;
                }
                else if (vecSize == vecCapacity)
                {
                    pointer tmp = arr;

                    arr = m_allocator.allocate(vecCapacity * 2);
                    for (size_type i = 0; i < vecSize; i++)
                        arr[i] = tmp[i];
                    m_allocator.deallocate(tmp, vecCapacity);
                    vecCapacity *= 2;
                }
                arr[vecSize] = val;
                vecSize++;
            }

            //Pop_back member function    
            void pop_back( void )
            {
                m_allocator.destroy( &arr[vecSize - 1] );
                vecSize--;
            }

            //Clear member function    
            void clear( void )
            {
                while (vecSize > 0)
                    pop_back();
            }

            //-------------ALLOCATOR-------------
            allocator_type get_allocator( void ) const { return m_allocator; }
            
    };
}

#endif