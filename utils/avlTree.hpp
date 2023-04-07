#pragma once

#define BEGIN 1
#define END 2

namespace ft
{
	// Base tree of the map
	template < class P >
	class avlTree
	{
		public :
			P data;
			avlTree *right;
			avlTree *left;
			avlTree *parent;
			size_t height;

		public :
 			avlTree( void ) : data(P()), right(NULL), left(NULL), parent(NULL), height(1) { }

			avlTree( P toInit, avlTree *parent ) : data(toInit), right(NULL),
				left(NULL), parent(parent), height(1) { }
				
			avlTree ( const avlTree &rhs ) : data(rhs.data), right(rhs.right),
				left(rhs.left), parent(rhs.parent), height(rhs.height) { }

			~avlTree( ) { }

		};
}