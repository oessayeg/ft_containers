#pragma once

#include "../utils/iterator_traits.hpp"
#include "../utils/type_traits.hpp"
#include "../utils/utility.hpp"
#include "../utils/algorithm.hpp"

namespace ft
{
	template < class Iterator >
	class vectorIterator
	{
		// ---------------------Iterator Member Types---------------------
		public :
			typedef typename ft::iterator_traits< Iterator >::iterator_category iterator_category;
			typedef typename ft::iterator_traits< Iterator >::value_type value_type;
			typedef typename ft::iterator_traits< Iterator >::difference_type difference_type;
			typedef typename ft::iterator_traits< Iterator >::pointer pointer;
			typedef typename ft::iterator_traits< Iterator >::reference reference;
			typedef size_t size_type;

		// ---------------------Base Pointer---------------------
		private :
			value_type* m_ptr;

		public :
			// Constructors, Assignment operator overload, Destructor
			vectorIterator( value_type* p = NULL ) : m_ptr(p) {}

			template < class Iter >
			vectorIterator( const vectorIterator < Iter > &rhs,
				typename ft::enable_if< ft::is_convertible< Iterator, Iter >::value >::type* = 0 ) : m_ptr(rhs.getPtr()) {}

			vectorIterator &operator=( const vectorIterator &rhs )
			{
				if (this != &rhs)
					m_ptr = rhs.getPtr();
				return *this;
			}

			~vectorIterator() {}

			// Equivalence Comparison operator
			template < class iter >
			bool operator==( const vectorIterator< iter > &rhs ) const { return m_ptr == rhs.getPtr(); }
			template < class iter >
			bool operator!=( const vectorIterator< iter > &rhs ) const { return m_ptr != rhs.getPtr(); }

			// Inequality Relational operators
			template < class iter >
			bool operator<( const vectorIterator< iter > &rhs ) const { return m_ptr < rhs.getPtr(); }
			template < class iter >
			bool operator>( const vectorIterator< iter > &rhs ) const { return m_ptr > rhs.getPtr(); }
			template < class iter >
			bool operator<=( const vectorIterator< iter > &rhs ) const { return m_ptr <= rhs.getPtr(); }
			template < class iter >
			bool operator>=( const vectorIterator< iter > &rhs ) const { return m_ptr >= rhs.getPtr(); }

			// Dereferencing operators (for const and non const iterators)
			reference operator*( void ) { return *m_ptr; }
			const reference operator*( void ) const { return *m_ptr; }
			pointer operator->( void ) { return m_ptr; }
			const pointer operator->( void ) const { return m_ptr; }

			// Incrementation/Decrementation operators
			vectorIterator &operator++( void )
			{
				++m_ptr;
				return *this;
			}
			vectorIterator operator++( int )
			{
				vectorIterator tmp = *this;

				++m_ptr;
				return tmp;
			}
			vectorIterator &operator--( void )
			{
				--m_ptr;
				return *this;
			}
			vectorIterator operator--( int )
			{
				vectorIterator tmp = *this;

				--m_ptr;
				return tmp;
			}

			// Arithmetic operators '+' and '-'
			vectorIterator operator+( difference_type n ) const { return vectorIterator(m_ptr + n); }
			vectorIterator operator-( difference_type n ) const { return vectorIterator(m_ptr - n); }
 
			// Compound assignment operator
			vectorIterator operator+=( difference_type n )
			{
				m_ptr += n;
				return *this;
			}
			vectorIterator operator-=( difference_type n )
			{
				m_ptr -= n;
				return *this;
			}

			// Subscript operator (offset dereference)
			reference operator[]( difference_type idx ) { return *(m_ptr + idx); }
			const reference operator[]( difference_type idx ) const { return *(m_ptr + idx); }

			// Base pointer getter
			value_type* getPtr( void ) const { return m_ptr; }
			
	};
		// Distance addition/substraction for vector_iterator
		template < class I >
		vectorIterator< I > operator+( typename vectorIterator< I >::difference_type n, vectorIterator< I > &rhs )
		{
			return vectorIterator< I >(rhs.getPtr() + n);
		}

		template < class T1, class T2 >
		typename vectorIterator< T1 >::difference_type operator-( vectorIterator< T1 > const &lhs,
			vectorIterator< T2 > const &rhs )
		{
			return lhs.getPtr() - rhs.getPtr();
		}
}