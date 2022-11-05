NAME = main

SRCS = main.cpp

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(SRCS)

clean :
	rm -f $(NAME)

re : clean all