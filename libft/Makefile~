NAME = libftprintf.a

FLAGS = -g #-Wall -Werror -Wextra

INC_DIR = ./includes
SRC_DIR = ./srcs
OBJ_DIR = ./obj
TMP_DIR = ./tmp

SRC =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar.c ft_putstr.c \
		ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
		ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
		ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c \
		ft_strlower.c ft_strupper.c \
		ft_memalloc.c ft_memdel.c ft_memdel.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		ft_itoa_base.c ft_itoa.c ft_dtoa.c ft_putendl.c ft_putnbr.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_strnew.c ft_printchr.c ft_str_fixlen.c \
		ft_pow.c ft_stoa.c ft_str_fixlen.c ft_uitoa_base.c \
		ft_printf.c additional.c type_handlers.c pf_itoa_base.c \
		spec_percent.c spec_di.c spec_o.c spec_u.c spec_hex.c \
		spec_f.c spec_s.c spec_c.c spec_p.c spec_b.c spec_n.c 
		
		#ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c
		#ft_lstmap.c ft_lstpush.c ft_lstremove.c
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Building...\n"
	@ar rc $@ $^
	@ranlib $@
	@echo "Build complete"

$(OBJ_DIR)/%.o: $(TMP_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -I $(INC_DIR) -c $< -o $@

copy:
	@mkdir -p $(TMP_DIR)
	@cp -f $(SRC_DIR)/libc/*.c $(TMP_DIR)
	@cp -f $(SRC_DIR)/additional/*.c $(TMP_DIR)
	@cp -f $(SRC_DIR)/bonus/*.c $(TMP_DIR)
	@cp -f $(SRC_DIR)/extend/*.c $(TMP_DIR)
	@cp -f $(SRC_DIR)/printf/*.c $(TMP_DIR)
	@echo "Source files copied to root"

test:
	@$(MAKE)
	@gcc $(FLAGS) -I $(INC_DIR) -L. -lftprintf main.c
	@echo "Tests build"

clean:
	@echo "Object files cleared"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(TMP_DIR)
	@rm -f $(NAME)
	@echo "Build cleared"

re: fclean copy all

.PHONY: all clean fclean re