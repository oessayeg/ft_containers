#pragma once

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

            public :
                avlTree( ) { }

                avlTree( P toInit, avlTree *parent ) : data(toInit), right(NULL),
                left(NULL), parent(parent) { }

                ~avlTree( ) { }
        };
}