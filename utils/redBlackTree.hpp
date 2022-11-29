#pragma once

#define BLACK true
#define RED false

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

		public :
			base( void ) : data(NULL), left(NULL), right(NULL),
				parent(NULL), isBlack(true), m_alloc(Alloc()) { }

			base( T val, base *parent, bool color ) : left(NULL),
				right(NULL), parent(parent), isBlack(color)
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

		// --------------Constructor, Destructor--------------
		public :
			redBlackTree( void ) : baseTree(NULL) { }
			~redBlackTree( void ) { }

		// --------------Red Black Tree Public Methods--------------
		public :
			void insert( T val )
			{
				if (baseTree == NULL)
					baseTree = new base(val, NULL, BLACK);
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
			//Printing functions end

		// --------------Red Black Tree Private Methods--------------
		private :
			base *giveSibling( base *node )
			{
				if (node->parent->right == node)
					return node->parent->left;
				return node->parent->right;
			}

			void doSuitableRotation( base *node )
			{
				if (node->parent->left == node && node->parent->parent->left == node->parent)
					// right rotation
				else if (node->parent->right == node && node->parent->parent->left == node->parent)
					// left, right rotation
				else if (node->parent->right == node && node->parent->parent->right == node->parent)
					// right rotation
				else if (node->parent->left == node && node->parent->parent->right == node->parent)
					// right, left rotation
			}

			void checkColor( base *insertedNode )
			{
				base *sibling;

				// Should not forget to protect parent for root node
				if (insertedNode->parent->isBlack)
					return ;
				sibling = giveSibling(insertedNode->parent);
				if (sibling == NULL || sibling->isBlack)
					doSuitableRotation(insertedNode);
				else if (!sibling->isBlack)
				{
					sibling->isBlack = true;
					insertedNode->parent->isBlack = true;
					if (sibling->parent->parent == NULL)
						return ;
					sibling->parent->parent->isBlack = false;
					checkColor(sibling->parent->parent);
				}
			}

			void insertAndBalance( base **root, T val )
			{
				if (compare(val, *(*root)->data) && (*root)->left == NULL)
				{
					(*root)->left = new base(val, *root, RED);
					checkColor((*root)->left);
				}
				else if (compare(*(*root)->data, val) && (*root)->right == NULL)
				{
					(*root)->right = new base(val, *root, RED);
					checkColor((*root)->right);
				}
				else if (compare(val, *(*root)->data) && (*root)->left != NULL)
					insertAndBalance(&(*root)->left, val);
				else if (compare(*(*root)->data, val) && (*root)->right != NULL)
					insertAndBalance(&(*root)->right, val);
				else
					return ;
			}

	};
};
