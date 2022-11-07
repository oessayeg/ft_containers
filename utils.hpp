#pragma once

#include <cstddef>
#include <iterator>

namespace ft
{
    //------------ENABLE_IF------------
    template < bool B, class T = void >
    struct enable_if {} ;

    template < class T >
    struct enable_if< true, T >
    {
        typedef T type;
    };
    
    //------------ITERATOR_TRAITS------------
    template < class Iter >
    struct iterator_traits
    {
        typedef typename Iter::difference_type difference_type;
        typedef typename Iter::value_type value_type;
        typedef typename Iter::pointer pointer;
        typedef typename Iter::reference reference;
        typedef typename Iter::iterator_category iterator_category;
    };

    template < class T >
    struct iterator_traits < T* >
    {
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template < class T >
    struct iterator_traits < const T* >
    {
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef const T* pointer;
        typedef const T& reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
    
    //------------DISTANCE BETWEEN ITERATORS------------
    template < class iterator >
    typename iterator_traits< iterator >::difference_type Distance( iterator a, iterator b, std::random_access_iterator_tag )
    {
        return b - a;
    }

    template < class iterator >
    typename iterator_traits< iterator >::difference_type Distance( iterator a, iterator b, std::input_iterator_tag )
    {
        typename iterator_traits< iterator >::difference_type dist = 0;
        
        for (; a != b; a++)
            dist++;
        return dist;
    }

    template < class iterator >
    typename iterator_traits< iterator >::difference_type iterDistance( iterator a, iterator b )
    {
        return Distance(a, b, typename ft::iterator_traits< iterator >::iterator_category());
    }

    //------------STRUCT TO CHECK IF 2 TYPES ARE CONVERTIBLE------------
    template < class T, class U >
    struct is_convertible
    {
        static const bool value = false;
    };

    template < class T >
    struct is_convertible< T* , T* >
    {
        static const bool value = true;
    };

    template < class T >
    struct is_convertible< const T *, const T * >
    {
        static const bool value = true;
    };

    template < class T, class U >
    struct is_convertible< const T *, U * >
    {
        static const bool value = true;
    };

    template < class T >
    struct is_convertible< T , T >
    {
        static const bool value = true;
    };

    template < class T >
    struct is_convertible< const T , const T  >
    {
        static const bool value = true;
    };

    template < class T, class U >
    struct is_convertible< const T , U >
    {
        static const bool value = true;
    };

    //------------LEXICOGRAPHICAL COMPARE------------
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    //------------IS_INTEGRAL------------

    template < class T >
    struct is_integral_t
    {
        static const bool value = false;
    };

    template <>
    struct is_integral_t< bool >
    {
        static const bool value = true;
    };

    template <>
    struct is_integral_t< char >
    {
        static const bool value = true;
    };

    template <>
    struct is_integral_t< wchar_t >
    {
        static const bool value = true;
    };

    template <>
    struct is_integral_t< signed char >
    {
        static const bool value = true;
    };

    template <>
    struct is_integral_t< short int >
    {
        static const bool value = true;
    };

    template <>
    struct is_integral_t< int >
    {
        static const bool value = true;
    };

    template <>
    struct is_integral_t< long int >
    {
        static const bool value = true;
    };

    template <>
    struct is_integral_t< long long int >
    {
        static const bool value = true;
    };

    template <>
    struct is_integral_t< unsigned char >
    {
        static const bool value = true;
    };

    template <>
    struct is_integral_t< unsigned short int >
    {
        static const bool value = true;
    };

    template <>
    struct is_integral_t< unsigned int >
    {
        static const bool value = true;
    };

    template <>
    struct is_integral_t< unsigned long int >
    {
        static const bool value = true;
    };

    template <>
    struct is_integral_t< unsigned long long int >
    {
        static const bool value = true;
    };

    template < class T >
    struct remove_const
    {
        typedef T type;
    };

    template < class T >
    struct remove_const< const T >
    {
        typedef T type;
    };

    template < class T >
    struct remove_volatile
    {
        typedef T type;
    };

    template < class T >
    struct remove_volatile < volatile T >
    {
        typedef T type;
    };

    template < class T >
    struct remove_const_volatile
    {
        typedef typename ft::remove_const< typename ft::remove_volatile < T >::type >::type type;
    };

    template < class T >
    struct is_integral
    {
        static const bool value =
        is_integral_t< typename ft::remove_const_volatile < T >::type >::value;
    };

}