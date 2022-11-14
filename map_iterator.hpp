#pragma once

#include "utils/iterator_traits.hpp"

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
            typedef iterator_category std::bidirectional_iterator_tag;
            typedef size_t size_type;
        
        private :
            value_type *m_root_ptr;
            value_type *m_ptr;

        public :

    };
}