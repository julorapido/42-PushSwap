NAME = push_swap
BONUS = checker
SRC = push_swap.c t_stack.c sort.c operations.c utils.c z_sort.c
SRC_BONUS = checker.c t_stack.c sort.c operations.c utils.c z_sort.c

SRC_OBJ = $(SRC:.c=.o)
SRC_BONUS_OBJ = $(SRC_BONUS.c=.o)

FLAGS = -Wall -Wextra 

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I./includes -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)
bonus: $(LIBFT) $(BONUS)

$(NAME): $(SRCS_OBJS)
	gcc $(FLAGS) $(SRC) $(INCLUDES) -o $(NAME) $(LIBFT)

$(BONUS): $(SRC_BONUS_OBJ)
	gcc $(FLAGS) $(SRC_BONUS) $(INCLUDES) -o $(BONUS) $(LIBFT)

$(LIBFT):
	@echo "LIBFT IN MAKING..."
	@make all -C $(LIBFT_DIR)

clean :
	@echo "Removing .o files"
	rm -f $(SRC_OBJ)
	@make clean -C $(LIBFT_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all
