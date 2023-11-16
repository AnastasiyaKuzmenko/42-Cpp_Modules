# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 13:22:38 by akuzmenk          #+#    #+#              #
#    Updated: 2023/10/17 12:24:40 by akuzmenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := phonebook
FLAGS := -Wall -Wextra -Werror -std=c++98
SRCS := 		\
		Contact.cpp \
		PhoneBook.cpp \
		add_contact.cpp \
		search_contact.cpp \
		main.cpp	

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
