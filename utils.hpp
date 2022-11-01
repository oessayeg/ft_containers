#pragma once

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

    template < class T, class U >
    struct is_same
    {
	    static const bool value = false;
    };

    template<class T>
    struct is_same<T, T>
    {
	    static const bool value = true;
    };
}