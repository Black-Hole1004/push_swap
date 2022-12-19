# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 13:36:46 by ahmaymou          #+#    #+#              #
#    Updated: 2022/12/19 15:33:27 by ahmaymou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PUSH_SWAP

SRC = push_swap.c

FLAGS = -Wall -Werror -Wextra

CC = cc

LIBS = libft.a libftprintf.a

EXEC = push_swap

all : $(NAME)

$(NAME) : libft_printf prog

libft_printf :
	@cd libft && make bonus && mv libft.a ..
	@cd printf && make && mv libftprintf.a .. && cd ..

prog : $(SRC) push_swap.h
	$(CC) $(FLAGS) $(SRC) $(LIBS) -o $(EXEC)
	@rm -rf $(LIBS)

clean :
	rm -rf EXEC libft/*.o printf/*.o
fclean : clean
	@rm -rf $(LIBS)

re : fclean all

.PHONY : all clean fclean re
	
	