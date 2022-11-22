#pragma once

#include <memory>
#include <queue>

#include "utils/utility.hpp"
#include "utils/tree.hpp"
#include "utils/functional.hpp"
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
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
            typedef map_iterator< value_type* > iterator;
            typedef map_iterator< const value_type* > const_iterator;
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

        //---------------------PUBLIC MEMBER FUNCTIONS---------------------
        public :
        	//---------------------Constructors, assignment overload, destructor---------------------
			explicit map( const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type() ) :
				baseTree(NULL), mapSize(0), m_allocator(alloc), comp(comp) { }

			template < class InputIterator >
			map ( InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type &alloc = allocator_type() )
			{
				baseTree = NULL;
				mapSize = 0;
				m_allocator = alloc;
				this->comp = comp;
				for (; first != last; first++)
					insert(value_type(first->first, first->second));
			}

			map ( const map &rhs )
			{
				baseTree = NULL;
				mapSize = 0;
				m_allocator = rhs.m_allocator;
				comp = rhs.comp;
				*this = rhs;
			}

			template < class iter >
			map &operator=( const map &rhs )
			{
				iter b, e;

				if (this != &rhs)
				{
					b = rhs.begin();
					e = rhs.end();
					for (; b != e; b++)
						insert(value_type(b->first, b->second));
				}
				return *this;
			}

            ~map( ) { }

			// Insert member function
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

        //---------------------ITERATORS---------------------
		iterator begin( void ) { return iterator(baseTree, BEGIN); }
		const_iterator begin( void ) const { return const_iterator(baseTree, BEGIN); }
		iterator end( void ) { return iterator(baseTree, END); }
		const_iterator end( void ) const { return const_iterator(baseTree, END); }

        //---------------------PRIVATE MEMBER FUNCTIONS---------------------
        private :
            avlTree *createNode( const value_type &val, avlTree *parent )
			{
				return new avlTree(val, parent);
			}

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
				leftRoot->parent = root->parent;
				root->parent = leftRoot;
				root->left = rightOfLeftRoot;
				if (rightOfLeftRoot)
					rightOfLeftRoot->parent = root;
				return leftRoot;
			}

			avlTree *leftRotation( avlTree *root )
			{
				avlTree *rightRoot = root->right;
				avlTree *leftOfRightRoot = rightRoot->left;

				rightRoot->left = root;
				rightRoot->parent = root->parent;
				root->parent = rightRoot;
				root->right = leftOfRightRoot;
				if (leftOfRightRoot)
					leftOfRightRoot->parent = root;
				return rightRoot;
			}

            void insertRecursively( avlTree **root, const value_type &val )
            {
				int balanceFactor = 0;

                if (*root == NULL)
                {
                    *root = createNode(val, NULL);
                    return ;
                }
				if(comp(val.first, (*root)->data.first) && (*root)->left == NULL)
					(*root)->left = createNode(val, *root);
				else if (comp((*root)->data.first, val.first) && (*root)->right == NULL)
					(*root)->right = createNode(val, *root);
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

   };
}