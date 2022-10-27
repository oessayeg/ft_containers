#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
    template< class T >
    class vectorIterator
    {
        public :
            typedef typename ft::iterator_traits< T * >::iterator_category iterator_category;
            typedef typename ft::iterator_traits< T * >::value_type value_type;
            typedef typename ft::iterator_traits< T * >::difference_type difference_type;
            typedef typename ft::iterator_traits< T * >::pointer pointer;
            typedef typename ft::iterator_traits< T * >::reference reference;
            typedef unsigned long size_type;

        private :
            pointer data;

        public :
            // Constructors, Copy assignment operator, Destructor
            // vectorIterator( void ) : data(NULL) {};
            vectorIterator( pointer p = NULL ) : data(p) {}
            vectorIterator( const vectorIterator< T > &rhs ) : data(NULL) { *this = rhs; }
            vectorIterator< T > &operator=( const vectorIterator< T > &rhs )
            {
                if (this != &rhs)
                    data = rhs.getData();
                return *this;
            }
            ~vectorIterator( void ) { }

            //Equivalence comparison
            bool operator==( const vectorIterator &rhs ) { return data == rhs.getData(); }
            bool operator!=( const vectorIterator &rhs ) { return data != rhs.getData(); }

            //Get data ptr
            pointer getData( void ) const { return data; }

            //Dereference (add const return)
            reference operator*( void ) { return *data; }
            pointer operator->( void ) { return data; }

            //Increment
            pointer operator++( void )
            {
                data += 1;
                return data;
            }
            pointer operator++( int )
            {
                pointer tmp = data;

                ++data;
                return tmp;
            }

            //Decrement
            pointer operator--( void )
            {
                data -= 1;
                return data;
            }

            pointer operator--( int )
            {
                pointer tmp = data;

                --data;
                return tmp;
            }

            //Subscript operator
            reference operator[]( difference_type idx ) { return *(data + idx); }

            //Arithmetic operators
            pointer operator+( const int rhs ) { return data + rhs; }
            pointer operator-( const int rhs ) { return data - rhs; }
            difference_type operator-( const vectorIterator &rhs ) { return data - rhs.getData(); }

            //Relational operators
            bool operator<( const vectorIterator &rhs ) { return data < rhs.getData(); }
            bool operator>( const vectorIterator &rhs ) { return data > rhs.getData(); }
            bool operator<=( const vectorIterator &rhs ) { return data <= rhs.getData(); }
            bool operator>=( const vectorIterator &rhs ) { return data >= rhs.getData(); }

            //Compound assignment operator
            vectorIterator operator+=( const int &rhs )
            {
                data += rhs;
                return *this;
            }

            vectorIterator operator-=( const int &rhs )
            {
                data -= rhs;
                return *this;
            }
    };

        template < class T >
        typename vectorIterator< T >::pointer operator+( int const lhs, vectorIterator< T > const &rhs )
        {
            return rhs.getData() + lhs;
        }
}

#endif