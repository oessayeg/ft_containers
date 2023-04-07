#pragma once

#include "../vector/vector.hpp"

namespace ft
{
	template < class T, class container = ft::vector< T > >
	class stack
	{
		//-----------------Stack Member Types-----------------
		public :
			typedef container container_type;
			typedef typename container::value_type value_type;
			typedef typename container::size_type size_type;
			typedef typename container::reference reference;
			typedef typename container::const_reference const_reference;

		protected :
			container_type ctr;
		
		public :
			//-----------------Constructors, Assignment Operator overload, Destructor-----------------
			explicit stack ( const container_type &ctnr = container_type() ) : ctr(ctnr) {}
			stack ( const stack &rhs ) { *this = rhs; }
			stack &operator=( const stack &rhs )
			{
				if (this != &rhs)
					ctr = rhs.ctr;
				return *this;
			}
			~stack() {}

			//-----------------Stack Member Functions-----------------
			bool empty ( void ) const { return ctr.empty(); }
			size_type size( void ) const{ return ctr.size(); }
			reference top( void ) { return ctr.back(); }
			const_reference top( void ) const { return ctr.back(); }
			void push( const value_type &val ) { ctr.push_back(val); }
			void pop( void ) { ctr.pop_back(); }

			// Comparison Operators
			template < class D, class C >
			friend bool operator==( stack< D, C > const &lhs, stack< D, C > const &rhs );

			template < class D, class C >
			friend bool operator!=( stack< D, C > const &lhs, stack< D, C > const &rhs );

			template < class D, class C >
			friend bool operator<( stack< D, C > const &lhs, stack< D, C > const &rhs );

			template < class D, class C >
			friend bool operator<=( stack< D, C > const &lhs, stack< D, C > const &rhs );

			template < class D, class C >
			friend bool operator>( stack< D, C > const &lhs, stack< D, C > const &rhs );

			template < class D, class C >
			friend bool operator>=( stack< D, C > const &lhs, stack< D, C > const &rhs );
	};

		// Implementation of the comparison operators
		template < class D, class C >
		bool operator==( stack< D, C > const &lhs, stack< D, C > const &rhs )
		{
			return lhs.ctr == rhs.ctr;
		}
		
		template < class D, class C >
		bool operator!=( stack< D, C > const &lhs, stack< D, C > const &rhs )
		{
			return lhs.ctr != rhs.ctr;
		}

		template < class D, class C >
		bool operator<( stack< D, C > const &lhs, stack< D, C > const &rhs )
		{
			return (lhs.ctr < rhs.ctr);
		}

		template < class D, class C >
		bool operator<=( stack< D, C > const &lhs, stack< D, C > const &rhs )
		{
			return (lhs.ctr <= rhs.ctr);
		}

		template < class D, class C >
		bool operator>( stack< D, C > const &lhs, stack< D, C > const &rhs )
		{
			return (lhs.ctr > rhs.ctr);
		}

		template < class D, class C >
		bool operator>=( stack< D, C > const &lhs, stack< D, C > const &rhs )
		{
			return (lhs.ctr >= rhs.ctr);
		}
}