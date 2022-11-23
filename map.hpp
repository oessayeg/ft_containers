#pragma once

#include <queue>
#include <iostream>

#include <memory>
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
				for (; first != last; first++)
					insert(value_type(first->first, first->second));
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
					b = rhs.begin();
					e = rhs.end();
					for (; b != e; b++)
						insert(value_type(b->first, b->second));
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
			size_type count ( const key_type &k ) { return (findKey(k, baseTree) != NULL); }

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

				found = findKey(val.first, baseTree);
				if (found != NULL)
					return ft::make_pair(iterator(found), false);
				insertRecursively(&baseTree, val);
				found = findKey(val.first, baseTree);
				return ft::make_pair(iterator(found), true);
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
					insert(value_type(first->first, first->second));
			}

        //---------------------ITERATORS---------------------
		iterator begin( void ) { return iterator(baseTree, BEGIN); }
		const_iterator begin( void ) const { return const_iterator(baseTree, BEGIN); }
		iterator end( void ) { return iterator(baseTree, END); }
		const_iterator end( void ) const { return const_iterator(baseTree, END); }

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

			void freeAll( avlTree *root )
			{
				if (root == NULL)
					return ;
				freeAll(root->left);
				freeAll(root->right);
				delete root;
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
   };

    //---------------------NON MEMBER FUNCTION OVERLOADS---------------------
	template < class Key, class T, class Comp, class Alloc >
	bool operator==( const map< Key, T, Comp, Alloc > &lhs, const map< Key, T, Comp, Alloc > &rhs )
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
	bool operator!=( const map< Key, T, Comp, Alloc > &lhs, const map< Key, T, Comp, Alloc > &rhs )
	{
		return !(lhs == rhs);
	}


	template < class Key, class T, class Comp, class Alloc >
	bool operator<( const map< Key, T, Comp, Alloc > &lhs, const map< Key, T, Comp, Alloc > &rhs )
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
			b1++;
			b2++;
		}
		if (b1 == e1 && b2 != e2)
			return true;
		return false;
	}

	template < class Key, class T, class Comp, class Alloc >
	bool operator<=( const map< Key, T, Comp, Alloc > &lhs, const map< Key, T, Comp, Alloc > &rhs )
	{
		return !(lhs > rhs);
	}

	template < class Key, class T, class Comp, class Alloc >
	bool operator>( const map< Key, T, Comp, Alloc > &lhs, const map< Key, T, Comp, Alloc > &rhs )
	{
		return (rhs < lhs);
	}

	template < class Key, class T, class Comp, class Alloc >
	bool operator>=( const map< Key, T, Comp, Alloc > &lhs, const map< Key, T, Comp, Alloc > &rhs )
	{
		return !(lhs < rhs);
	}
}