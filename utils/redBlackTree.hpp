#pragma once

#define BLACK true
#define RED false

#define RIGHT_ROTATION 1
#define LEFT_ROTATION 2
#define RIGHT_LEFT_ROTATION 3
#define LEFT_RIGHT_ROTATION 4

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

		// --------------Private attributes--------------
		private :
			base *baseTree;
			Comp compare;
			Alloc m_alloc;

		// --------------Constructor, Destructor--------------
		public :
			redBlackTree( void ) : baseTree(NULL) { }

			redBlackTree( Alloc alloc, Comp m_comp ) : baseTree(NULL),
				compare(m_comp), m_alloc(alloc) { }

			~redBlackTree( void ) { }

		// --------------Red Black Tree Public Methods--------------
		// ---------------------------------------
		public :
			void insert( T val )
			{
				if (baseTree == NULL)
					baseTree = new base(val, NULL, BLACK, m_alloc);
				else
					insertAndBalance(&baseTree, val);
			}

			//Printing functions
			void printLevels( void ) const { levels(baseTree); }
			void printInorder( void ) const { inorder(baseTree); }

			void inorder( base *root ) const
			{
				if (root == NULL)
					return ;
				inorder(root->left);
				std::cout << *root->data << std::endl;
				inorder(root->right);
			}

			void levels( base *root ) const
			{
				int size;
				std::queue< base * > q;
				base *tmp;

				q.push(root);
				while (q.size() > 0)
				{
					size = q.size();
					while (size > 0)
					{
						tmp = q.front();
						std::cout << *tmp->data << ", color : ";
						if (tmp->isBlack)
							std::cout << "black-------";
						else
							std::cout << "red------";
						q.pop();
						if (tmp->left)
							q.push(tmp->left);
						if (tmp->right)
							q.push(tmp->right);
						size--;
					}
					std::cout << std::endl;
				}
			}
			// ---------------------------------------

		// --------------Red Black Tree Private Methods--------------
		private :
			// Insert and check the color of the new node
			void insertAndBalance( base **root, T val )
			{
				if (compare(val, *(*root)->data) && (*root)->left == NULL)
				{
					(*root)->left = new base(val, *root, RED, m_alloc);
					checkColor((*root)->left);
				}
				else if (compare(*(*root)->data, val) && (*root)->right == NULL)
				{
					(*root)->right = new base(val, *root, RED, m_alloc);
					checkColor((*root)->right);
				}
				else if (compare(val, *(*root)->data) && (*root)->left != NULL)
					insertAndBalance(&(*root)->left, val);
				else if (compare(*(*root)->data, val) && (*root)->right != NULL)
					insertAndBalance(&(*root)->right, val);
				else
					return ;
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
				return rightNode;
			}
	};
};
