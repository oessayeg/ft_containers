#pragma once

#define BLACK true
#define RED false

#define RIGHT_ROTATION 1
#define LEFT_ROTATION 2
#define RIGHT_LEFT_ROTATION 3
#define LEFT_RIGHT_ROTATION 4

#define CASE_1 1
#define CASE_2 2
#define CASE_3 3
#define CASE_4 4
#define CASE_5 5
#define CASE_6 6

#define LEFT 1
#define RIGHT 2

#include <iostream>

namespace ft
{
	template < class T, class Alloc >
	class base
	{
		// --------------Base tree member attributes--------------
		public :
			T* data;
			base *left;
			base *right;
			base *parent;
			bool isBlack;
			Alloc m_alloc;

		// --------------Base constructor--------------
		public :
			base( void ) : data(NULL), left(NULL), right(NULL),
				parent(NULL), isBlack(true), m_alloc(Alloc()) { }

			base( T val, base *parent, bool color, Alloc allocator ) : left(NULL),
				right(NULL), parent(parent), isBlack(color), m_alloc(allocator)
			{
				data = m_alloc.allocate(1);
				m_alloc.construct(data, val);
			}

			~base( void ) { }
	};

	// --------------Red Black Tree--------------
	template < class T, class Comp, class Alloc >
	class redBlackTree
	{
		// --------------Member Types--------------
		public :
			typedef T value_type;
			typedef base < T, Alloc > base;
			typedef size_t size_type;

		// --------------Private attributes--------------
		private :
			base *baseTree;
			Comp compare;
			Alloc m_alloc;
			size_type setSize;

		// --------------Constructor, Destructor--------------
		public :
			redBlackTree( void ) : baseTree(NULL), setSize(0) { }

			redBlackTree( Alloc alloc, Comp m_comp ) : baseTree(NULL),
				compare(m_comp), m_alloc(alloc), setSize(0) { }

			~redBlackTree( void ) { clear(); }

		// --------------Red Black Tree Public Methods--------------
		public :
			Alloc getAllocator( void ) const { return m_alloc; }
			base *getRoot( void ) const { return baseTree; }
			bool insert( const T &val )
			{
				if (baseTree == NULL)
				{
					baseTree = new base(val, NULL, BLACK, m_alloc);
					setSize += 1;
					return true;
				}
				return insertAndBalance(&baseTree, val);
			}

			void swap( redBlackTree &x )
			{
				base *tmp1 = x.baseTree;
				Comp tmp2 = x.compare;
				Alloc tmp3 = x.m_alloc;
				size_type tmp4 = x.setSize;

				x.baseTree = baseTree;
				x.compare = compare;
				x.m_alloc = m_alloc;
				x.setSize = setSize;

				baseTree = tmp1;
				compare = tmp2;
				m_alloc = tmp3;
				setSize = tmp4;
			}

			base *bound( const T &val, int whichBound ) const
			{
				base *tmp;

				tmp = baseTree;
				while (tmp != NULL)
				{
					if (compare(*tmp->data, val))
						tmp = tmp->right;
					else
						break;
				}
				(void)whichBound;
				if (tmp)
					return tmp;
				std::cout << *tmp->data << std::endl;
				return NULL;
			}

			size_type erase( const T &val )
			{
				base *toDelete;

				toDelete = baseTree;
				while (toDelete != NULL)
				{
					if (*toDelete->data == val)
						break;
					else if (val < *toDelete->data)
						toDelete = toDelete->left;
					else if (val > *toDelete->data)
						toDelete = toDelete->right;
				}
				if (toDelete == NULL)
					return 0;
				if (toDelete == baseTree)
					eraseAndFixTree(&baseTree);
				else if (toDelete->parent->left == toDelete)
					eraseAndFixTree(&toDelete->parent->left);
				else if (toDelete->parent->right == toDelete)
					eraseAndFixTree(&toDelete->parent->right);
				setSize -= 1;
				return 1;
			}

			void clear ( void ) { clearEverything(baseTree); setSize = 0; baseTree = NULL; }
			void clearEverything( base *rootNode )
			{
				if (rootNode == NULL)
					return ;
				clearEverything(rootNode->left);
				clearEverything(rootNode->right);
				m_alloc.destroy(rootNode->data);
				m_alloc.deallocate(rootNode->data, 1);
				delete rootNode;

			}

