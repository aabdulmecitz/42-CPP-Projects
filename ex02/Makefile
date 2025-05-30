NAME = account
TESTS = tests.cpp

SRC = account.cpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 

$(NAME):
	$(CC) $(FLAGS) $(SRC) $(TESTS) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(NAME)
fclean: clean
	@rm -f $(NAME)
re:  fclean all

.PHONY: all clean fclean re