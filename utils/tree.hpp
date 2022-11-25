#pragma once

#define BEGIN 1
#define END 2

namespace ft
{
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
                avlTree( ) { }

                avlTree( P toInit, avlTree *parent ) : data(toInit), right(NULL),
                left(NULL), parent(parent), height(0) { }

                ~avlTree( ) { }
        };
}