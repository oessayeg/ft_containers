#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
    template< class T >
    class vectorIterator
    {
        public :
            typedef T value_type;
            typedef T* pointer;
            typedef T& reference;
            typedef const T& const_reference;
            typedef const T* const_pointer;
            typedef ptrdiff_t difference_type;
            typedef unsigned long size_type;

        private :
            pointer data;

        public :
            // Constructors, copy assignment operator, destructor
            vectorIterator( void ) : data(NULL) {};
            vectorIterator( pointer p ) : data(p) {}
            vectorIterator( vectorIterator const &rhs ) : data(NULL) { *this = rhs; }
            vectorIterator &operator=( vectorIterator const &rhs )
            {
                if (this != &rhs)
                    data = rhs.getData();
                return *this;
            }
            ~vectorIterator( void ) { }

            //Get data ptr
            pointer getData( void ) const { return data; }

            //Dereference
            reference operator*( void ) { return *data; }
            const_reference operator*( void ) const { return *data; }
            pointer operator->( void ) { return data; }

            //test
            bool operator==( const vectorIterator &rhs )
            {
                return data == rhs.getData();
            }
            //test

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
            value_type operator[]( size_type idx ) { return *(data + idx); }

            //Comparison operator
            // bool operator<( vectorIterator const &rhs ) { return data < rhs.getData(); }
            // bool operator>( vectorIterator const &rhs ) { return data > rhs.getData(); }
            // bool operator<=( vectorIterator const &rhs ) { return data <= rhs.getData(); }
            // bool operator>=( vectorIterator const &rhs ) { return data >= rhs.getData(); }

            //Compound assignment operator
            // vectorIterator &operator+=( int n )
            // {
            //     data += n;
            //     return *this;
            // }

            // vectorIterator &operator-=( int n )
            // {
            //     data -= n;
            //     return *this;
            // }
    };
            // //'+' Operator
            // template < class T >
            // vectorIterator< T > operator+( int n, vectorIterator<T> &rhs )
            // {
            //     return vectorIterator<T>(rhs.getData() + n);
            // }

            //'==' Operator
            template < class T >
            bool operator==( const vectorIterator<T> &lhs, const vectorIterator<T> &rhs )
            {
                return lhs.getData() == rhs.getData();
            }

            //'!=' Operator
            template < class T >
            bool operator!=( const vectorIterator<T> &lhs, const vectorIterator<T> &rhs )
            {
                return lhs.getData() != rhs.getData();
            }

            //'+' Operator
            template < class T >
            vectorIterator< T > operator+( int lhs, vectorIterator< T > const & rhs )
            {
                return vectorIterator< T >(rhs.getData() + lhs);
            }

            template < class T >
            vectorIterator< T > operator+( vectorIterator< T > const & lhs, int rhs )
            {
                return vectorIterator< T >(lhs.getData() + rhs);
            }

            template < class T >
            vectorIterator< T > operator-( vectorIterator< T > const &lhs, vectorIterator< T > const &rhs )
            {
                return vectorIterator< T >(lhs.getData() - rhs.getData());
            }
}

#endif