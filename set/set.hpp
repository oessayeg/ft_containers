#pragma once

#include "../utils/functional.hpp"
#include "../utils/redBlackTree.hpp"
#include "../utils/utility.hpp"
#include "set_iterator.hpp"
#include "../vector/vector.hpp"

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
            typedef ft::set_iterator< const value_type *, base< T, Alloc > >  iterator;
            typedef ft::set_iterator< const value_type *, base< T, Alloc > > const_iterator;
            typedef ft::reverse_iterator< iterator > reverse_iterator;
            typedef ft::reverse_iterator< const_iterator > const_reverse_iterator;
            typedef std::ptrdiff_t difference_type;
            typedef std::size_t size_type;
            typedef base< T, Alloc > bst;

        private :
            redBlackTree< value_type, value_compare, allocator_type > base;
            key_compare comp;
        
        public :
            // ------------Constructors, '=' overload, Destructor------------
            explicit set( const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type() )
                : base(redBlackTree<value_type, value_compare, allocator_type>(alloc, comp)), comp(comp) { }

            template < class InputIterator >
            explicit set( InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
                const allocator_type &alloc = allocator_type() ) : base(redBlackTree<value_type, value_compare, allocator_type>(alloc, comp)),
                comp(comp)
            {
                for (; first != last; first++)
                    insert(*first);
            }
            
            set( const set &x ) { *this = x; }

            set &operator=( const set &x )
            {
                iterator b;
                iterator e;

                base.clear();
                b = x.begin();
                e = x.end();
                for (; b != e; b++)
                    insert(*b);
                return *this;
            }

            // ------------Iterator Category------------
            iterator begin( void ) { return iterator(base.getRoot(), BEGIN); }
            const_iterator begin( void ) const { return const_iterator(base.getRoot(), BEGIN); }
            iterator end( void ) { return iterator(base.getRoot(), END); }
            const_iterator end( void ) const { return const_iterator(base.getRoot(), END); }

            reverse_iterator rbegin( void ) { return reverse_iterator(end()); }
            const_reverse_iterator rbegin( void ) const { return const_reverse_iterator(end()); }
            reverse_iterator rend( void ) { return reverse_iterator(begin()); }
            const_reverse_iterator rend( void ) const { return const_reverse_iterator(begin()); }

            // ------------Capacity Category------------
            bool empty( void ) const { return base.size() == 0; }
            size_type size( void ) const { return base.size(); }
            size_type max_size( void ) const { return base.max(); }

            // ------------Modifiers Category------------
            // Insert member function (key, hint, range)
            ft::pair< iterator, bool > insert( const value_type &val )
            {
                bool is_inserted;

                is_inserted = base.insert(val);
                if (is_inserted)
                    return ft::make_pair(iterator(base.find(val)), is_inserted);
                return ft::make_pair(iterator(base.find(val)), false);
            }

            iterator insert( iterator position, const value_type &val )
            {
                (void)position;
                return insert(val).first;
            }

            template < class InputIterator >
            void insert( InputIterator first, InputIterator last )
            {
                for (; first != last; first++)
                    insert(*first);
            }
            
            // Erase member function (hint, key, range)
            void erase( iterator position ) { base.erase(*position); }

            size_type erase( const value_type &val ) { return base.erase(val); }

            void erase ( iterator first, iterator last )
            {
                ft::vector< value_type > keys;

                for (; first != last; first++)
                    keys.push_back(*first);
                for (size_type i = 0; i < keys.size(); i++)
                    base.erase(keys[i]);
            }

            //Swap member function
            void swap( set &x ) { base.swap(x.base); }

            // Clear member function
            void clear( void ) { base.clear(); }

            // ------------Observers Category------------
            key_compare key_comp( void ) const { return comp; }
            value_compare value_comp( void ) const { return comp; }

            // ------------Operations Category------------
            // Find member function (get the iterator to the element)
            iterator find( const value_type &val ) const
            {
                bst *found;

                found = base.find(val);
                if (found == NULL)
                    return iterator(base.getRoot(), END);
                return iterator(found);
            }

            // Count member function
            size_type count( const value_type &val ) const { return !(base.find(val) == NULL); }

            iterator lower_bound( const value_type &val ) const
            {
                iterator b;
                iterator e;

                b = begin();
                e = end();
                for (; b != e; b++)
                    if (comp(*b, val) == false)
                        return b;
                return e;
            }

            iterator upper_bound( const value_type &val ) const
            {
                iterator b;
                iterator e;

                b = begin();
                e = end();
                for (; b != e; b++)
                    if (comp(val, *b))
                        return b;
                return e;
            }

            ft::pair< iterator, iterator > equal_range( const value_type &val ) const
            {
                return ft::make_pair(lower_bound(val), upper_bound(val));
            }

            // ------------Allocator Category------------
            allocator_type get_allocator( void ) const { return base.getAllocator(); }
    };

        // ------------Comparison Operators------------
        template < class Key, class Compare, class Alloc >
        bool operator==( const ft::set< Key, Compare, Alloc > &lhs, const set< Key, Compare, Alloc > &rhs )
        {
            typename ft::set< Key, Compare, Alloc >::iterator b1, e1, b2, e2;

            b1 = lhs.begin();
            e1 = lhs.end();
            b2 = rhs.begin();
            e2 = rhs.end();
            while (b1 != e1 && b2 != e2)
            {
                if (*b1 != *b2)
                    return false;
                b1++;
                b2++;
            }
            if (b1 == e1 && b2 == e2)
                return true;
            return false;
        }

        template < class Key, class Compare, class Alloc >
        bool operator!=( const ft::set< Key, Compare, Alloc > &lhs, const set< Key, Compare, Alloc > &rhs )
        {
            return !(lhs == rhs);
        }

        template < class Key, class Compare, class Alloc >
        bool operator<( const ft::set< Key, Compare, Alloc > &lhs, const set< Key, Compare, Alloc > &rhs )
        {
            typename ft::set< Key, Compare, Alloc >::iterator b1, e1, b2, e2;

            b1 = lhs.begin();
            e1 = lhs.end();
            b2 = rhs.begin();
            e2 = rhs.end();
            while (b1 != e1 && b2 != e2)
            {
                if (*b1 < *b2)
                    return true;
                else if (*b1 > *b2)
                    return false;
                b1++;
                b2++;
            }
            if (b1 == e1 && b2 != e2)
                return true;
            return false;
        }

        template < class Key, class Compare, class Alloc >
        bool operator<=( const ft::set< Key, Compare, Alloc > &lhs, const set< Key, Compare, Alloc > &rhs )
        {
            return !(lhs > rhs);
        }

        template < class Key, class Compare, class Alloc >
        bool operator>( const ft::set< Key, Compare, Alloc > &lhs, const set< Key, Compare, Alloc > &rhs )
        {
            return rhs < lhs;
        }

        template < class Key, class Compare, class Alloc >
        bool operator>=( const ft::set< Key, Compare, Alloc > &lhs, const set< Key, Compare, Alloc > &rhs )
        {
            return !(lhs < rhs);
        }

        // Non-member swap function
        template < class T, class Compare, class Alloc >
        void swap( set< T, Compare, Alloc > &x, set < T, Compare, Alloc > &y )
        {
            x.swap(y);
        }

};