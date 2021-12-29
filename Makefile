# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 12:49:30 by gvarys            #+#    #+#              #
#    Updated: 2021/12/28 11:48:01 by gvarys           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

CC				= gcc
CFALGS			= -O2 -Wall -Wextra -Werror -g3

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

OBJS			= $(patsubst %.c, %.o, $(addprefix $(SRC_DIR), $(SRC_FILES)))

all:			$(LIBFT) $(NAME)

$(NAME):		$(OBJS) $(HEADER)
					$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $@

$(SRC_DIR)%.o:		$(SRC_DIR)%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean:		clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
