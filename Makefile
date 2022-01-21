NAME =	roulette
SRC	=	roulette.cpp raddoppi.cpp
OB	=	$(SRC:.cpp=.o)
CC	=	clang++
FLG	=	-Wall -Wextra -Werror

%.o: %.cpp
	@$(CC) $(FLG) -c $^ -o $@

all:	$(NAME)

$(NAME): $(OB)
	@$(CC) $(FLG) $(OB) -o $(NAME)
	@echo "\033[1m$(NAME)\033[0m""\033[32m	Compiled\033[0m"

clean:
	@rm -rf $(OB)
	@rm -rf file.replace
	@echo "Objects ""\033[34m	Cleaned\033[0m"
fclean:	clean
	@rm -rf $(NAME)
	@echo "Project ""\033[31m	Cleaned\033[0m"
re:	fclean all

.PHONY:	re fclean clean all