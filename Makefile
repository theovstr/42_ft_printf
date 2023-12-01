# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 10:34:18 by ael-mank          #+#    #+#              #
#    Updated: 2023/11/30 10:03:30 by ael-mank         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME		= libftprintf.a
INCLUDE		= include
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I$(INCLUDE) # Added $(INCLUDE) to include directory
RM			= rm -f
AR			= ar rcs

# Sources

SRC_FILES	= ft_printf ft_printchars ft_printptr minilibft


SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# Rules

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all
