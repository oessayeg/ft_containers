#pragma once

#include "utils/iterator_traits.hpp"
#include "utils/type_traits.hpp"
#include "utils/utility.hpp"
#include "utils/algorithm.hpp"

namespace ft
{
    template < class Iterator >
    class reverse_iterator : public vectorIterator< typename Iterator::pointer >
    {
        public :
            typedef Iterator iterator_type;
            typedef typename ft::iterator_traits< Iterator >::iterator_category iterator_category;
            typedef typename ft::iterator_traits< Iterator >::value_type value_type;
            typedef typename ft::iterator_traits< Iterator >::difference_type difference_type;
            typedef typename ft::iterator_traits< Iterator >::pointer pointer;
            typedef typename ft::iterator_traits< Iterator >::reference reference;

        protected :
            iterator_type baseIterator;

        public :
            reverse_iterator( void ) {};

            explicit reverse_iterator( iterator_type it ) : baseIterator(it) {}

            template < class iter >
            reverse_iterator ( const reverse_iterator< iter > &rhs ) : baseIterator(rhs.base()) {}

            reverse_iterator &operator=( const reverse_iterator &rhs )
            {
                if (this != &rhs)
                    baseIterator = rhs.base();
                return *this;
            }

            ~reverse_iterator( void ) {}

            // Base iterator
            iterator_type base() const { return baseIterator; }

            // Dereference operators
            reference operator*( void )
			{
				iterator_type tmp;
				
				tmp = baseIterator;
				return *--tmp;
			}
            pointer operator->( void )
            {
                iterator_type tmp;

                tmp = baseIterator;
                return &(*--tmp) ;
            }

            // Subscript operator
            reference operator[]( difference_type idx ) { return baseIterator[-idx - 1]; }

            // Addition - Substraction operators
            reverse_iterator operator+( difference_type n ) const
            {
                return reverse_iterator(baseIterator - n);
            }
            reverse_iterator operator-( difference_type n ) const
            {
                return reverse_iterator(baseIterator + n);
            }

            // Incrementation - Decrementation operators
            reverse_iterator &operator++( void )
            {
                --baseIterator;
                return *this;
            }
            reverse_iterator operator++( int )
            {
                reverse_iterator tmp = *this;

                --baseIterator;
                return tmp;
            }
            reverse_iterator &operator--( void )
            {
                ++baseIterator;
                return *this;
            }
            reverse_iterator operator--( int )
            {
                reverse_iterator tmp = *this;

                ++baseIterator;
                return tmp;
            }

            // Compound assignment operator
            reverse_iterator operator+=( difference_type n )
            {
                baseIterator -= n;
                return *this;
            }
            reverse_iterator operator-=( difference_type n )
            {
                baseIterator += n;
                return *this;
            }
    };

    template < class iterator >
    reverse_iterator< iterator > operator+( typename reverse_iterator< iterator >::difference_type n, const reverse_iterator< iterator > &rev_it )
    {
        return reverse_iterator< iterator >(rev_it.base() - n);
    }

    template < class iterator1, class iterator2 >
    typename reverse_iterator< iterator1 >::difference_type operator-( const reverse_iterator< iterator1 > &lhs, const reverse_iterator< iterator2 > &rhs )
    {
        return rhs.base() - lhs.base();
    }
    
    //------------------RELATIONAL OPERATORS------------------
    template < class iter1, class iter2 >
    bool operator==( const reverse_iterator< iter1 > &lhs, const reverse_iterator< iter2 > &rhs )
    {
        return lhs.base() == rhs.base();
    }

    template < class iter1, class iter2 >
    bool operator!=( const reverse_iterator< iter1 > &lhs, const reverse_iterator< iter2 > &rhs )
    {
        return lhs.base() != rhs.base();
    }

    template < class iter1, class iter2 >
    bool operator<( const reverse_iterator< iter1 > &lhs, const reverse_iterator< iter2 > &rhs )
    {
        return lhs.base() > rhs.base();
    }

    template < class iter1, class iter2 >
    bool operator<=( const reverse_iterator< iter1 > &lhs, const reverse_iterator< iter2 > &rhs )
    {
        return lhs.base() >= rhs.base();
    }

    template < class iter1, class iter2 >
    bool operator>( const reverse_iterator< iter1 > &lhs, const reverse_iterator< iter2 > &rhs )
    {
        return lhs.base() < rhs.base();
    }

    template < class iter1, class iter2 >
    bool operator>=( const reverse_iterator< iter1 > &lhs, const reverse_iterator< iter2 > &rhs )
    {
        return lhs.base() <= rhs.base();
    }
}