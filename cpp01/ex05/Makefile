NAME = harl

SRC = Harl.cpp main.cpp 

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(NAME)
fclean: clean

re: fclean all

.PHONY: all clean fclean re