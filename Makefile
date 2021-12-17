# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#              #
#    Updated: 2021/11/29 04:39:38 by ykosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 4inrow
SRC		= main.c map.c disp.c ctrl.c kbhit.c
CFLAGS	= -g -fsanitize=address -Wall -Wextra -Werror
CC		= gcc
RM		= rm -f

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^
all: $(NAME)
bonus: $(BONUS)
clean:
	$(RM) $(OBJ)
fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
