#pragma once

#include "utils/functional.hpp"
#include "utils/redBlackTree.hpp"

namespace ft
{
    template < class T, class Compare = ft::less< T >, class Alloc = std::allocator< T > >
    class set
    {
        // --------------Member Types--------------
        public :
            typedef T key_type;
            typedef T value_type;
            typedef Compare key_compare;
            typedef Compare value_compare;
            typedef Alloc allocator_type;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;
            typedef std::ptrdiff_t difference_type;
            typedef std::size_t size_type;
            //iterators typedefs here 

        private :
            redBlackTree< value_type, value_compare, allocator_type > base;

        public :
            // ------------Constructors, '=' overload, Destructor------------
            explicit set( const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type() )
                : base(redBlackTree<value_type, value_compare, allocator_type>(alloc, comp)) { }
    };
};