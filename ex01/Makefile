CC = c++
CFLAGS = -Wall -Wextra -Werror -ggdb -std=c++98
RM = rm -f

NAME = scavtrap

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp

OBJS = $(SRCS:.cpp=.o)

INCS = ClapTrap.hpp ScavTrap.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

leaks: $(NAME)
	valgrind --leak-check=full ./$(NAME)

re: fclean all

.PHONY: all clean fclean leaks re