# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 13:22:38 by akuzmenk          #+#    #+#              #
#    Updated: 2023/10/24 16:19:14 by akuzmenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := megaphone
FLAGS := -std=c++98 -Wall -Wextra -Werror
SRCS := megaphone.cpp

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(SRCS)
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: clean fclean re
