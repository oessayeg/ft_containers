NAME = main

SRCS = main.cpp

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

all : $(NAME)

$(NAME) : $(SRCS)

clean :
	rm -f $(NAME)

re : clean all