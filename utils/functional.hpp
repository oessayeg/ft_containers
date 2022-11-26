#pragma once

namespace ft
{
    //--------Function Object To Compare 2 Objects (Map Use)--------
    template < class T >
    struct less
    {
        bool operator()( const T &lhs, const T &rhs ) const
        {
            return lhs < rhs;
        }
    };
}