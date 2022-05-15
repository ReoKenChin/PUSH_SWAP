# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcherki <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 11:58:30 by mcherki           #+#    #+#              #
#    Updated: 2022/05/15 11:59:04 by mcherki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CHECKER = checker
INC = push_swap.h

CFLAGS = -Wall -Wextra -Werror

M_SRCS = utils.c \
		operation.c \
		moves.c \
		sort_small_nb.c \
		push_swap_utils.c \
		ft_split.c \
		get_next_line.c \
		sort_small_nb.c \
		sort2.c \
		utils2.c \
		putstr.c \
		utils3.c \
		longest_increasing_sub.c \
		args.c \
		push_swap.c\
		
M_SRCB = args.c\
		operation.c \
		moves.c\
		push_swap_utils.c \
		ft_split.c\
		putstr.c \
		get_next_line.c\
		utils.c\
		checker.c

M_OBJS = $(M_SRCS:.c=.o)

M_OBJB = $(M_SRCB:.c=.o)

all : $(NAME)

$(NAME) : $(M_OBJS)
	$(CC) $(CFLAGS) $^ -o $@


%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
	
bonus : $(CHECKER) $(NAME)

$(CHECKER) : $(M_OBJB)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -rf $(M_OBJS) $(M_OBJB)

fclean: clean
	rm -rf $(NAME) $(CHECKER)

re: fclean all
