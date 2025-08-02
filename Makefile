# minilibx_test
NAME		=	fdf

# Compiler
CC			=	cc
CFLAGS		= 	-Wall -Wextra -Werror -Iincludes
INC 		= 	-Iincludes -Ilibft

LIBFT_DIR	= libft

SRCS		=	main.c free_all_rcs.c put_pixel.c
OBJS 		=	$(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
MLX = includes/libmlx_Linux.a -lXext -lX11 -lm -lz

# Rules
all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(INC) -o $(NAME)

$(LIBFT):
		make -C $(LIBFT_DIR)

clean:
			$(RM) $(OBJS)
			make clean -C $(LIBFT_DIR)

fclean:		clean
			rm -f $(NAME)
			make fclean $(LIBFT_DIR)

re:			fclean all

.PHONY:		all clean fclean re