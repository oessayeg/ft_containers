#pragma once

#include "utils/utility.hpp"
#include "utils/functional.hpp"
#include <memory>
#include <queue>

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

			size_type height( avlTree *root )
			{
				if (root == NULL)
					return 0;
				return (std::max(height(root->left), height(root->right)) + 1);
			}
			
			avlTree* rightRotation( avlTree *root )
			{
				avlTree *leftRoot = root->left;
				avlTree *rightOfLeftRoot = leftRoot->right;

				leftRoot->right = root;
				root->left = rightOfLeftRoot;
				return leftRoot;
			}

			avlTree *leftRotation( avlTree *root )
			{
				avlTree *rightRoot = root->right;
				avlTree *leftOfRightRoot = rightRoot->left;

				rightRoot->left = root;
				root->right = leftOfRightRoot;
				return rightRoot;
			}

            void insertRecursively( avlTree **root, const value_type &val )
            {
				int balanceFactor = 0;

                if (*root == NULL)
                {
                    *root = createNode(val);
                    return ;
                }
				if(comp(val.first, (*root)->data.first) && (*root)->left == NULL)
					(*root)->left = createNode(val);
				else if (comp((*root)->data.first, val.first) && (*root)->right == NULL)
					(*root)->right = createNode(val);
				else if (comp(val.first, (*root)->data.first) && (*root)->left)
					insertRecursively(&(*root)->left, val);
				else if (comp((*root)->data.first, val.first) && (*root)->right)
					insertRecursively(&(*root)->right, val);
				else
					return ;
				balanceFactor = height((*root)->left) - height((*root)->right);
				if (balanceFactor > 1 && comp(val.first, (*root)->left->data.first))
					(*root) = rightRotation(*root);
				else if (balanceFactor < -1 && comp((*root)->right->data.first, val.first))
					(*root) = leftRotation(*root);
				else if (balanceFactor > 1 && comp((*root)->left->data.first, val.first))
				{
					(*root)->left = leftRotation((*root)->left);
					(*root) = rightRotation(*root);
				}
				else if (balanceFactor < -1 && comp(val.first, (*root)->right->data.first))
				{
					(*root)->right = rightRotation((*root)->right);
					(*root) = leftRotation(*root);
				}
			}

        //---------------------PUBLIC MEMBER FUNCTIONS---------------------
        public :
            map( ) : baseTree(NULL), mapSize(0), m_allocator(allocator_type()), comp(key_compare()) { }
            void insert( const value_type &val ) { insertRecursively(&baseTree, val); }
			void print( void )
			{
				avlTree *tmp;
				std::queue< avlTree* > q;
				int nodes = 0;

				if (baseTree == NULL)
					return ;
				q.push(baseTree);
				while (!q.empty())
				{
					nodes = q.size();
					while (nodes > 0)
					{
						tmp = q.front();
						std::cout << "(" << tmp->data.first << " " << tmp->data.second << ")";
						q.pop();
						if (tmp->left)
							q.push(tmp->left);
						if (tmp->right)
							q.push(tmp->right);
						nodes--;
					}
					std::cout << std::endl;
				}
			}
            ~map( ) { }
   };
}