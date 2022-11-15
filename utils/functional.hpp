#pragma once

namespace ft
{
    template < class T >
    struct less
    {
        bool operator()( const T &lhs, const T &rhs )
        {
            return lhs < rhs;
        }
    };
}