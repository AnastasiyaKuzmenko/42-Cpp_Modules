# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 16:33:27 by akuzmenk          #+#    #+#              #
#    Updated: 2024/02/27 11:49:38 by akuzmenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := easyfind
FLAGS := -Wall -Wextra -Werror #-std=c++98
SRCS := 		\
		main.cpp

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: clean fclean re
