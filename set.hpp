#pragma once

#include "utils/functional.hpp"
#include "utils/redBlackTree.hpp"
#include "utils/utility.hpp"
#include "set_iterator.hpp"

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
            typedef std::ptrdiff_t difference_type;
            typedef std::size_t size_type;
            //iterators typedefs here 
            typedef ft::set_iterator< value_type *, base< T, Alloc > >  iterator;
            typedef ft::set_iterator< const value_type *, base< T, Alloc > > const_iterator;
            typedef base< T, Alloc > bst;

        public :
            redBlackTree< value_type, value_compare, allocator_type > base;

        public :
            // ------------Constructors, '=' overload, Destructor------------
            explicit set( const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type() )
                : base(redBlackTree<value_type, value_compare, allocator_type>(alloc, comp)) { }

            template < class InputIterator >
            explicit set( InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
                const allocator_type &alloc = allocator_type() ) : base(redBlackTree<value_type, value_compare, allocator_type>(alloc, comp))
            {
                for (; first != last; first++)
                    insert(*first);
            }
            
            set( const set &rhs )
            {
                iterator b;
                iterator e;

                b = rhs.begin();
                e = rhs.end();
                for (; b != e; b++)
                    insert(*b);
            }

            // ------------Iterator Category------------
            iterator begin( void ) { return iterator(base.getRoot(), BEGIN); }
            const_iterator begin( void ) const { return const_iterator(base.getRoot(), BEGIN); }
            iterator end( void ) { return iterator(base.getRoot(), END); }
            const_iterator end( void ) const { return const_iterator(base.getRoot(), END); }

            // ------------Capacity Category------------
            bool empty( void ) { return base.size() == 0; }
            size_type size( void ) const { return base.size(); }
            size_type max_size( void ) const { return base.max(); }

            // ------------Modifiers Category------------
            ft::pair< iterator, bool > insert( const value_type &val )
            {
                bool is_inserted;

                is_inserted = base.insert(val);
                if (is_inserted)
                    return ft::make_pair(iterator(base.find(val)), is_inserted);
                return ft::make_pair(iterator(base.find(val)), false);
            }
            size_type erase( const value_type &val ) { return base.erase(val); }


            // ------------Operations Category------------
            iterator find( const value_type &val ) const
            {
                bst *found;

                found = base.find(val);
                if (found == NULL)
                    return iterator(base.getRoot(), END);
                return iterator(found);
            }
    };
};