			base *find( value_type const &val ) const
			{
				base *tmp;
				
				tmp = baseTree;
				while (tmp != NULL)
				{
					if (compare(val, *tmp->data))
						tmp = tmp->left;
					else if (compare(*tmp->data, val))
						tmp = tmp->right;
					else
						break;
				}
				return tmp;
			}

			size_type size( void ) const { return setSize; }
			size_type max( void ) const { return m_alloc.max_size(); }

		// --------------Red Black Tree Private Methods--------------
		private :
			// Insert and check the color of the new node
			bool insertAndBalance( base **root, T val )
			{
				if (compare(val, *(*root)->data) && (*root)->left == NULL)
				{
					(*root)->left = new base(val, *root, RED, m_alloc);
					checkColor((*root)->left);
					setSize += 1;
					return true;
				}
				else if (compare(*(*root)->data, val) && (*root)->right == NULL)
				{
					(*root)->right = new base(val, *root, RED, m_alloc);
					checkColor((*root)->right);
					setSize += 1;
					return true;
				}
				else if (compare(val, *(*root)->data) && (*root)->left != NULL)
					return insertAndBalance(&(*root)->left, val);
				else if (compare(*(*root)->data, val) && (*root)->right != NULL)
					return insertAndBalance(&(*root)->right, val);
				else
					return false;
			}

			// Check the color of the inserted node
			void checkColor( base *insertedNode )
			{
				base *sibling;
				int rotation;

				if (insertedNode->parent->isBlack)
					return ;
				sibling = giveSibling(insertedNode->parent);
				if (sibling == NULL || sibling->isBlack)
				{
					rotation = giveSuitableRotation(insertedNode);
					if (insertedNode->parent->parent->parent == NULL)
						rotateForRoot(rotation, insertedNode);
					else if (insertedNode->parent->parent->parent->left == insertedNode->parent->parent)
						rotateForLeftSubtree(rotation, insertedNode->parent->parent);
					else
						rotateForRightSubtree(rotation, insertedNode->parent->parent);
				}
				else if (!sibling->isBlack)
				{
					sibling->isBlack = true;
					insertedNode->parent->isBlack = true;
					if (sibling->parent->parent == NULL)
						return ;
					sibling->parent->isBlack = false;
					checkColor(sibling->parent);
				}
			}

			// Get the sibling of a node to check the color
			base *giveSibling( base *node )
			{
				if (node->parent->right == node)
					return node->parent->left;
				return node->parent->right;
			}
			
			// Return an int indicating which rotation should be done
			int giveSuitableRotation( base *node )
			{
				if (node->parent->left == node && node->parent->parent->left == node->parent)
					return RIGHT_ROTATION;
				else if (node->parent->right == node && node->parent->parent->right == node->parent)
					return LEFT_ROTATION;
				else if (node->parent->right == node && node->parent->parent->left == node->parent)
					return LEFT_RIGHT_ROTATION;
				return RIGHT_LEFT_ROTATION;
			}

			// Perform a rotation for root
			void rotateForRoot( int rotation, base *node )
			{
				if (rotation == RIGHT_ROTATION)
					baseTree = rightRotation(node->parent->parent);
				else if (rotation == LEFT_ROTATION)
					baseTree = leftRotation(node->parent->parent);
				else if (rotation == LEFT_RIGHT_ROTATION)
				{
					baseTree->left = leftRotation(baseTree->left);
					baseTree = rightRotation(baseTree);
				}
				else if (rotation == RIGHT_LEFT_ROTATION)
				{
					baseTree->right = rightRotation(baseTree->right);
					baseTree = leftRotation(baseTree);
				}
			}
			
			// Perform rotations for a left subtree
			void rotateForLeftSubtree( int rotation, base *toRotate )
			{
				base *tmp;

				tmp = toRotate->parent;
				if (rotation == RIGHT_ROTATION)
					tmp->left = rightRotation(toRotate);
				else if (rotation == LEFT_ROTATION)
					tmp->left = leftRotation(toRotate);
				else if (rotation == LEFT_RIGHT_ROTATION)
				{
					toRotate->left = leftRotation(toRotate->left);
					tmp->left = rightRotation(toRotate);
				}
				else if (rotation == RIGHT_LEFT_ROTATION)
				{
					toRotate->right = rightRotation(toRotate->right);
					tmp->left = leftRotation(toRotate);
				}
			}

