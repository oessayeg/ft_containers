#pragma once

namespace ft
{
    //--------FUNCTION OBJECT TO COMPARE 2 OBJECTS (MAP USE)--------
    template < class T >
    struct less
    {
        bool operator()( const T &lhs, const T &rhs ) const
        {
            return lhs < rhs;
        }
    };
}