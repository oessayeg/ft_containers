#include <vector>
#include "vector.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <iterator>

template < class vector >
void print( vector vect )
{
	for (typename vector::iterator b = vect.begin(); b != vect.end(); b++)
		std::cout << *b << " ";
	std::cout << std::endl;
}

template < class vector >
void t( vector vec )
{
	std::cout << "Size = " << vec.size() << std::endl;
	std::cout << "Capacity = " << vec.capacity() << std::endl;
	print(vec);
}

//Class from unit test
class B {
public:
    char *l;
    int i;
    B():l(nullptr), i(1) {};
    B(const int &ex) {
        this->i = ex;
        this->l = new char('a');
    };
    virtual ~B() {
        delete this->l;
        this->l = nullptr;
    };
};

class A : public B {
public:
    A():B(){};
    A(const B* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
        delete this->l;
        this->l = nullptr;
    };
};

template < class T >
void testFunction( void )
{
	T v, tmp, vector;
    tmp.assign(2600 * 10000, 1);
    vector.assign(4200 * 10000, 1);
    vector.insert(vector.end() - 1000 * 10000, tmp.begin(), tmp.end());
    v.push_back(vector[3]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());

    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    std::vector<A> vv;
    std::vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
        v.push_back(vv.size());
        v.push_back(vv.capacity());
    }
}

int main( void )
{
	{
		testFunction< std::vector<int> >();
	}

	{
		testFunction< ft::vector<int> >();
	}
	return 0;
}