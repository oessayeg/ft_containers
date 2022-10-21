#include <iostream>

class INT
{
	public :
		int nbr;
		INT( int n ) : nbr(n) {}
		~INT( void ) {};
		INT &operator=( INT &rhs )
		{
			if (this != &rhs)
				nbr = rhs.nbr;
			return *this;
		}
		// INT operator+( INT const &rhs )
		// {
		// 	nbr += rhs.nbr; 
		// 	return *this;
		// }
		int getNbr( void ) const { return nbr; }
};
INT operator+( INT const &lhs, INT const &rhs )
{
	INT ret = lhs;
	ret.nbr += rhs.nbr;
	return ret;
}

std::ostream &operator<<( std::ostream &o, INT const &rhs )
{
	o << rhs.getNbr();
	return o;
}

int main( void )
{
	INT test(40);

	std::cout << 10 + test << std::endl;
	return 0;
}
