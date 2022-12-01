#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "utils/avlTree.hpp"
#include <iterator>
#include <sys/time.h>
#include <map>
#include <cmath>
#include "map.hpp"
#include "utils/functional.hpp"
#include <utility>
#include "vector.hpp"
#include "stack.hpp"
#include "set.hpp"
#include "utils/redBlackTree.hpp"

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    return (msecs_time);
}

template < class T >
class example
{
    private :
        int num;
    public :
        example( ) { num = 42; }
        ~example( ) { }
        template < class U, class V >
        friend bool operator<( U const &lhs, V const &rhs )
        {
            return lhs.num < rhs.num;
        }
};

#include <set>
int		main(void)
{
    ft::redBlackTree< int, ft::less< int >, std::allocator< int > > root;

    root.insert(50);
    root.insert(30);
    root.insert(60);
    root.insert(65);
    root.insert(70);
    root.erase(30);
    root.printLevels();
	return (0);
}
