#include <utility>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include "vector/vector.hpp"
#include "map/map.hpp"
#include "stack/stack.hpp"
#include "set/set.hpp"
#include "utils/utility.hpp"
#include "sys/time.h"

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

template < class C >
void printContent( C m_container )
{
    typename C::iterator b;
    typename C::iterator e;

    b = m_container.begin();
    e = m_container.end();

    std::cout << "Size = " << m_container.size() << std::endl;
    std::cout << "Capacity = " << m_container.capacity() << std::endl;
    for (; b != e; b++)
        std::cout << *b << " ";
    std::cout << std::endl;
}

template < class C >
void printContentRev( C m_container )
{
    typename C::reverse_iterator b;
    typename C::reverse_iterator e;

    b = m_container.rbegin();
    e = m_container.rend();

    std::cout << "Size = " << m_container.size() << std::endl;
    std::cout << "Capacity = " << m_container.capacity() << std::endl;
    for (; b != e; b++)
        std::cout << *b << " ";
    std::cout << std::endl;
}

int main ( void )
{
    ft::vector< int > m_vec1(10, 12);
    ft::vector< int > m_vec2(m_vec1);
    ft::vector< int >::const_iterator c_it1, c_it2;

    m_vec2 = m_vec1;
    for (int i = 0; i < 10; i++)
        m_vec2[i] = i + 3;

    std::cout << "-----m_vec1-----" << std::endl;
    printContent(m_vec1);
    std::cout << std::endl;

    m_vec2.push_back(13);
    m_vec2.push_back(14);
    m_vec2.pop_back();
    std::cout << "-----m_vec2-----" << std::endl;
    printContent(m_vec2);
    std::cout << std::endl;

    std::cout << "-----m_vec1-----" << std::endl;
    printContentRev(m_vec1);
    std::cout << std::endl;

    std::cout << "-----m_vec2-----" << std::endl;
    printContentRev(m_vec2);
    std::cout << std::endl;
    
    // Range constructor
    std::cout << "------Range constructor on m_vec3------" << std::endl;
    ft::vector< int > m_vec3(m_vec2.begin(), m_vec2.end() - 4);
    printContentRev(m_vec3);

    std::cout << "\nMax_size : " << m_vec1.max_size() << std::endl << std::endl;
    
    std::cout << "\nComparing non-const and const iterators\n" << std::endl;

    c_it1 = m_vec2.begin();
    c_it2 = m_vec2.end();

    std::cout << std::boolalpha;
    std::cout << (c_it1 == m_vec2.begin()) << std::endl;
    std::cout << (c_it1 != m_vec2.begin()) << std::endl;
    std::cout << (c_it1 > m_vec2.end() - 2) << std::endl;
    std::cout << (c_it1 < m_vec2.begin() + 2) << std::endl;
    std::cout << (c_it1 >= m_vec2.begin()) << std::endl;
    std::cout << (c_it1 <= --m_vec2.end()) << std::endl;

    std::cout << "-----Resize + Reserve-------\n" << std::endl;

    ft::vector< int > testV;

    testV.reserve(20);
    printContent(testV);

    testV.insert(testV.begin(), m_vec2.begin(), m_vec2.end() - 1);
    printContentRev(testV);

    testV.resize(5);
    std::cout << "After resizing\n";
    printContentRev(testV);

    std::cout << "----[], front, back, data----\n" << std::endl;
    ft::vector< int > vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    std::cout << "Front : " << vec.front() << std::endl;
    std::cout << "Back : " << vec.back() << std::endl;
    std::cout << "Data (dereferenced) : " << *vec.data() << std::endl;

    vec.clear();
    std::cout << "----Assign----" << std::endl;
    vec.assign(testV.begin(), testV.end());
    std::cout << std::endl;
    printContent(vec);


    std::cout << "\n\n-------STACK-------\n" << std::endl;

    ft::stack < int > m_stack1;
    ft::stack < int > m_stack2;

    m_stack1.push(1);
    m_stack1.push(2);
    m_stack1.push(3);

    m_stack2.push(10);
    m_stack2.push(20);
    m_stack2.push(30);

    std::cout << m_stack1.top() << std::endl;
    std::cout << m_stack2.top() << std::endl << std::endl;

    std::cout << std::boolalpha;
    std::cout << (m_stack1 > m_stack2) << std::endl;
    std::cout << (m_stack1 < m_stack2) << std::endl;
    std::cout << (m_stack1 >= m_stack2) << std::endl;
    std::cout << (m_stack1 <= m_stack2) << std::endl;
    std::cout << (m_stack1 == m_stack2) << std::endl;
    std::cout << (m_stack1 != m_stack2) << std::endl;

    while (!m_stack1.empty())
    {
        m_stack1.pop();
        m_stack2.pop();
    }

    m_stack1.push(10);
    m_stack1.push(20);
    m_stack2.push(10);
    m_stack2.push(20);

    std::cout << "\n\n";
    std::cout << (m_stack1 > m_stack2) << std::endl;
    std::cout << (m_stack1 < m_stack2) << std::endl;
    std::cout << (m_stack1 >= m_stack2) << std::endl;
    std::cout << (m_stack1 <= m_stack2) << std::endl;
    std::cout << (m_stack1 == m_stack2) << std::endl;
    std::cout << (m_stack1 != m_stack2) << std::endl;


    std::cout << "\n\n-------MAP-------\n" << std::endl;

    ft::map< std::string, int > m_map1;
    ft::map< std::string, int >::iterator map_it1, map_it2;
    ft::map< std::string, int >::reverse_iterator rmap_it1, rmap_it2;

    m_map1.insert(ft::make_pair("Bob", 21));
    m_map1.insert(ft::make_pair("Ali", 12));
    m_map1.insert(ft::make_pair("Xo", 71));
    m_map1.insert(ft::make_pair("Mall", 4));
    m_map1.insert(ft::make_pair("Relax", 15));

    map_it1 = m_map1.begin();
    map_it2 = m_map1.end();
    std::cout << "Size = " << m_map1.size() << std::endl;
    for (; map_it1 != map_it2; map_it1++)
        std::cout << "key : " << map_it1->first << " -- value : " << map_it1->second << std::endl;
    std::cout << std::endl;


    std::cout << "Printing with reverse_iterator" << std::endl;
    rmap_it1 = m_map1.rbegin();
    rmap_it2 = m_map1.rend();
    for (; rmap_it1 != rmap_it2; rmap_it1++)
        std::cout << "key : " << rmap_it1->first << " -- value : " << rmap_it1->second << std::endl;
    std::cout << std::endl;


    std::cout << m_map1.lower_bound("Ali")->first << std::endl;
    std::cout << m_map1.upper_bound("Ali")->first << std::endl;

    std::cout << "\n----count-----" << std::endl;
    std::cout << m_map1.count("ds") << std::endl;
    std::cout << m_map1.count("Ali") << std::endl;

    if (m_map1.find("Ali") == m_map1.end())
        std::cout << "Not found" << std::endl;
    else
        std::cout << "Found" << std::endl;

    m_map1.erase("Bob");
    map_it1 = m_map1.begin();
    map_it2 = m_map1.end();
    for (; map_it1 != map_it2; map_it1++)
        std::cout << "key : " << map_it1->first << " -- value : " << map_it1->second << std::endl;
    std::cout << std::endl;

    m_map1.clear();
    std::cout << "Size = " << m_map1.size() << std::endl;
    if (m_map1.find("Ali") == m_map1.end())
        std::cout << "Not found" << std::endl;
    else
        std::cout << "Found" << std::endl;


    //Time here
    // -----------------Vector-------------------
    // Constructor 
    time_t start, end;
    start = get_time();
    ft::vector< int > v_t1(100000000);
    end = get_time();
    std::cout << "Vector Constructor : " << end - start << std::endl;

    // Copy Constructor
    start = get_time();
    ft::vector< int > v_t3(v_t1);
    end = get_time();
    std::cout << "Vector Copy Constructor : " << end - start << std::endl;

    // Assign Range
    ft::vector< int > v_t2;
    start = get_time();
    v_t2.assign(v_t1.begin(), v_t1.end());
    end = get_time();
    std::cout << "Vector Assign_range : " << end - start << std::endl;

    // Erase
    start = get_time();
    v_t1.erase(v_t1.begin(), v_t1.end());
    end = get_time();
    std::cout << "Vector Erase_range : " << end - start << std::endl;

    // Resize
    start = get_time();
    v_t2.resize(1000);
    end = get_time();
    std::cout << "Vector Resize : " << end - start << std::endl;


    // -----------------Map-------------------
    ft::map< int, int > t_map1;

    // Insert
    start = get_time();
    for (unsigned long long i = 0; i < 10000000; i++)
        t_map1.insert(ft::make_pair(i, i));
    end = get_time();
    std::cout << "Map Insert : " << end - start << std::endl;

    // Copy Constructor
    start = get_time();
    ft::map < int, int > t_map2(t_map1);
    end = get_time();
    std::cout << "Map Copy constructor : " << end - start << std::endl;

    // Erase
    start = get_time();
    t_map1.erase(t_map1.begin(), t_map1.end());
    end = get_time();
    std::cout << "Map Erase Insert : " << end - start << std::endl;

    // [], at
    start = get_time();
    t_map2[10000] = 12;
    end = get_time();
    std::cout << "Map [ 1000 ] : " << end - start << std::endl;

    start = get_time();
    t_map2.at(10000) = 10;
    end = get_time();
    std::cout << "Map at( 1000 ) : " << end - start << std::endl;

    // Find
    start = get_time();
    t_map2.find(100000);
    std::cout << "Map Find : " << end - start << std::endl;
    end = get_time();


    // -----------------Set-------------------
    std::set < int > t_set;
    
    // Insert
    start = get_time();
    for (int i = 0; i < 10000000; i++)
        t_set.insert(i);
    end = get_time();
    std::cout << "Set Insert " << end - start << std::endl;

    // Erase key
    start = get_time();
    t_set.erase(534);
    t_set.erase(23);
    t_set.erase(1331214);
    t_set.erase(53214);
    end = get_time();
    std::cout << "Set Erase_key " << end - start << std::endl;

    // Contructor range
    start = get_time();
    ft::set < int > t_set2(t_set.begin(), t_set.end());
    end = get_time();
    std::cout << "Contructor_range " << end - start << std::endl;

    // Find
    start = get_time();
    t_set.find(100000);
    std::cout << "Set Find : " << end - start << std::endl;
    end = get_time();

    // Erase range
    start = get_time();
    t_set.erase(t_set.begin(), t_set.end());
    end = get_time();
    std::cout << "Erase_range " << end - start << std::endl;

    return 0;
}