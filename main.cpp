#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <iterator>
#include <sys/time.h>
#include <map>
#include <cmath>
#include "map.hpp"

template < class T >
struct avlTree
{
	T data;
	struct avlTree *right;
	struct avlTree *left;
	size_t height;
};

template < class T >
avlTree< T > *createNode( T val )
{
	avlTree< T > *ret = new avlTree< T >[1];

	ret->data = val;
	ret->right = NULL;
	ret->left = NULL;
	return ret;
}

template < class T >
avlTree < T > *rightRotation( avlTree < T > *tree)
{
	avlTree < T > *leftRoot = tree->left;
	avlTree < T > *rightOfLeftRoot = leftRoot->right;

	tree->left = rightOfLeftRoot;
	leftRoot->right = tree;
	return leftRoot;
}

template < class T >
avlTree < T > *leftRotation( avlTree < T > *tree)
{
	avlTree < T > *rightRoot = tree->right;
	avlTree < T > *leftOfRightRoot = rightRoot->left;

	tree->right = leftOfRightRoot;
	rightRoot->left = tree;
	return rightRoot;
}
template < class U >
void insert( avlTree< U > **tree, U val )
{
	int balanceFactor;

	if (*tree == NULL)
	{
		*tree = createNode( val );
		return ;
	}
	if (val > (*tree)->data && (*tree)->right != NULL)
		insert(&(*tree)->right, val);
	else if (val < (*tree)->data && (*tree)->left != NULL)
		insert(&(*tree)->left, val);
	else if (val > (*tree)->data && (*tree)->right == NULL)
		(*tree)->right = createNode(val);
	else if (val < (*tree)->data && (*tree)->left == NULL)
		(*tree)->left = createNode(val);
	else if (val == (*tree)->data)
		return ;
	balanceFactor = calculateHeightRecursively((*tree)->left) - calculateHeightRecursively((*tree)->right);
	if (balanceFactor > 1 && val < (*tree)->left->data)
		*tree = rightRotation(*tree);
	else if (balanceFactor < -1 && val > (*tree)->right->data)
		*tree = leftRotation(*tree);
	else if (balanceFactor > 1 && val > (*tree)->left->data)
	{
		(*tree)->left = leftRotation((*tree)->left);
		(*tree) = rightRotation(*tree);
	}
	else if (balanceFactor < -1 && val < (*tree)->right->data)
	{
		(*tree)->right = rightRotation((*tree)->right);
		(*tree) = leftRotation(*tree);
	}

}

// template < class T >
// int calculateHeightRecursively( avlTree< T > *treeRoot )
// {
// 	if (treeRoot == NULL)
// 		return 0;
// 	return (std::max(calculateHeightRecursively(treeRoot->left), calculateHeightRecursively(treeRoot->right)) + 1);
// }

template < class T >
int calculateHeightIteratively( avlTree< T > *treeRoot )
{
	int height = 0, howManyNodes = 0;
	std::queue< avlTree< T >* > q;

	if (treeRoot == NULL)
		return 0;
	q.push(treeRoot);
	while (q.size() > 0)
	{
		howManyNodes = q.size();
		while (howManyNodes > 0)
		{
			treeRoot = q.front();
			q.pop();
			if (treeRoot->right)
				q.push(treeRoot->right);
			if (treeRoot->left)
				q.push(treeRoot->left);
			howManyNodes--;
		}
		height += 1;
	}
	return height;
}

template < class T >
void printS( T data, int level )
{
	if (level == 0)
		for (int i = 0; i < 50; i++)
			std::cout << " ";
	else if (level == 1)
		for (int i = 0; i < 40; i++)
			std::cout << " ";
	else if (level == 2)
		for (int i = 0; i < 30; i++)
			std::cout << " ";
	else if (level == 3)
		for (int i = 0; i < 20; i++)
			std::cout << " ";
	else if (level == 4)
		for (int i = 0; i < 10; i++)
			std::cout << " ";
	std::cout << data;
}

template < class T >
void printLevelByLevel( avlTree< T > *treeRoot )
{
	std::queue< avlTree< T> * > q;
	int howManyNodes;

	if (treeRoot == NULL)
		return ;
	q.push(treeRoot);
	while (q.size() > 0)
	{
		howManyNodes = q.size();
		while (howManyNodes > 0)
		{
			treeRoot = q.front();
			q.pop();
			std::cout << treeRoot->data << " ";
			if (treeRoot->left)
				q.push(treeRoot->left);
			if (treeRoot->right)
				q.push(treeRoot->right);
			howManyNodes--;
		}
		std::cout << "\n";
	}
}

class test
{
	private :
		int num;
		std::string s;

	public :
		test() : num(0) { std::cout << num << s << std::endl; };
		test( int n ) : num(n) { }
		~test() {};
		bool operator<( const test &rhs ) { return num < rhs.getNum(); }
		int getNum( void ) const { return num; }
};

int main( void )
{
	ft::map<std::string, int> mapTest;
	avlTree < ft::pair<std::string, int> > tmp;

	mapTest.insert(ft::make_pair("Bob", 20));
	// ft::pair<>
	// test.test1.insert(ft::make_pair(12, 3));
	// test1.insert(std::make_pair(obj2, 20));
	// test1.insert(ft::make_pair("Bob", 21));
	return 0;
}