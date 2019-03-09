############################		Variables		############################
NAME = libftprintf.a

LIBFT_DIR = ../libft

INC_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./obj

C_INCLUDE_PATH += includes/
C_INCLUDE_PATH += $(LIBFT_DIR)/includes

FLAGS = -Wall -Werror -Wextra
FLAGS += $(foreach path,$(C_INCLUDE_PATH),-I$(path))

SRCS_FILES =	ft_printf.c parse_body.c additional.c \
				unicode_utils.c extend_itoa.c \
				spec_c.c spec_s.c spec_p.c spec_percent.c \
				spec_di.c spec_o.c spec_u.c spec_hex.c \
				spec_f.c spec_e.c spec_a.c \
				spec_b.c spec_n.c ft_numtohex.c \
				spec_g.c

SRCS =	$(foreach file,$(SRCS_FILES),$(SRCS_DIR)/$(file))

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS_FILES:%.c=%.o))
OBJS += $(foreach func,$(LIBFT_FUNCS),$(OBJS_DIR)/libft/ft_$(func).o)

FLAGS += $(foreach fun,$(LIBFT_FUNS),-Dft_$(fun)=ft_printf_libft_$(fun))

############################		  Rules 		############################

all: $(NAME)

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	@mkdir -p $@
	@mkdir -p $@/libft

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@gcc $(FLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	@echo "Building...\n"
	@ar rc $@ $^
	@ranlib $@
	@echo "Build complete"

test: all
	@gcc -Iincludes/ -Ilibft/includes -L$(LIBFT_DIR) -lft -L. -lftprintf main.c
	@echo "Tests build"

clean:
	@echo "Object files cleared"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "Build cleared"

re: fclean all

.PHONY: all clean fclean re

#	by rschuppe