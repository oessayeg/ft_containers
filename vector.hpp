#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include <limits>
#include "reimplementationIterator.hpp"
#include "utils.hpp"
#include <typeinfo>
#include <iterator>

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
			typedef vectorIterator< T* > iterator;
			typedef vectorIterator< const T* > const_iterator;
            typedef ptrdiff_t difference_type;
            typedef size_t size_type;

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
            vector( iterator begin, iterator end, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if< !std::is_integral< iterator >::value >::type* = 0 )
            {
                difference_type distance;
				
				distance = ft::iterDistance(begin, end);
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
                else
                {
                    while (vecSize != 0)
                        pop_back();
                    reserve(rhs.size());
                    for (size_type i = 0; i < rhs.size(); i++)
                        push_back(rhs[i]);
                }
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
			const_iterator begin( void ) const { return const_iterator(arr); }
			iterator end( void ) { return iterator(arr + vecSize); }
			const_iterator end( void ) const { return const_iterator(arr + vecSize); }

            //-------------CAPACITY-------------
            //Size of vector (member function)
            size_type size( void ) const { return vecSize; }

            //Max_size member function (max size to allocate)
            size_type max_size( void ) const { return m_allocator.max_size(); }

            //Resize member function
            void resize( size_type n, value_type val = value_type() )
            {
				if (n == vecSize)
					return ;
                else if (n < vecSize)
                    while (vecSize != n)
                        pop_back();
                else if (n > vecSize && n <= vecCapacity * 2)
                    while (vecSize != n)
                        push_back(val);
				else
				{
					reserve(n);
					while (vecSize != n)
						push_back(val);
				}
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
				else if (vecSize == 0 && n > vecCapacity)
				{
					if (vecCapacity == 0)
						arr = m_allocator.allocate(n);
					else if (vecCapacity > 0)
					{
						m_allocator.deallocate(arr, vecCapacity);
						arr = m_allocator.allocate(n);
					}
					vecCapacity = n;
				}
                else if (n > vecCapacity && vecSize > 0)
                {
                    pointer tmp = arr;

                    arr = m_allocator.allocate(n);
                    for (size_type i = 0; i < vecSize; i++)
					{
						m_allocator.construct(&arr[i], tmp[i]);
						m_allocator.destroy(&tmp[i]);
					}
                    m_allocator.deallocate(tmp, vecCapacity);
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
                if ( idx >= vecSize )
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
            //Assign member function
            void assign ( size_type n, const value_type &val )
            {
				if (n == 0)
					while (vecSize != 0)
						pop_back();
                else if (n <= vecCapacity)
            	{
                    for (size_type i = 0; i < vecCapacity; i++)
                    {
						if (i < vecSize)
                        	m_allocator.destroy(&arr[i]);
                        if (i < n)
                            m_allocator.construct(&arr[i], val);
						if (i >= n && i >= vecSize)
							break;
                    }
                    vecSize = n;
                }
                else
                {
					resize(0);
					reserve(n);
					while (vecSize != n)
						push_back(val);
                }
            }
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last,
			typename ft::enable_if< !std::is_integral<InputIterator>::value >::type* = 0 )
			{
				clear();
				for (; first != last; first++)
					push_back(*first);
			}

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
					{
						m_allocator.construct(&arr[i], tmp[i]);
						m_allocator.destroy(&tmp[i]);
					}
                    m_allocator.deallocate(tmp, vecCapacity);
                    vecCapacity *= 2;
                }
				m_allocator.construct(&arr[vecSize], val);
                vecSize++;
            }

            //Pop_back member function    
            void pop_back( void )
            {
                m_allocator.destroy( &arr[vecSize - 1] );
                vecSize--;
            }

			// Insert member function
			iterator insert( iterator position, const value_type &val )
			{
				iterator e;

				e = end();
				if (arr == NULL)
				{
					if (position == begin() && position == end())
					{
						reserve(1);
						push_back(val);
					}
					return begin();
				}
				if (vecSize < vecCapacity)
				{
					while (e != position)
					{
						m_allocator.construct(&(*e), *(e - 1));
						m_allocator.destroy(&(*(e - 1)));
						e--;
					}
					*position = val;
					m_allocator.construct(&(*position), val);
					vecSize += 1;
				}
				else
				{
					difference_type diff = position - begin();
					reserve(vecCapacity * 2);
					return insert(begin() + diff, val);
				}
				return position;
			}
			
			void insert( iterator position, size_type n, const value_type &val )
			{
				if (n + vecSize <= vecCapacity)
				{
					vector<value_type> tmp;
					iterator tmpIter;

					tmp.reserve(end() - position);
					for (tmpIter = position; tmpIter < end(); tmpIter++)
					{
						tmp.push_back(*tmpIter);
						m_allocator.destroy(&(*tmpIter));
					}
					vecSize = (position - begin());
					for (size_type i = 0; i < n; i++)
						push_back(val);
					for (iterator b = tmp.begin(); b != tmp.end(); b++)
						push_back(*b);
				}
				else
				{
					difference_type diff = position - begin();
					if (vecCapacity * 2 >= n + vecSize)
						reserve(vecCapacity * 2);
					else
						reserve(vecSize + n);
					insert(begin() + diff, n, val);
				}
			}

			template <class InputIterator>
			void insert( iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if< !std::is_integral<InputIterator>::value >::type* = 0 )
			{
				difference_type distance = 0;
				vector<value_type> tmp;
				vector<value_type> lastValVector;

				for (; first != last; first++)
				{
					distance++;
					tmp.push_back(*first);
				}
				if (distance + vecSize > vecCapacity)
				{
					difference_type diff = position - begin();

					if (distance + vecSize <= vecCapacity * 2)
						reserve(vecCapacity * 2);
					else
						reserve(vecSize + distance);
					position = begin() + diff;
				}
				lastValVector.reserve(end() - position);
				for (iterator b = position; b != end(); b++)
				{
					lastValVector.push_back(*b);
					m_allocator.destroy(&(*b));
				}
				vecSize = position - begin();
				for (iterator b = tmp.begin(); b != tmp.end(); b++)
					push_back(*b);
				for (iterator b = lastValVector.begin(); b != lastValVector.end(); b++)
					push_back(*b);
			}

			//Erase member function
			iterator erase( iterator position )
			{
				iterator ret = position;

				m_allocator.destroy(&(*position));
				++position;
				for (; position != end(); position++)
				{
					m_allocator.construct(&(*(position - 1)), *position);
					m_allocator.destroy(&(*position));
				}
				vecSize -= 1;
				return ret;
			}

			iterator erase ( iterator first, iterator last )
			{
				iterator tmp = first;
				difference_type toRemove = last - first;

				if (first == last)
					return first;
				for (; tmp != last; tmp++)
					m_allocator.destroy(&(*tmp));
				tmp = first;
				for (; last != end(); last++)
				{
					m_allocator.construct(&(*tmp), *last);
					m_allocator.destroy(&(*last));
					tmp++;
				}
				vecSize -= toRemove;
				return first;
			}

			//Swap member function
			void swap( vector &x ) { std::swap(*this, x); }

            //Clear member function    
            void clear( void )
            {
                while (vecSize > 0)
                    pop_back();
            }

            //-------------ALLOCATOR-------------
            allocator_type get_allocator( void ) const { return m_allocator; }
            
    };
 			       //-------------Non member functions-------------
		template < class T, class allocator >
		void swap( vector< T, allocator >& x, vector< T, allocator >& y ) { x.swap(y); }

            		//-------------RELATIONAL OPERATORS-------------
		template< class T, class allocator >
		bool operator==( vector< T, allocator > const &lhs, vector< T, allocator > const &rhs )
		{
			if (lhs.size() == rhs.size())
			{
				for (size_t i = 0; i < lhs.size(); i++)
					if (lhs.data()[i] != rhs.data()[i])
						return false;
				return true;
			}
			return false;
		}

		template< class T, class allocator >
		bool operator!=( vector< T, allocator > const &lhs, vector< T, allocator > const &rhs )
		{
			return !(lhs == rhs);
		}

		template< class T, class allocator >
		bool operator<( vector< T, allocator > const &lhs, vector< T, allocator > const &rhs)
		{
			size_t i = 0;

			if (lhs.size() == 0 && rhs.size() > 0)
				return true;
			else if (rhs.size() == 0 && lhs.size() > 0)
				return false;
			while (i < lhs.size() && i < rhs.size())
			{
				if (lhs.data()[i] < rhs.data()[i])
					return true;
				else if (lhs.data()[i] == rhs.data()[i])
					i++;
				else
					return false;
			}
			if (lhs.size() < rhs.size())
				return true;
			return false;
		}

		template< class T, class allocator >
		bool operator<=( vector< T, allocator > const &lhs, vector< T, allocator > const &rhs)
		{
			return !(lhs > rhs);
		}

		template< class T, class allocator >
		bool operator>( vector< T, allocator > const &lhs, vector< T, allocator > const &rhs)
		{
			size_t i = 0;

			if (lhs.size() == 0 && rhs.size() > 0)
				return false;
			else if (rhs.size() == 0 && lhs.size() > 0)
				return true;
			while (i < lhs.size() && i < rhs.size())
			{
				if (lhs.data()[i] > rhs.data()[i])
					return true;
				else if (lhs.data()[i] == rhs.data()[i])
					i++;
				else
					return false;
			}
			if (lhs.size() > rhs.size())
				return true;
			return false;
		}

		template< class T, class allocator >
		bool operator>=( vector< T, allocator > const &lhs, vector< T, allocator > const &rhs)
		{
			return !(lhs < rhs);
		}
}

#endif