#pragma once

#include "../utils/iterator_traits.hpp"
#include "../utils/avlTree.hpp"
#include "../utils/type_traits.hpp"

namespace ft
{
    template < class T >
    class map_iterator
    {
		// -----------------------Member Types-----------------------
        public :
            typedef typename ft::iterator_traits< T >::value_type value_type;
            typedef typename ft::iterator_traits< T >::difference_type difference_type;
            typedef typename ft::iterator_traits< T >::pointer pointer;
            typedef typename ft::iterator_traits< T >::reference reference;
            typedef std::bidirectional_iterator_tag iterator_category;
            typedef size_t size_type;
            typedef avlTree< value_type > avlTree;

		// -----------------------Member Attributes-----------------------
        private :
            avlTree *m_current_node;
            avlTree *first_node;
            avlTree *last_node;
			int		check;

		// -----------------------Public Member Functions-----------------------
        public :
			// ------------------Contstructors, Assignment operator overload, Destructor------------------
            map_iterator( void ) : m_current_node(NULL), first_node(NULL), last_node(NULL), check(0) { }

            map_iterator( avlTree *root, int pos )
            {
                avlTree *tmp;

				tmp = root;
				if (tmp == NULL)
				{
					m_current_node = NULL;
					first_node = NULL;
					last_node = NULL;
					check = 0;
					return ;
				}
				while (tmp->left != NULL)
					tmp = tmp->left;
				first_node = tmp;
				while (root->right != NULL)
					root = root->right;
				last_node = root;
                if (pos == BEGIN)
				{
                    m_current_node = first_node;
					check = 0;
				}
				else if (pos == END)
				{
					m_current_node = NULL;
					check = 1;
				}
            }

			map_iterator( avlTree *current )
			{
				avlTree *root;

				m_current_node = current;
				check = 0;
				while (current->parent != NULL)
					current = current->parent;
				root = current;
				while (root->left != NULL)
					root = root->left;
				while (current->right != NULL)
					current = current->right;
				first_node = root;
				last_node = current;	
			}

			template < class U >
            map_iterator( const map_iterator< U > &rhs, typename ft::enable_if< ft::is_convertible< T, U >::value >::type * = 0 )
			{
				m_current_node = rhs.getCurrent();
				first_node = rhs.getFirst();
				last_node = rhs.getLast();
				check = rhs.getCheck();
			}

            map_iterator &operator=( const map_iterator &rhs )
            {
                if (this != &rhs)
                {
                    m_current_node = rhs.m_current_node;
                    first_node = rhs.first_node;
                    last_node = rhs.last_node;
					check = rhs.check;
                    return *this;
                }
                return *this;
            }

            ~map_iterator( ) { }

            // Dereference operators
            reference operator*( void ) { return m_current_node->data; }
			const value_type &operator*( void ) const { return m_current_node->data; }
            pointer operator->( void ) { return &m_current_node->data; }
            const value_type *operator->( void ) const { return &m_current_node->data; }

            // Pre and post increment operators
            map_iterator &operator++( void )
            {
                m_current_node = nextNode(m_current_node);
				if (m_current_node == NULL)
					check = 1;
                return *this;
            }

            map_iterator operator++( int )
            {
                map_iterator tmp(*this);

                m_current_node = nextNode(m_current_node);
				if (m_current_node == NULL)
					check = 1;
                return tmp;
            }
            
            // Pre and post decrement operators
			map_iterator &operator--( void )
			{
				m_current_node = previousNode(m_current_node);
				return *this;
			}

			map_iterator operator--( int )
			{
				map_iterator tmp(*this);

				m_current_node = previousNode(m_current_node);
				return tmp;
			}

			// Getters for private member attributes
			avlTree *getCurrent() const { return m_current_node; }
			avlTree *getFirst() const { return first_node; }
			avlTree *getLast() const { return last_node; }
			int getCheck() const { return check; }

			// Equality, Inequality operators
			template < class X >
			bool operator==( const map_iterator< X > &rhs )
			{
				return m_current_node == rhs.getCurrent();
			}

			template < class Y >
			bool operator!=( const map_iterator< Y > &rhs )
			{
				return !(*this == rhs);
			}

		// -----------------------Private Member Functions-----------------------
        private :
			// Get the succesor of the node given in the parameter
            avlTree *nextNode( avlTree *node )
			{
				avlTree *parent;

				if (node == last_node || node == NULL)
					return NULL;
				parent = node->parent;
				if (node->right != NULL)
				{
					node = node->right;
					while (node->left != NULL)
						node = node->left;
					return node;
				}
				if (node == parent->left)
					return parent;
				while (parent != NULL && node != parent->left)
				{
					node = parent;
					parent = node->parent;
				}
				return parent;
            }

			// Get the predecessor of the node given in the parameter
			avlTree *previousNode( avlTree *node )
			{
				avlTree *parent;

				if (check == 1 && node == NULL)
				{
					check = 0;
					return last_node;
				}
				else if (node == first_node || node == NULL)
					return NULL;
				parent = node->parent;
				if (node->left != NULL)
				{
					node = node->left;
					while (node->right != NULL)
						node = node->right;
					return node;
				}
				if (node == parent->right)
					return parent;
				while (parent != NULL && node != parent->right)
				{
					node = parent;
					parent = node->parent;
				}
				return parent;
			}
    };
}