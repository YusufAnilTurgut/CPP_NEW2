SRCS = main.cpp Classes.cpp
NAME = main

OBJS = $(SRCS:.cpp=.o)

CC = c++

RM = rm -rf

FLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) :	$(OBJS)
				$(CC) $(FLAGS) $(OBJS) -o $(NAME)

.cpp.o :
	@$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

clean :
				$(RM) $(OBJS)

fclean :		clean
				$(RM) $(NAME)

re : fclean all

.PHONY = all clean fclean re