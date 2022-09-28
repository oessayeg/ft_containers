NAME = main

SRCS = main.cpp

CPPFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS)

clean :
	rm -f $(NAME)

re : clean all