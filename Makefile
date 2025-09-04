# minilibx_test
NAME		=	fdf

# Compiler
CC			=	cc
CFLAGS		= 	-Wall -Wextra -Werror -Iincludes -g
INC 		= 	-Ilibft/includes
CFLAGS		+=	$(INC)

LIBFT_DIR	= libft

SRCS		=	main.c alloc_app_content.c draw_map.c prepare_map.c free_array.c \
				alloc_maps.c convert_map.c free_all_rcs.c manage_key_events.c refresh.c \
				convert_points.c ft_split_map.c mlx_app_work.c \
				direction_mono.c get_points_list.c  parse_map.c w_open_close.c \
				direction_shift.c vector_culc1.c vector_culc2.c set_map_3d.c\
				draw_line.c plus_minus_scale.c rotation_adjustment.c orthonormalize.c
OBJS 		=	$(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
MLX = libmlx_Linux.a -lXext -lX11 -lm -lz

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
			make -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re