#pragma once

namespace ft
{
    //------------Enable_if------------
    template < bool B, class T = void >
    struct enable_if {} ;

    template < class T >
    struct enable_if< true, T >
    {
        typedef T type;
    };

    //------------Const to non-const Check------------
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

    //------------Is_integral------------
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

    //------------Struct to check if type entered is char------------
    template < class T >
    struct is_char
    {
        static const bool value = false;
    };

    template <>
    struct is_char < char >
    {
        static const bool value = true;
    };

    template <>
    struct is_char < const char >
    {
        static const bool value = true;
    };

    template <>
    struct is_char < unsigned char >
    {
        static const bool value = true;
    };

}