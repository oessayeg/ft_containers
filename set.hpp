#pragma once

#include <queue>
#include "utils/functional.hpp"

namespace ft
{
    template < class T, class Compare = ft::less< T >, class Alloc = std::allocator< T > >
    class set
    {
        private :
            redBlackTree base;
    };
};