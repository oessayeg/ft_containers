#pragma once

#include "utils/utility.hpp"
#include <memory>
#include <functional>

namespace ft
{
	template < class P >
	class avlTree
	{
		private :
			P data;
			avlTree *right;
			avlTree *left;
		
		public :
			avlTree( ) { }
			avlTree( P toInit ) : data(toInit), right(NULL), left(NULL) { }
			~avlTree( ) { }
	};

    template < class Key, class T, class Compare = std::less< Key >, class Allocator = std::allocator<ft::pair< const Key, T > > >
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
            size_type mapSize;
            avlTree *baseTree;
            allocator_type m_allocator;

        //---------------------PRIVATE MEMBER FUNCTIONS---------------------
        private :
            avlTree *createNode( const value_type &val )
            {
                avlTree *node;

                node = new avlTree;
                node->data = val;
                node->left = NULL;
                node->right = NULL;
                return node;
            }

            void insertRecursively( avlTree **root, const value_type &val )
            {
                if (*root == NULL)
                {
                    *root = createNode(val);
                    return ;
                }
            }

        //---------------------PUBLIC MEMBER FUNCTIONS---------------------
        public :
            map( ) : mapSize(0), baseTree(NULL) { }
            void insert( const value_type &val ) { insertRecursively(&baseTree, val); }
            ~map( ) { }
   };
}