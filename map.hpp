#pragma once

#include <queue>
#include <iostream>

#include <memory>
#include "utils/utility.hpp"
#include "utils/tree.hpp"
#include "utils/functional.hpp"
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"
#include "vector.hpp"

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
            typedef ft::reverse_iterator< iterator > reverse_iterator;
            typedef ft::reverse_iterator< const_iterator > const_reverse_iterator;
            typedef std::ptrdiff_t difference_type;
            typedef size_t size_type;

        //---------------------PRIVATE MEMBER ATTRIBUTES---------------------
        private :
            avlTree *baseTree;
            size_type mapSize;
            allocator_type m_allocator;
			std::allocator< avlTree > avlAlloc;
			key_compare comp;

        //---------------------PUBLIC MEMBER ATTRIBUTE---------------------
		public :
			class value_compare
			{
				protected :
					Compare c;

				public :
					value_compare( Compare com ) : c(com) { }
					bool operator()( const value_type &lhs, const value_type &rhs ) const
					{
						return c(lhs.first, rhs.first);
					}
			};

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
				insert(first, last);
			}

			map ( const map &rhs )
			{
				baseTree = NULL;
				mapSize = 0;
				*this = rhs;
			}

			map &operator=( const map &rhs )
			{
				const_iterator b, e;

				if (this != &rhs)
				{
					freeAll(baseTree);
					mapSize = 0;
					baseTree = NULL;
					insert(rhs.begin(), rhs.end());
				}
				return *this;
			}

            ~map( ) { freeAll(baseTree); }

        	//---------------------Capacity member functions---------------------
			bool empty ( void ) const { return baseTree == NULL; }
			size_type size ( void ) const { return mapSize; }
			size_type max_size( void ) const { return m_allocator.max_size(); }

        	//---------------------Observers---------------------
			key_compare key_comp() const { return key_compare(); }
			value_compare value_comp() const { return value_compare(key_compare()); }

        	//---------------------Operations---------------------
			// Find member function (non-const and const)
			iterator find( const key_type &k )
			{
				avlTree *found;

				found = findKey(k, baseTree);
				if (found == NULL)
					return iterator(baseTree, END);
				return iterator(found);
			}
			const_iterator find( const key_type &k ) const
			{
				avlTree *found;

				found = findKey(k, baseTree);
				if (found == NULL)
					return const_iterator(baseTree, END);
				return const_iterator(found);
			}

			// Count member function
			size_type count ( const key_type &k ) const { return (findKey(k, baseTree) != NULL); }

			// Lower_bound member function (non-const and const)
			iterator lower_bound( const key_type &k )
			{
				iterator b;
				
				for (b = begin(); b != end(); b++)
					if (comp(b->first, k) == false)
						break;
				return b;
			}

			const_iterator lower_bound( const key_type &k ) const
			{
				const_iterator b;

				for (b = begin(); b != end(); b++)
					if (comp(b->first, k) == false)
						break;
				return b;
			}

			// Upper_bound member function (non-const and const)
			iterator upper_bound( const key_type &k )
			{
				iterator b;

				for (b = begin(); b != end(); b++)
					if (comp(k, b->first) == true)
						break;
				return b;
			}

			const_iterator upper_bound( const key_type &k ) const
			{
				const_iterator b;

				for (b = begin(); b != end(); b++)
					if (comp(k, b->first) == true)
						break;
				return b;
			}

			// Equal_range member function (non-const and const)
			ft::pair< iterator, iterator > equal_range( const key_type &k )
			{
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			ft::pair< const_iterator, const_iterator > equal_range( const key_type &k ) const
			{
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			// Insert member function
            ft::pair< iterator, bool > insert( const value_type &val )
			{
				avlTree *found;
				avlTree *ret;

				ret = NULL;
				found = giveLast(&baseTree, val);
				if (found == NULL)
				{
					baseTree = createNode(val, NULL);
					mapSize += 1;
					return ft::make_pair(begin(), true);
				}
				else if (found->data.first == val.first)
					return ft::make_pair(iterator(found), false);
				else
				{
					if (comp(val.first, found->data.first))
					{
						found->left = createNode(val, found);
						ret = found->left;
						while (found->parent != NULL)
						{
							found->height = std::max(giveHeight(found->left), giveHeight(found->right)) + 1;
							found = found->parent;
						}
						found->height = std::max(giveHeight(found->left), giveHeight(found->right)) + 1;
						if (ret->parent->right == NULL)
							balanceTree(&baseTree);
					}
					else if (comp(found->data.first, val.first))
					{
						found->right = createNode(val, found);
						ret = found->right;
						while (found->parent != NULL)
						{
							found->height = std::max(giveHeight(found->left), giveHeight(found->right)) + 1;
							found = found->parent;
						}
						found->height = std::max(giveHeight(found->left), giveHeight(found->right)) + 1;
						if (ret->parent->left == NULL)
							balanceTree(&baseTree);
					}
					mapSize += 1;
				}
				// balanceTree(&baseTree);
				// avlTree *found;

				// found = findKey(val.first, baseTree);
				// if (found != NULL)
				// 	return ft::make_pair(iterator(found), false);
				// insertRecursively(&baseTree, val);
				// balanceTree(&baseTree);
				// found = findKey(val.first, baseTree);
				return ft::make_pair(iterator(ret), true);
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
					insertRecursively(&baseTree, value_type(first->first, first->second));
				balanceTree(&baseTree);
			}

			// Erase member function
			void erase( iterator position )
			{
				avlTree *current;

				current = position.getCurrent();
				if (current != NULL)
				{
					mapSize -= 1;
					eraseNode(current);
				}
			}

			size_type erase( const key_type &k )
			{
				avlTree *found;

				found = findKey(k, baseTree);
				if (found == NULL)
					return 0;
				mapSize -= 1;
				eraseNode(found);
				return 1;
			}

			void erase( iterator first, iterator last )
			{
				ft::vector< const key_type > keys;
				avlTree *found;

				for (; first != last; first++)
					keys.push_back(first->first);
				for (size_t i = 0; i < keys.size(); i++)
				{
					found = findKey(keys[i], baseTree);
					if (found != NULL)
					{
						mapSize -= 1;
						if (found->right == NULL || found->left == NULL)
							deleteNodeWithOneChild(found);
						else
							deleteNodeWithTwoChilds(found);	
					}
				}
				balanceTree(&baseTree);
			}

			void swap( map &x )
			{
				std::swap(mapSize, x.mapSize);
				std::swap(baseTree, x.baseTree);
				std::swap(m_allocator, x.m_allocator);
			}

			void clear( void )
			{
				freeAll(baseTree);
				mapSize = 0;
				baseTree = NULL;
			}

        //---------------------ITERATORS---------------------
		iterator begin( void ) { return iterator(baseTree, BEGIN); }
		const_iterator begin( void ) const { return const_iterator(baseTree, BEGIN); }
		iterator end( void ) { return iterator(baseTree, END); }
		const_iterator end( void ) const { return const_iterator(baseTree, END); }

		reverse_iterator rbegin( void ) { return reverse_iterator(end()); }
		const_reverse_iterator rbegin( void ) const { return const_reverse_iterator(end()); }
		reverse_iterator rend( void ) { return reverse_iterator(begin()); }
		const_reverse_iterator rend( void ) const { return const_reverse_iterator(begin()); }

        //---------------------MEMBER ACCESS---------------------
		mapped_type &at( key_type const &k )
		{
			avlTree *found = findKey(k, baseTree);
			
			if (found == NULL)
				throw std::out_of_range("map::at:  key not found");
			return found->data.second;
		}
		const mapped_type &at( key_type const &k ) const
		{
			avlTree *found = findKey(k, baseTree);
			
			if (found == NULL)
				throw std::out_of_range("map::at:  key not found");
			return found->data.second;
		}

		mapped_type &operator[]( const key_type &k )
		{
			avlTree *tmp;

			tmp = findKey(k, baseTree);
			if (tmp != NULL)
				return tmp->data.second;
			return insert(value_type(k, mapped_type())).first->second;
		}

        //---------------------ALLOCATOR---------------------
		allocator_type get_allocator( void ) const { return m_allocator; }

        //---------------------PRIVATE MEMBER FUNCTIONS---------------------
        private :
            avlTree *createNode( const value_type &val, avlTree *parent )
			{
				avlTree *node;

				node = avlAlloc.allocate(1);
				avlAlloc.construct(node, avlTree(val, parent));
				return node;
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
                if (*root == NULL)
                {
                    *root = createNode(val, NULL);
					mapSize += 1;
                    return ;
                }
				if(comp(val.first, (*root)->data.first) && (*root)->left == NULL)
				{
					(*root)->left = createNode(val, *root);
					mapSize += 1;
				}
				else if (comp((*root)->data.first, val.first) && (*root)->right == NULL)
				{
					(*root)->right = createNode(val, *root);
					mapSize += 1;
				}
				else if (comp(val.first, (*root)->data.first) && (*root)->left)
					insertRecursively(&(*root)->left, val);
				else if (comp((*root)->data.first, val.first) && (*root)->right)
					insertRecursively(&(*root)->right, val);
				else
					return ;
				(*root)->height = std::max(giveHeight((*root)->right), giveHeight((*root)->left)) + 1;
			}

			size_type giveHeight( avlTree *t )
			{
				if (t == NULL)
					return 0;
				return t->height;
			}

			void freeAll( avlTree *root )
			{
				if (root == NULL)
					return ;
				freeAll(root->left);
				freeAll(root->right);
				avlAlloc.destroy(&(*root));
				avlAlloc.deallocate(root, 1);
			}

			avlTree *findKey( const key_type &k, avlTree *root ) const
			{
				if (root == NULL)
					return NULL;
				else if (comp(k, root->data.first))
					return findKey(k, root->left);
				else if (comp(root->data.first, k))
					return findKey(k, root->right);
				else
					return root;
			}

			void deleteNodeWithOneChild( avlTree *node )
			{
				avlTree *child;

				if (node->right)
					child = node->right;
				else
					child = node->left;
				if (child != NULL)
					child->parent = node->parent;
				if (node->parent == NULL)
					baseTree = child;
				else if (node->parent->left == node)
					node->parent->left = child;
				else
					node->parent->right = child;
				avlAlloc.destroy(node);
				avlAlloc.deallocate(node, 1);
			}

			void deleteNodeWithTwoChilds( avlTree *node )
			{
				avlTree *smallest;
				avlTree *newNode;

				smallest = node->right;
				while (smallest->left != NULL)
					smallest = smallest->left;
				newNode = createNode(smallest->data, node->parent);
				newNode->left = node->left;
				newNode->right = node->right;
				node->right->parent = newNode;
				node->left->parent = newNode;
				if (node->parent == NULL)
					baseTree = newNode;
				else if (node->parent->left == node)
					node->parent->left = newNode;
				else if (node->parent->right == node)
					node->parent->right = newNode;
				avlAlloc.destroy(node);
				avlAlloc.deallocate(node, 1);
				deleteNodeWithOneChild(smallest);
			}

			void balanceTree( avlTree **root )
			{
				int balanceFactor;

				if (*root == NULL)
					return ;
				balanceTree(&(*root)->left);
				balanceTree(&(*root)->right);
				balanceFactor = giveHeight((*root)->left) - giveHeight((*root)->right);
				if (balanceFactor == 2 && (*root)->left->left != NULL)
					*root = rightRotation(*root);
				else if (balanceFactor == 2 && (*root)->left->right != NULL)
				{
					(*root)->left = leftRotation((*root)->left);
					*root = rightRotation((*root));
				}
				else if (balanceFactor == -2 && (*root)->right->right != NULL)
					*root = leftRotation(*root);
				else if (balanceFactor == -2 && (*root)->right->left != NULL)
				{
					(*root)->right = rightRotation((*root)->right);
					*root = leftRotation(*root);
				}
			}

			void eraseNode( avlTree *node )
			{
				if (node->right == NULL || node->left == NULL)
					deleteNodeWithOneChild(node);
				else
					deleteNodeWithTwoChilds(node);
				balanceTree(&baseTree);	
			}

			avlTree *giveLast( avlTree **root, const value_type &val )
			{
				avlTree *tmp;
				
				tmp = *root;
				if (tmp == NULL)
					return NULL;
				while (tmp != NULL)
				{
					if (!comp(val.first, tmp->data.first) && !(comp(tmp->data.first, val.first)))
						return tmp;
					if ((comp(val.first, tmp->data.first) && tmp->left == NULL)
						|| (comp(tmp->data.first, val.first) && tmp->right == NULL))
						return tmp;
					else if (comp(val.first, tmp->data.first) && tmp->left != NULL)
						tmp = tmp->left;
					else if (comp(tmp->data.first, val.first) && tmp->right != NULL)
						tmp = tmp->right;
				}
				return tmp;
			}
   };

    //---------------------NON MEMBER FUNCTIONS---------------------
	template < class Key, class T, class Comp, class Alloc >
	bool operator==( const ft::map< Key, T, Comp, Alloc > &lhs, const ft::map< Key, T, Comp, Alloc > &rhs )
	{
		typename ft::map< Key, T, Comp, Alloc >::const_iterator b1, e1, b2, e2;
		
		if (lhs.size() != rhs.size())
			return false;
		b1 = lhs.begin();
		e1 = lhs.end();
		b2 = rhs.begin();
		e2 = rhs.end();
		while (b1 != e1 && b2 != e2)
		{
			if (b1->first != b2->first || b1->second != b2->second)
				return false;
			b1++;
			b2++;
		}
		if (b1 == e1 && b2 == e2)
			return true;
		return false;
	}

	template < class Key, class T, class Comp, class Alloc >
	bool operator!=( const ft::map< Key, T, Comp, Alloc > &lhs, const ft::map< Key, T, Comp, Alloc > &rhs )
	{
		return !(lhs == rhs);
	}


	template < class Key, class T, class Comp, class Alloc >
	bool operator<( const ft::map< Key, T, Comp, Alloc > &lhs, const ft::map< Key, T, Comp, Alloc > &rhs )
	{
		typename ft::map< Key, T, Comp, Alloc >::const_iterator b1, e1, b2, e2;

		if (lhs.size() == 0 && rhs.size() > 0)
			return true;
		else if (rhs.size() == 0 && lhs.size() > 0)
			return false;
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

	template < class Key, class T, class Comp, class Alloc >
	bool operator<=( const ft::map< Key, T, Comp, Alloc > &lhs, const ft::map< Key, T, Comp, Alloc > &rhs )
	{
		return !(lhs > rhs);
	}

	template < class Key, class T, class Comp, class Alloc >
	bool operator>( const ft::map< Key, T, Comp, Alloc > &lhs, const ft::map< Key, T, Comp, Alloc > &rhs )
	{
		return (rhs < lhs);
	}

	template < class Key, class T, class Comp, class Alloc >
	bool operator>=( const ft::map< Key, T, Comp, Alloc > &lhs, const ft::map< Key, T, Comp, Alloc > &rhs )
	{
		return !(lhs < rhs);
	}

	template < class Key, class T, class Comp, class Alloc >
	void swap( ft::map< Key, T, Comp, Alloc > &x, ft::map< Key, T, Comp, Alloc > &y )
	{
		x.swap(y);
	}
}