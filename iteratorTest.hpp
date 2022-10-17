#pragma once

namespace ft
{
    template <class vector>
    class vectorIterator
    {
        public :
            typedef typename vector::value_type value_type;
            typedef typename vector::value_type* pointer;
            typedef typename vector::value_type& reference;

        private :
            pointer _myptr;

        public :
            vectorIterator(pointer p)
            {
                _myptr = p;
            }

            vectorIterator()
            {

            }

            value_type operator*( )
            {
                return *_myptr;
            }

            pointer operator + ( int idx )
            {
                return _myptr + idx;
            }
    };
};