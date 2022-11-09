#pragma once

namespace ft
{
    //------------PAIR STRUCT------------
    template < class F, class S >
    struct pair
    {
        public :
            F first;
            S second;

        public :
            pair() : first(), second() {}
            pair ( const F &a, const S &b )
            {
                first = a;
                second = b;
            }
            template < class T1, class T2 >
            pair ( const pair < T1, T2 > &rhs )
            {
                first = rhs.first;
                second = rhs.second;
            }
            pair &operator=( const pair &rhs )
            {
                if (this != &rhs)
                {
                    first = rhs.first;
                    second = rhs.second;
                }
                return *this;
            }
            ~pair() {}
    };

    template < class T1, class T2 >
    bool operator==( pair< T1, T2 > const &lhs, pair< T1, T2 > const &rhs )
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    template < class T1, class T2 >
    bool operator!=( pair< T1, T2 > const &lhs, pair< T1, T2 > const &rhs )
    {
        return !(lhs == rhs);
    }

    template < class T1, class T2 >
    bool operator<( pair< T1, T2 > const &lhs, pair< T1, T2 > const &rhs )
    {
        return lhs.first < rhs.first || (!(lhs.first > rhs.first) && lhs.second < rhs.second);
    }

    template < class T1, class T2 >
    bool operator<=( pair< T1, T2 > const &lhs, pair< T1, T2 > const &rhs )
    {
        return !(lhs > rhs);
    }

    template < class T1, class T2 >
    bool operator>( pair< T1, T2 > const &lhs, pair< T1, T2 > const &rhs )
    {
        return lhs.first > rhs.first || (!(lhs.first < rhs.first) && lhs.second > rhs.second);
    }

    template < class T1, class T2 >
    bool operator>=( pair< T1, T2 > const &lhs, pair< T1, T2 > const &rhs )
    {
        return !(lhs < rhs);
    }

    // ------------MAKE_PAIR------------
    template < class T1, class T2 >
    pair< T1, T2 > make_pair( T1 a, T2 b )
    {
        return pair< T1, T2 >( a, b );
    }
}