			// Perform rotations for a right subtree
			void rotateForRightSubtree( int rotation, base *toRotate )
			{
				base *tmp;

				tmp = toRotate->parent;
				if (rotation == RIGHT_ROTATION)
					tmp->right = rightRotation(toRotate);
				else if (rotation == LEFT_ROTATION)
					tmp->right = leftRotation(toRotate);
				else if (rotation == LEFT_RIGHT_ROTATION)
				{
					toRotate->left = leftRotation(toRotate->left);
					tmp->right = rightRotation(toRotate);
				}
				else if (rotation == RIGHT_LEFT_ROTATION)
				{
					toRotate->right = rightRotation(toRotate->right);
					tmp->right = leftRotation(toRotate);
				}
			}

			// Perform a right rotation and return the new root of the subtree
			base *rightRotation( base *node )
			{
				base *leftNode;
				base *rightOfLeftnode;

				leftNode = node->left;
				rightOfLeftnode = leftNode->right;
				node->isBlack = false;
				leftNode->isBlack = true;
				leftNode->parent = node->parent;
				node->parent = leftNode;
				leftNode->right = node;
				node->left = rightOfLeftnode;
				if (rightOfLeftnode != NULL)
					rightOfLeftnode->parent = node;
				return leftNode;
			}

			// Perform a left rotation and return the new root of the subtree
			base *leftRotation( base *node )
			{
				base *rightNode;
				base *leftOfRightnode;

				rightNode = node->right;
				leftOfRightnode = rightNode->left;
				node->isBlack = false;
				rightNode->isBlack = true;
				rightNode->parent = node->parent;
				node->parent = rightNode;
				rightNode->left = node;
				node->right = leftOfRightnode;
				if (leftOfRightnode != NULL)
					leftOfRightnode->parent = node;
				return rightNode;
			}

			void eraseAndFixTree( base **toDelete )
			{
				if (!(*toDelete)->isBlack)
					deleteRedNode(toDelete);
				else
					deleteBlackNode(toDelete);
			}

			void deleteRedNode( base **toDelete )
			{
				base *leftMost;

				if ((*toDelete)->right == NULL && (*toDelete)->left == NULL)
				{
					m_alloc.destroy((*toDelete)->data);
					m_alloc.deallocate((*toDelete)->data, 1);
					if ((*toDelete)->parent->left == (*toDelete))
						(*toDelete)->parent->left = NULL;
					else
						(*toDelete)->parent->right = NULL;
					if (*toDelete == baseTree)
						baseTree = NULL;
					delete *toDelete;
				}
				else
				{
					leftMost = (*toDelete)->right;
					while (leftMost->left != NULL)
						leftMost = leftMost->left;
					m_alloc.destroy((*toDelete)->data);
					m_alloc.construct((*toDelete)->data, *leftMost->data);
					if (leftMost->parent->left == leftMost)
						eraseAndFixTree(&leftMost->parent->left);
					else 
						eraseAndFixTree(&leftMost->parent->right);
				}
			}
			
			bool isDoubleBlack( base *toCheck )
			{
				if ((toCheck->left == NULL && toCheck->right == NULL)
					|| (toCheck->left != NULL && toCheck->right == NULL && toCheck->left->isBlack)
					|| (toCheck->right != NULL && toCheck->left == NULL && toCheck->right->isBlack))
					return true;
				return false;
			}

			void deleteBlackNode( base **toDelete )
			{
				base *leftMost;

				if (isDoubleBlack(*toDelete))
					deleteDoubleBlack(toDelete);
				else if ((*toDelete)->left == NULL && (*toDelete)->right != NULL
					&& !((*toDelete)->right->isBlack))
				{
					m_alloc.destroy((*toDelete)->data);
					m_alloc.construct((*toDelete)->data, *(*toDelete)->right->data);
					eraseAndFixTree(&(*toDelete)->right);
				}
				else if ((*toDelete)->left != NULL && (*toDelete)->right == NULL
					&& (!(*toDelete)->left->isBlack))
				{
					m_alloc.destroy((*toDelete)->data);
					m_alloc.construct((*toDelete)->data, *(*toDelete)->left->data);
					eraseAndFixTree(&(*toDelete)->left);
				}
				else
				{
					leftMost = (*toDelete)->right;
					while (leftMost->left != NULL)
						leftMost = leftMost->left;
					m_alloc.destroy((*toDelete)->data);
					m_alloc.construct((*toDelete)->data, *leftMost->data);
					if (leftMost->parent->left == leftMost)
						eraseAndFixTree(&leftMost->parent->left);
					else
						eraseAndFixTree(&leftMost->parent->right);
				}
			}
			
