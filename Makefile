NAME = main

SRCS = main.cpp

HEADERS = vector/vector.hpp vector/vector_iterator.hpp \
		map/map.hpp map/map_iterator.hpp stack/stack.hpp \
		set/set.hpp set/set_iterator.hpp \
		utils/algorithm.hpp utils/avlTree.hpp \
		utils/functional.hpp utils/iterator_traits.hpp \
		utils/redBlackTree.hpp utils/reverse_iterator.hpp \
		utils/type_traits.hpp utils/utility.hpp

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(SRCS) $(HEADERS)
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean :
	rm -f $(NAME)

fclean : clean

re : clean all

.PHONY : all clean fclean re