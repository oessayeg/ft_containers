// #include "iterator_traits.hpp"

namespace ft
{
    template < class Iterator >
    class vectorIterator
    {
        public :
            typedef typename ft::iterator_traits< Iterator >::iterator_category iterator_category;
            typedef typename ft::iterator_traits< Iterator >::value_type value_type;
            typedef typename ft::iterator_traits< Iterator >::difference_type difference_type;
            typedef typename ft::iterator_traits< Iterator >::pointer pointer;
            typedef typename ft::iterator_traits< Iterator >::reference reference;
            typedef size_t size_type;

        private :
            pointer m_ptr;
        
        public :
            // Constructors, Destructor, assignment operator overload
            vectorIterator( pointer p = NULL ) : m_ptr(p) {}
            vectorIterator( const vectorIterator &rhs ) : m_ptr(rhs.getPtr()) {}
            vectorIterator &operator=( const vectorIterator &rhs )
            {
                m_ptr = rhs.getPtr();
                return *this;
            }
            ~vectorIterator() {}

            // Incrementation/Decrementation operators
            vectorIterator operator++( void )
            {
                ++m_ptr;
                return *this;
            }
            vectorIterator operator++( int )
            {
                vectorIterator tmp = *this;

                ++m_ptr;
                return tmp;
            }
            vectorIterator operator--( void )
            {
                --m_ptr;
                return *this;
            }
            vectorIterator operator--( int )
            {
                vectorIterator tmp = *this;

                --m_ptr;
                return tmp;
            }

            // Dereference operators
            reference operator*( void ) { return *m_ptr; }
            pointer operator->( void ) { return m_ptr; }


            // Pointer getter
            pointer getPtr( void ) { return m_ptr; }
    };
}