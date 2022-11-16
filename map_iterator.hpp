#pragma once

#include "utils/iterator_traits.hpp"
#include "utils/tree.hpp"

namespace ft
{
    template < class T >
    class map_iterator
    {
        public :
            typedef typename ft::iterator_traits< T >::value_type value_type;
            typedef typename ft::iterator_traits< T >::difference_type difference_type;
            typedef typename ft::iterator_traits< T >::pointer pointer;
            typedef typename ft::iterator_traits< T >::reference reference;
            typedef std::bidirectional_iterator_tag iterator_category;
            typedef size_t size_type;

        private :
            value_type *m_ptr;

        public :
            map_iterator( value_type *ptr = NULL ) : m_ptr(ptr) { }
            ~map_iterator( ) { }
    };
}