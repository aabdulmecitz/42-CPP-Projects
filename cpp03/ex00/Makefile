NAME = claptrap

CYAN = \033[1;36m
RESET = \033[0m

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp ClapTrap.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

re: clean all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

run: re
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@rm -rf $(OBJS)
	@echo "$(CYAN)Result...$(RESET)"
	@./$(NAME)

.PHONY: all clean re fclean run