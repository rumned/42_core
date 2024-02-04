NAME		= libftprintf.a
HEADER		= header
LIBFT		= libft
SRC_DIR		= src/
UTIL_DIR	= utils/
OBJ_DIR		= objft/
CC			= cc
CC_FLAGS	= -Wall -Wextra -Werror

# Update OBJ_FILES to include all source and utility files
SRC_FILES	= ft_printf.c
UTIL_FILES	= ft_print_i.c ft_print_s.c ft_print_u.c ft_print_x.c ft_print_p.c ft_print_c.c ft_bonus_hex.c
OBJ_FILES	= $(SRC_FILES:.c=.o) $(UTIL_FILES:.c=.o)
# Update the OBJ variable to include the full paths to object files
OBJ			= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
OBJF			= .cache_exists

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	echo "Compiling: $<"
	$(CC) $(CC_FLAGS) -I $(HEADER) -c $< -o $@

$(OBJ_DIR)%.o: $(UTIL_DIR)%.c | $(OBJ_DIR)
	echo "Compiling: $<"
	$(CC) $(CC_FLAGS) -I $(HEADER) -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cp libft/libft.a $(NAME)
	ar r $(NAME) $(OBJ)
	echo "ft_printf is compiled!"

$(OBJF):
	@mkdir -p $(OBJ_DIR)

all: $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT)
	echo "All objects are cleaned!"

fclean: clean
	@rm -f $(LIBFT)/libft.a
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
