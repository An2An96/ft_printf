NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRC_DIR = ./srcs
OBJ_DIR = ./obj
INC_DIR = ./includes

SRC = ft_printf.c
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

all:
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $<
	ranlib $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $(FLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re