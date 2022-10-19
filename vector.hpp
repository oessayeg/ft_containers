#ifndef VECTOR_HPP
# define VECTOR_HPP

// To implement :

//Constructors(4) : done
//Destructor : done
//Copy assignment operator

// --ITERATORS--
// _begin : done
// _end : done
// _rbegin : done
// _rend : done

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

#include <iostream>
#include <memory>
#include "iterator.hpp"

namespace ft
{
    template< class T, class allocator = std::allocator< T > >
    class vector
    {
        public :
            typedef T value_type;
            typedef allocator allocator_type;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;
			typedef vectorIterator< vector< T > > iterator;
			typedef const vectorIterator< vector< T > > const_iterator;
            typedef ptrdiff_t difference_type;
            typedef unsigned long size_type;

        private :
            value_type *arr;
            size_type vecSize;
            size_type vecCapacity;
            allocator_type m_allocator;

        public :
            //-------------CONSTRUCTORS-------------
            explicit vector( const allocator_type& alloc = allocator_type() ) : arr(NULL), vecSize(0), vecCapacity(0), m_allocator(alloc) {}
            explicit vector( size_type n, const value_type &val = value_type(), const allocator_type& alloc = allocator_type())
            {
                arr = NULL;
                vecSize = 0;
                vecCapacity = 0;
                m_allocator = alloc;
                reserve(n);
                while (vecSize != n)
                    push_back(val);
            }
            template< class iterator >
            vector( iterator begin, iterator end, const allocator_type& alloc = allocator_type())
            {
                difference_type distance = end - begin;

                arr = NULL;
                vecSize = 0;
                vecCapacity = 0;
                m_allocator = alloc;
                reserve(distance);
                for (difference_type i = 0; i < distance; i++)
                {
                    m_allocator.construct(&arr[i], *begin);
                    vecSize++;
                    begin++;
                }
            }
            vector ( const vector &rhs )
            {
                arr = NULL;
                vecSize = 0;
                vecCapacity = 0;
                m_allocator = allocator_type();
                *this = rhs;
            }
            vector &operator=( const vector &rhs )
            {
                if (this == &rhs || (arr == NULL && rhs.data() == NULL))
                    return *this;
                if (arr == NULL && rhs.data())
                {
                    reserve(rhs.size());
                    for (size_type i = 0; i < rhs.size(); i++)
                        push_back(rhs[i]);
                }
                else if (arr && rhs.data() == NULL)
                {
                    while (vecSize != 0)
                        pop_back();
                    m_allocator.deallocate(arr, vecCapacity);
                    vecCapacity = 0;
                    arr = NULL;
                }
                //another condition to add (if they are both !empty)
                return *this;
            }
            ~vector ( void )
            {
                if (arr)
                {
                    for (size_type i = 0; i < vecSize; i++)
                        m_allocator.destroy(&arr[i]);
                    m_allocator.deallocate(arr, vecCapacity);
                }
            }
            //-------------ITERATORS-------------
			iterator begin( void ) { return iterator(arr); }
			const iterator begin( void ) const { return iterator(arr); }
			iterator end( void ) { return iterator(arr + vecSize); }
			const iterator end( void ) const { return iterator(arr + vecSize); }

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