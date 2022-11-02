#ifndef REIMPLEMENTATIONITERATOR_HPP
# define REIMPLEMENTATIONITERATOR_HPP

#include "utils.hpp"

namespace ft
{
    template < class Iterator >
    class vectorIterator
    {
        public :
            typedef typename ft::iterator_traits< Iterator >::iterator_category iterator_category;
            typedef typename ft::iterator_traits< Iterator >::value_type value_type;
            typedef typename ft::iterator_traits< Iterator >::difference_type difference_type;
            typedef typename ft::iterator_traits< Iterator >::pointer pointer;
            typedef typename ft::iterator_traits< Iterator >::reference reference;
            typedef size_t size_type;

        private :
            value_type* m_ptr;
        
        public :
            // Constructors, Destructor, assignment operator overload
            vectorIterator( value_type* p = NULL ) : m_ptr(p) {}

            template < class Iter >
            vectorIterator( const vectorIterator < Iter > &rhs, typename ft::enable_if< ft::is_convertible< Iterator, Iter >::value >::type* = 0 ) : m_ptr(rhs.getPtr()) {}

            vectorIterator &operator=( const vectorIterator &rhs )
            {
                m_ptr = rhs.getPtr();
                return *this;
            }

            ~vectorIterator() {}

            // Equivalence comparison operator
            template < class iter >
            bool operator==( const vectorIterator< iter > &rhs ) { return m_ptr == rhs.getPtr(); }
            template < class iter >
            bool operator!=( const vectorIterator< iter > &rhs ) { return m_ptr != rhs.getPtr(); }

            // Inequality relational operators
            template < class iter >
            bool operator<( const vectorIterator< iter > &rhs ) { return m_ptr < rhs.getPtr(); }
            template < class iter >
            bool operator>( const vectorIterator< iter > &rhs ) { return m_ptr > rhs.getPtr(); }
            template < class iter >
            bool operator<=( const vectorIterator< iter > &rhs ) { return m_ptr <= rhs.getPtr(); }
            template < class iter >
            bool operator>=( const vectorIterator< iter > &rhs ) { return m_ptr >= rhs.getPtr(); }

            // Dereferencing operators
            reference operator*( void ) { return *m_ptr; }
            pointer operator->( void ) { return m_ptr; }

            // Incrementation/Decrementation operators
            vectorIterator operator++( void )
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
            vectorIterator operator--( void )
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
            vectorIterator operator+( difference_type n ){ return vectorIterator(m_ptr + n); }
            vectorIterator operator-( difference_type n ){ return vectorIterator(m_ptr - n); }
            difference_type operator-( const vectorIterator &rhs ){ return m_ptr - rhs.getPtr(); }
            
            // Compound assignment operator
            vectorIterator operator+=( difference_type n )
            {
                m_ptr += n;
                return m_ptr;
            }
            vectorIterator operator-=( difference_type n )
            {
                m_ptr -= n;
                return m_ptr;
            }

            // Subscript operator (offset dereference)
            reference operator[]( difference_type idx ) { return *(m_ptr + idx); }

            // Base pointer getter
            value_type* getPtr( void ) const { return m_ptr; }
            
    };
        template < class I >
        vectorIterator< I > operator+( typename vectorIterator< I >::difference_type n, vectorIterator< I > &rhs )
        {
            return vectorIterator< I >(rhs.getPtr() + n);
        }
}

#endif