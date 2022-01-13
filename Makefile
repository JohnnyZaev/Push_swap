# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 12:49:30 by gvarys            #+#    #+#              #
#    Updated: 2022/01/13 15:18:34 by gvarys           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
NAME_BONUS		= checker

CC				= gcc
CFALGS			= -O2 -Wall -Wextra -Werror

RM				= rm -rf

LIBFT_DIR		= Libft/
LIBFT			= $(LIBFT_DIR)libft.a

SRC_DIR			= src/

HEADER			= $(SRC_DIR)push_swap.h

SRC_FILES		= push_swap.c\
				init.c\
				valid.c\
				full_stacks.c\
				mini_sort.c\
				operations.c\
				operations1.c\
				operations2.c\
				quicksort.c\
				big_sort.c\
				big_sort_utils.c\

SRC_BONUS		= checker.c\
				init.c\
				valid.c\
				full_stacks.c\
				operations.c\
				operations1.c\
				operations2.c\
				quicksort.c\

OBJS			= $(patsubst %.c, %.o, $(addprefix $(SRC_DIR), $(SRC_FILES)))

OBJS_BONUS		= $(patsubst %.c, %.o, $(addprefix $(SRC_DIR), $(SRC_BONUS)))

all:			$(LIBFT) $(NAME)

bonus:			$(LIBFT) $(NAME_BONUS)

$(NAME):		$(OBJS) $(HEADER)
					$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $@

$(NAME_BONUS):		$(OBJS_BONUS) $(HEADER)
					$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft -o $@

$(SRC_DIR)%.o:		$(SRC_DIR)%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	make -C $(LIBFT_DIR) clean

fclean:		clean
	$(RM) $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
