#pragma once

#include "utils/iterator_traits.hpp"
#include "utils/redBlackTree.hpp"

#define BEGIN 1
#define END 2

namespace ft
{
    template < class T, class Tree >
    class set_iterator
    {
        // -------------------Member Types-------------------
        public :
            typedef typename ft::iterator_traits< T >::value_type value_type;
            typedef typename ft::iterator_traits< T >::difference_type difference_type;
            typedef typename ft::iterator_traits< T >::pointer pointer;
            typedef typename ft::iterator_traits< T >::reference reference;
            typedef std::bidirectional_iterator_tag iterator_category;
            typedef size_t size_type;

        private :
            Tree *m_current_node;
            Tree *first_node;
            Tree *last_node;
            int  firstT;

        public :
            set_iterator ( void ) : m_current_node(NULL), first_node(NULL), last_node(NULL), firstT(0)  { }
            set_iterator ( Tree *root, int position )
            {
                Tree *first;
                Tree *last;

                firstT = 0;
                if (root == NULL)
                {
                    first_node = NULL;
                    last_node = NULL;
                    m_current_node = NULL;
                    return ;
                }
                first = root;
                while (first->left != NULL)
                    first = first->left;
                last = root;
                while (last->right != NULL)
                    last = last->right;
                if (position == BEGIN)
                    m_current_node = first;
                else if (position == END)
                {
                    firstT = 1;
                    m_current_node = NULL;
                }
                first_node = first;
                last_node = last;
            }
            set_iterator( Tree *current )
			{
				Tree *root;

				m_current_node = current;
				firstT = 0;
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

            template < class X, class Y >
            set_iterator( const set_iterator< X, Y > &rhs )
            {
                m_current_node = rhs.getCurrent();
                first_node = rhs.getFirst();
                last_node = rhs.getLast();
                firstT = rhs.getFirstT();
            }

            set_iterator &operator=( const set_iterator &rhs )
            {
                if (this != &rhs)
                {
                    m_current_node = rhs.getCurrent();
                    first_node = rhs.getFirst();
                    last_node = rhs.getLast();
                    firstT = rhs.getFirstT();
                }
                return *this;
            }

            ~set_iterator( ) { }           

            // Pre and post increment operators
            set_iterator &operator++( void )
            {
                m_current_node = getNextNode(m_current_node);
                return *this;
            }
            set_iterator operator++( int )
            {
                set_iterator tmp = *this;

                m_current_node = getNextNode(m_current_node);
                return tmp;
            }

            // Pre and post decrement operators
            set_iterator &operator--( void )
            {
                m_current_node = getPreviousNode(m_current_node);
                return *this;
            }
            set_iterator operator--( int )
            {
                set_iterator tmp = *this;

                m_current_node = getPreviousNode(m_current_node);
                return tmp;
            }

            // Dereference operators
            const value_type &operator*( void ) { return *m_current_node->data; }
            const value_type *operator->( void ) { return m_current_node->data; }

            // Comparison operators
            template < class U, class A >
            bool operator==( const set_iterator< U, A > &rhs ) { return m_current_node == rhs.getCurrent() ; }

            template < class U, class A >
            bool operator!=( const set_iterator< U, A > &rhs ) { return m_current_node != rhs.getCurrent() ; }

            // Private attributes getters
            Tree* getCurrent( void ) const { return m_current_node; }
            Tree* getFirst( void ) const { return first_node; }
            Tree* getLast( void ) const { return last_node; }
            int getFirstT( void ) const { return firstT; }

        private :
            Tree *getNextNode( Tree *node )
            {
                Tree *leftMost;
                Tree *parent;

                if (node == last_node)
                    return NULL;
                if (node->right)
                {
                    leftMost = node->right;
                    while (leftMost->left != NULL)
                        leftMost = leftMost->left;
                    return leftMost;
                }
                parent = node->parent;
                while (parent != NULL && parent->left != node)
                {
                    node = parent;
                    parent = node->parent;
                }
                return parent;
            }

            Tree *getPreviousNode( Tree *node )
            {
                Tree *rightMost;
                Tree *parent;
                
                if (m_current_node == NULL && firstT == 1)
                {
                    firstT = 0;
                    return last_node;
                }
                if (node->left)
                {
                    rightMost = node->left;
                    while (rightMost->right != NULL)
                        rightMost = rightMost->right;
                    return rightMost;
                }
                parent = node->parent;
                while (parent != NULL && parent->right != node)
                {
                    node = parent;
                    parent = node->parent;
                }
                return parent;
            }
    };
}