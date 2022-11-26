#pragma once

namespace ft
{
    //------------Distance Between Iterators------------
    template < class iterator >
    typename iterator_traits< iterator >::difference_type distance( iterator a, iterator b, std::random_access_iterator_tag )
    {
        return b - a;
    }

    template < class iterator >
    typename iterator_traits< iterator >::difference_type distance( iterator a, iterator b, std::input_iterator_tag )
    {
        typename iterator_traits< iterator >::difference_type dist = 0;
        
        for (; a != b; a++)
            dist++;
        return dist;
    }

    template < class iterator >
    typename iterator_traits< iterator >::difference_type iterDistance( iterator a, iterator b )
    {
        return distance(a, b, typename ft::iterator_traits< iterator >::iterator_category());
    }

    //------------Lexicographical Compare------------
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

    //------------Equal------------
    template < class inputIterator >
    bool equal( inputIterator first1, inputIterator last1, inputIterator first2 )
    {
		for (; first1 != last1; first1++ )
		{
			if (*first1 != *first2)
				return false;
			first2++;
		}
		return true;
    }  
}