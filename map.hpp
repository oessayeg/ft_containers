#pragma once

#include "utils/utility.hpp"
#include "utils/functional.hpp"
#include <memory>

namespace ft
{
	template < class P >
	class avlTree
	{
		public :
			P data;
			avlTree *right;
			avlTree *left;
		
		public :
			avlTree( ) { }
			avlTree( P toInit ) : data(toInit), right(NULL), left(NULL) { }
			~avlTree( ) { }
	};

    template < class Key, class T, class Compare = ft::less< Key >, class Allocator = std::allocator<ft::pair< const Key, T > > >
    class map
    {
        //---------------------MEMBER TYPES---------------------
        public :
            typedef Key key_type;
            typedef T mapped_type;
            typedef ft::pair< const key_type, mapped_type > value_type;
            typedef Compare key_compare;
            typedef Allocator allocator_type;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;
            typedef avlTree< value_type > avlTree;
            //iterator
            //const_iterator
            //reverse_iterator
            //const_reverse_iterator
            typedef std::ptrdiff_t difference_type;
            typedef size_t size_type;

        //---------------------MEMBER ATTRIBUTES---------------------
        private :
            avlTree *baseTree;
            size_type mapSize;
            allocator_type m_allocator;
			key_compare comp;

        //---------------------PRIVATE MEMBER FUNCTIONS---------------------
        private :
            avlTree *createNode( const value_type &val ) { return new avlTree(val); }

            void insertRecursively( avlTree **root, const value_type &val )
            {
                if (*root == NULL)
                {
                    *root = createNode(val);
                    return ;
                }
				if (comp(val.first, (*root)->data.first))
					std::cout << "is lower" << std::endl;
				else
					std::cout << "is greater" << std::endl;
            }

        //---------------------PUBLIC MEMBER FUNCTIONS---------------------
        public :
            map( ) : baseTree(NULL), mapSize(0), m_allocator(allocator_type()), comp(key_compare()) { }
            void insert( const value_type &val ) { insertRecursively(&baseTree, val); }
            ~map( ) { }
   };
}