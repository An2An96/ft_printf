NAME = libftprintf.a

FLAGS = -g #-Wall -Werror -Wextra

LIB_DIR = ./libs
INC_DIR = ./includes
SRC_DIR = ./srcs
OBJ_DIR = ./obj

SRC = ft_printf.c spec_di.c spec_o.c spec_u.c spec_xX.c spec_s.c spec_c.c spec_p.c
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

vpath %.o $(OBJ_DIR)/

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Building..." '$(OBJ) > $(NAME)'
	ar rc $@ $^
	@ranlib $@
	@echo "Build complete"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Recompile source file"
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -I $(INC_DIR) -I $(LIB_DIR)/libft/includes -c $< -o $@

test: $(NAME) 
	#gcc $(FLAGS) -I $(LIB_DIR)/libft/includes -I $(INC_DIR) -L libs/libft -lft $(SRC_DIR)/*.c
	gcc $(FLAGS) -I $(LIB_DIR)/libft/includes -I $(INC_DIR) -L libs/libft -lft -L. -lftprintf main.c

clean:
	@echo "Object files cleared"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "Build cleared"

re: fclean all

.PHONY: all clean fclean re