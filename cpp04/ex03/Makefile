NAME = animal

CYAN = \033[1;36m
RESET = \033[0m

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS =	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp Brain.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

re: clean all

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

run: re
	@echo "$(CYAN)Result...$(RESET)"
	@./$(NAME)
	@rm -rf $(OBJS)

.PHONY: all clean re fclean run