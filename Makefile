# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 13:36:46 by ahmaymou          #+#    #+#              #
#    Updated: 2023/01/08 20:12:54 by ahmaymou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PUSH_SWAP

SRCS_OBJ = $(shell ls | grep .c | grep -v main | grep -v chec)
SRC = main.c
SRC_B = main_bonus.c

FLAGS = -Wall -Werror -Wextra

CC = cc

LIBS = libft.a libftprintf.a

EXEC = push_swap
EXEC_B = checker

OBJ = $(SRCS_OBJ:.c=.o)

all : $(NAME)

%.o: %.c push_swap.h
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : libft_printf prog

libft_printf :
	@cd libft && make bonus && mv libft.a ..
	@cd printf && make re && mv libftprintf.a .. && cd ..

prog :  $(OBJ) push_swap.h
	$(CC) $(FLAGS) $(SRC) $(OBJ) $(LIBS) -o $(EXEC)

bonus : $(NAME) checker_prog

checker_prog : push_swap.h
	$(CC) $(FLAGS) $(SRC_B) $(OBJ) $(LIBS) -o $(EXEC_B)
	@rm -rf $(LIBS)

clean :
	@cd libft && make clean
	@cd printf && make clean
	@rm -rf $(OBJ)
fclean : clean
	@rm -rf $(LIBS) $(EXEC) $(EXEC_B)

re : fclean all
re_bonus: fclean bonus

.PHONY : all clean fclean re