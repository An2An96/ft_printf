NAME = libftprintf.a

FLAGS = -g #-Wall -Werror -Wextra

LIB_DIR = ./libs
INC_DIR = ./includes
SRC_DIR = ./srcs
OBJ_DIR = ./obj

SRC = ft_printf.c spec_c.c #ft_spec.c
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

all:
	#@$(MAKE) -C $(LIB_DIR)/libft
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	@echo "Building..."
	@ar rc $@ $<
	@ranlib $@
	@echo "Build complete"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Recompile source file"
	@gcc $(FLAGS) -I $(INC_DIR) -I $(LIB_DIR)/libft/includes -c $< -o $@

test:
	gcc $(FLAGS) -I $(LIB_DIR)/libft/includes -I $(INC_DIR) -L. -L libs/libft -lft -lftprintf main.c

clean:
	@$(MAKE) clean -C $(LIB_DIR)/libft
	@echo "Object files cleared"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)/libft
	@rm -f $(NAME)
	@echo "Build cleared"

re: fclean all

.PHONY: all clean fclean re