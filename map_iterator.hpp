#pragma once

#include "utils/iterator_traits.hpp"
#include "utils/tree.hpp"

namespace ft
{
    template < class T >
    class map_iterator
    {
        public :
            typedef typename ft::iterator_traits< T >::value_type value_type;
            typedef typename ft::iterator_traits< T >::difference_type difference_type;
            typedef typename ft::iterator_traits< T >::pointer pointer;
            typedef typename ft::iterator_traits< T >::reference reference;
            typedef std::bidirectional_iterator_tag iterator_category;
            typedef size_t size_type;
            typedef avlTree< value_type > avlTree;

        private :
            avlTree *m_root;
            // int isEnd;

            avlTree *leftMost( avlTree *node )
            {
                while (node->left != NULL)
                    node = node->left;
                return node;
            }
            avlTree *nextNode( void )
            {
                avlTree *tmp_root = m_root;
                avlTree *parent;

                if (tmp_root->right != NULL)
                    return leftMost(tmp_root->right);
                parent = tmp_root->parent;
                if (tmp_root == parent->left)
                    return parent;
                while (parent != NULL && tmp_root != parent->left)
                {
                    tmp_root = parent;
                    parent = tmp_root->parent;
                }
                return parent;
            }

            avlTree *rightMost( avlTree *node )
            {
                while (node->right != NULL)
                    node = node->right;
                return node;
            }

            avlTree *previousNode( void )
            {
                avlTree *tmp_root = m_root;
                avlTree *parent;

                if (tmp_root->left != NULL)
                    return rightMost(tmp_root);
                parent = tmp_root->parent;

                if (tmp_root == parent->right)
                    return parent;

                while (parent != NULL && tmp_root != parent->right)
                {
                    tmp_root = parent;
                    parent = tmp_root->parent;
                }
                return parent;
            }

        public :
            map_iterator( avlTree *ptr = NULL ) : m_root(ptr), isEnd(0) { }
            map_iterator( avlTree *ptr, int ) : m_root(ptr), isEnd(1) {}
            map_iterator( const map_iterator &rhs ) : m_root(rhs.m_root), isEnd(0) { }
            map_iterator &operator=( const map_iterator &rhs )
            {
                if (this != &rhs)
                {
                    isEnd = rhs.isEnd();
                    m_root = rhs.m_root;
                    return *this;
                }
                return *this;
            }
            ~map_iterator( ) { }

            // Dereference operators
            reference operator*( void ) { return m_root->data; }
            pointer operator->( void ) { return &m_root->data; }

            map_iterator &operator++( void )
            {
                m_root = nextNode();
                return *this;
            }
            map_iterator operator++( int )
            {
                map_iterator tmp(m_root);

                m_root = nextNode();
                return tmp;
            }

            map_iterator &operator--( void )
            {
                m_root = previousNode();
                return *this;
            }

            map_iterator operator--( int )
            {
                map_iterator tmp(m_root);

                m_root = previousNode();
                return tmp;
            }
    };
}