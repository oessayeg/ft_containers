#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
    template< class vector >
    class vectorIterator
    {
        public :
            typedef typename vector::value_type value_type;
            typedef typename vector::pointer pointer;
            typedef typename vector::reference reference;
            typedef ptrdiff_t difference_type;
            typedef unsigned long size_type;

        private :
            pointer data;

        public :
            //Constructors
            vectorIterator( void ) : data(NULL) {};
            vectorIterator( pointer p ) : data(p) {}

            //Get data ptr
            pointer getData( void ) const { return data; } ;

            //Comparison operators
            bool operator==( const vectorIterator &rhs ) { return data == rhs.getData(); }
            bool operator!=( const vectorIterator &rhs ) { return !(data == rhs.getData()); }

            //Dereference
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

            //Arithmetic operators
            vectorIterator operator+( int n ) { return vectorIterator(data + n); }
            vectorIterator operator-( int n ) { return vectorIterator(data - n); }
            difference_type operator-( const vectorIterator &rhs ) { return data - rhs.getData(); }

            //Subscript operator
            value_type operator[]( size_type idx ) { return *(data + idx); }

            //Comparison operator
            bool operator<( vectorIterator &rhs ) { return data < rhs.getData(); }
            bool operator>( vectorIterator &rhs ) { return data > rhs.getData(); }
            bool operator<=( vectorIterator &rhs ) { return data <= rhs.getData(); }
            bool operator>=( vectorIterator &rhs ) { return data >= rhs.getData(); }

            //Compound assignment operator
            vectorIterator &operator+=( int n )
            {
                data += n;
                return *this;
            }

            vectorIterator &operator-=( int n )
            {
                data -= n;
                return *this;
            }
    };
            //'+' Operator
            template < class T >
            vectorIterator< T > operator+( int n, vectorIterator<T> &rhs )
            {
                return vectorIterator<T>(rhs.getData() + n);
            }
}

#endif