			void deleteDoubleBlack( base **toDelete )
			{
				base *tmp1, *tmp2, *parent, *sibling;
				int whichCase, position;

				if ((*toDelete)->parent == NULL)
					sibling = NULL;
				else
					sibling = giveSibling(*toDelete);
				if ((*toDelete)->parent == NULL && (*toDelete)->left == NULL && (*toDelete)->right == NULL)
				{
					m_alloc.destroy((*toDelete)->data);
					m_alloc.deallocate((*toDelete)->data, 1);
					delete *toDelete;
					baseTree = NULL;
					return ;
				}
				if ((*toDelete)->parent->right == (*toDelete))
					position = RIGHT;
				else
					position = LEFT;
				whichCase = giveCase((*toDelete)->parent, sibling, position);
				if (whichCase == CASE_1 && (*toDelete)->left == NULL && (*toDelete)->right != NULL)
				{
					tmp1 = (*toDelete);
					*toDelete = (*toDelete)->right;
					handleDoubleBlack(giveCase(*toDelete, (*toDelete)->right, position), &(*toDelete)->right, position);
					return ;
				}
				else if (whichCase == CASE_1 && (*toDelete)->left != NULL && (*toDelete)->right == NULL)
				{
					tmp1 = (*toDelete);
					*toDelete = (*toDelete)->left;
					handleDoubleBlack(giveCase(*toDelete, (*toDelete)->right, position), &(*toDelete)->left, position);
					return ;
				}
				parent = (*toDelete)->parent;
				if ((*toDelete)->right == NULL && (*toDelete)->left == NULL)
				{
					tmp1 = (*toDelete);
					if (tmp1->parent->right == tmp1)
						tmp1->parent->right = NULL;
					else if (tmp1->parent->left == tmp1)
						tmp1->parent->left = NULL;
				}
				else if ((*toDelete)->left == NULL && (*toDelete)->right != NULL)
				{
					tmp1 = (*toDelete);
					tmp2 = (*toDelete)->right;
					if (tmp1->parent->right == tmp1)
						tmp1->parent->right = tmp2;
					else if (tmp1->parent->left == tmp1)
						tmp1->parent->left = tmp2;
				}
				else
				{
					tmp1 = (*toDelete);
					tmp2 = (*toDelete)->left;
					if (tmp1->parent->right == tmp1)
						tmp1->parent->right = tmp2;
					else if (tmp1->parent->left == tmp1)
						tmp1->parent->left = tmp2;
				}
				m_alloc.destroy(tmp1->data);
				m_alloc.deallocate(tmp1->data, 1);
				delete tmp1;
				if (parent == baseTree)
					handleDoubleBlack(whichCase, &baseTree, position);
				else if (parent->parent->left == parent)
					handleDoubleBlack(whichCase, &parent->parent->left, position);
				else if (parent->parent->right == parent)
					handleDoubleBlack(whichCase, &parent->parent->right, position);
			}

			bool hasBlackChildren( base *node )
			{
				if ((node->right != NULL && node->left != NULL && node->right->isBlack && node->left->isBlack)
					|| (node->right == NULL && node->left != NULL && node->left->isBlack)
					|| (node->right != NULL && node->left == NULL && node->right->isBlack)
					|| (node->right == NULL && node->left == NULL))
					return true;
				return false;
			}

			bool isCase5( base *parent, base *sibling, int position )
			{
				if (position == LEFT && parent->isBlack && sibling->isBlack && sibling->left && !sibling->left->isBlack
					&& (sibling->right == NULL || sibling->right->isBlack))
					return true;
				else if (position == RIGHT && parent->isBlack && sibling->isBlack && sibling->right && !sibling->right->isBlack
					&& (sibling->left == NULL || sibling->left->isBlack))
					return true;
				return false;
			}

