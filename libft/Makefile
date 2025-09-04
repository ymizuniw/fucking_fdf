# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/20 00:00:00 by yourlogin         #+#    #+#              #
#    Updated: 2025/09/05 07:12:09 by ymizuniw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

INCLUDES = -Iincludes

SRCS	= \
	src/libft/ft_atoi.c src/libft/ft_bzero.c src/libft/ft_calloc.c src/libft/ft_isalnum.c \
	src/libft/ft_isalpha.c src/libft/ft_isascii.c src/libft/ft_isdigit.c src/libft/ft_isprint.c \
	src/libft/ft_itoa.c src/libft/ft_memchr.c src/libft/ft_memcmp.c src/libft/ft_memcpy.c \
	src/libft/ft_memmove.c src/libft/ft_memset.c src/libft/ft_putchar_fd.c src/libft/ft_putendl_fd.c \
	src/libft/ft_putnbr_fd.c src/libft/ft_putstr_fd.c src/libft/ft_split.c src/libft/ft_strchr.c \
	src/libft/ft_strdup.c src/libft/ft_striteri.c src/libft/ft_strjoin.c src/libft/ft_strlcat.c \
	src/libft/ft_strlcpy.c src/libft/ft_strlen.c src/libft/ft_strmapi.c src/libft/ft_strncmp.c \
	src/libft/ft_strndup.c src/libft/ft_strnstr.c src/libft/ft_strrchr.c src/libft/ft_strtrim.c \
	src/libft/ft_substr.c src/libft/ft_tolower.c src/libft/ft_toupper.c src/libft/ft_atoi_base.c \
	src/libft/ft_lstadd_back_bonus.c src/libft/ft_lstadd_front_bonus.c src/libft/ft_lstclear_bonus.c \
	src/libft/ft_lstdelone_bonus.c src/libft/ft_lstiter_bonus.c src/libft/ft_lstlast_bonus.c \
	src/libft/ft_lstmap_bonus.c src/libft/ft_lstnew_bonus.c src/libft/ft_lstsize_bonus.c \
	src/get_next_line/get_next_line.c src/get_next_line/get_next_line_utils.c \
	src/ft_printf/ft_printf.c \
	src/ft_printf/parse_format/manage_flag_conflict.c src/ft_printf/parse_format/manage_flag_spec.c \
	src/ft_printf/parse_format/parse_flags.c src/ft_printf/parse_format/parse_format.c \
	src/ft_printf/parse_format/parse_format_utils.c src/ft_printf/parse_format/parse_precision.c \
	src/ft_printf/parse_format/parse_specifier.c src/ft_printf/parse_format/parse_width.c \
	src/ft_printf/parse_args_utils/ft_ctoa.c src/ft_printf/parse_args_utils/ft_is_upper.c \
	src/ft_printf/parse_args_utils/ft_itoa_abs.c src/ft_printf/parse_args_utils/ft_ptoa.c \
	src/ft_printf/parse_args_utils/ft_utoa.c src/ft_printf/parse_args_utils/ft_xtoa.c \
	src/ft_printf/parse_args/parse_args.c src/ft_printf/parse_args/arg_to_spec.c \
	src/ft_printf/tokenize/init_free_token.c src/ft_printf/tokenize/tokenize_format.c \
	src/ft_printf/apply_format/apply_format.c src/ft_printf/apply_format/set_count_utils.c \
	src/ft_printf/apply_format/set_output_str.c \
	src/ft_printf/output/output_list.c src/ft_printf/output/output_token.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
