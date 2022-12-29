# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blackhole <blackhole@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 18:47:21 by ahmaymou          #+#    #+#              #
#    Updated: 2022/12/27 19:25:10 by blackhole        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = $(shell ls | grep .c)

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJECT = $(SRC:.c=.o)

BONUS_OBJECT = $(BONUS_SRC:.c=.o)

CC = cc

# echo1 = @echo "\033[92mCompiled all the files successfully !!! :) \033[0m"
# echo2 = @echo "\033[92mCompiled bonus files successfully !!! :) \033[0m"
# echo3 = @echo "\033[36mArchive created successfully !!! :) \033[m"
# echo4 = @echo "\033[31mbonus added to the archive successfully !!! :) \033[m"

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o: %.c libft.h
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJECT) libft.h
	@ar rc $(NAME) $(OBJECT)

bonus : $(NAME) $(BONUS_OBJECT)
	@ar rc $(NAME) $(OBJECT) $(BONUS_OBJECT)

clean :
	@rm -f $(OBJECT) $(BONUS_OBJECT)

fclean : clean
	@rm -f $(NAME)

re : fclean all

re_b:fclean bonus
	

#a : all bonus
	
#.PHONY : clean fclean all re bonus