			int giveCase( base *parent, base *sibling, int position )
			{
				if (parent == NULL)
					return CASE_1;
				if (parent->isBlack && !sibling->isBlack && hasBlackChildren(sibling))
					return CASE_2;
				else if (parent->isBlack && sibling->isBlack && hasBlackChildren(sibling))
					return CASE_3;
				else if (!(parent->isBlack) && sibling->isBlack && hasBlackChildren(sibling))
					return CASE_4;
				else if (isCase5(parent, sibling, position))
					return CASE_5;
				else if ((sibling->isBlack && sibling->right && !sibling->right->isBlack)
					|| (sibling->isBlack && sibling->left && !sibling->left->isBlack))
					return CASE_6;
				return 0;
			}
			// 6 cases
			void handleDoubleBlack( int whichFix, base **parent, int position )
			{
				if (whichFix == CASE_2)
					fixCase2(position, parent);
				else if (whichFix == CASE_3)
					fixCase3(position, parent);
				else if (whichFix == CASE_4)
				{
					(*parent)->isBlack = true;
					if (position == LEFT)
						(*parent)->right->isBlack = false;
					else
						(*parent)->left->isBlack = false;
				}
				else if (whichFix == CASE_5)
					fixCase5(position, parent);
				else if (whichFix == CASE_6)
					fixCase6(position, parent);
			}

			void fixCase2( int position, base **parent )
			{
				if (position == LEFT)
				{
					*parent = leftRotation(*parent);
					(*parent)->isBlack = true;
					(*parent)->right->isBlack = true;
					(*parent)->left->isBlack = false;
					handleDoubleBlack(giveCase((*parent)->left, (*parent)->left->right, position), &(*parent)->left, position);
				}
				else
				{
					*parent = rightRotation(*parent);
					(*parent)->isBlack = true;
					(*parent)->left->isBlack = true;
					(*parent)->right->isBlack = false;
					handleDoubleBlack(giveCase((*parent)->right, (*parent)->right->left, position), &(*parent)->right, position);
				}
			}

			void fixCase3( int position, base **parent )
			{
				base *sibling;

				if (position == LEFT)
					sibling = (*parent)->right;
				else
					sibling = (*parent)->left;
				sibling->isBlack = false;
				if ((*parent)->parent == NULL)
					return ;
				sibling = giveSibling(*parent);
				if ((*parent)->parent->left == (*parent))
					position = LEFT;
				else
					position = RIGHT;
				if ((*parent)->parent->parent == NULL)
					handleDoubleBlack(giveCase((*parent)->parent, sibling, position), &baseTree, position);
				else if ((*parent)->parent->parent->left == (*parent)->parent)
					handleDoubleBlack(giveCase((*parent)->parent, sibling, position), &(*parent)->parent->parent->left, position);
				else if ((*parent)->parent->parent->right == (*parent)->parent)
					handleDoubleBlack(giveCase((*parent)->parent, sibling, position), &(*parent)->parent->parent->right, position);
			}

			void fixCase5( int position, base **parent )
			{
				if (position == LEFT)
				{
					(*parent)->right = rightRotation((*parent)->right);
					(*parent)->right->isBlack = true;
					(*parent)->right->right->isBlack = false;
					handleDoubleBlack(giveCase(*parent, (*parent)->right, position), parent, position);
				}
				else if (position == RIGHT)
				{
					(*parent)->left = leftRotation((*parent)->left);
					(*parent)->left->isBlack = true;
					(*parent)->left->left->isBlack = false;
					handleDoubleBlack(6, parent, position);
				}
			}

			void fixCase6( int position, base **parent )
			{
				base *sibling = NULL, *oldParent = NULL;
				bool tmpColor;

				tmpColor = (*parent)->isBlack;
				if (position == LEFT)
				{
					sibling = (*parent)->right;
					if ((sibling->right == NULL || sibling->right->isBlack) && !sibling->left->isBlack)
					{
						oldParent = (*parent);
						(*parent) = leftRotation(*parent);
						oldParent->isBlack = false;
						(*parent)->isBlack = true;
						(*parent)->left = leftRotation((*parent)->left);
						(*parent) = rightRotation(*parent);
					}
					else
					{
						oldParent = *parent;
						*parent = leftRotation(*parent);
						oldParent->isBlack = true;
						sibling->isBlack = tmpColor;
						sibling->right->isBlack = true;
					}
				}
				else
				{
					sibling = (*parent)->left;
					if ((sibling->left == NULL || sibling->left->isBlack) && !sibling->right->isBlack )
					{
						oldParent = (*parent);
						(*parent) = rightRotation(*parent);
						oldParent->isBlack = false;
						(*parent)->isBlack = true;
						(*parent)->right = rightRotation((*parent)->right);
						(*parent) = leftRotation(*parent);
					}
					else
					{
						sibling = (*parent)->left;
						oldParent = *parent;
						*parent = rightRotation(*parent);
						oldParent->isBlack = true;
						sibling->isBlack = tmpColor;
						if (sibling->left)
							sibling->left->isBlack = true;
					}
				}
			}
	};
};
