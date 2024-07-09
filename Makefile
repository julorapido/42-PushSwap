NAME = push_swap
SRC = push_swap.c t_stack.c sort.c insertion.c operations.c utils.c radix.c alg.c 
SRC_OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra 

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I./includes -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(SRCS_OBJS)
	gcc $(FLAGS) $(SRC) $(INCLUDES) -o $(NAME) $(LIBFT)

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
