# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 21:16:06 by nandreev          #+#    #+#              #
#    Updated: 2025/05/07 16:44:57 by nandreev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = c++



# hey hey, I think I figured out why you see g++ when using make : I think you are missing these lines in your makefile :
# %.o: %.cpp
# 	$(CC) $(CPPFLAGS) -c $< -o $@
# without this rule on how to compile the .o files, it defaults to the default (g++) instead of c++



# Compiler flags
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRCS = main.cpp Harl.cpp

OBJS = $(SRCS:.cpp=.o)

# Executable name
NAME = harl

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re