# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 16:33:27 by akuzmenk          #+#    #+#              #
#    Updated: 2024/03/05 16:16:32 by akuzmenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := PmergeMe
FLAGS := -Wall -Wextra -Werror #-std=c++98
SRCS := 		\
		main.cpp \
		PmergeMe.cpp

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
