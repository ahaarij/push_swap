# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 16:43:46 by ahaarij           #+#    #+#              #
#    Updated: 2024/04/15 08:36:27 by ahaarij          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -g3 -fsanitize=address
LIBFT_DIR = libft
LIBFT = ./libft/libft.a
RM = rm -rf
SRCS = a.c utils.c move.c sort.c
SRC = $(addprefix ./srcs/,$(SRCS))
OBJ = $(SRC:.c=.o)
GREY		= $'\x1b[30m
RED			= $'\x1b[31m
GREEN		= $'\x1b[32m
YELLOW		= $'\x1b[33m
BLUE		= $'\x1b[34m
PURPLE		= $'\x1b[35m
CYAN		= $'\x1b[36m
WHITE		= $'\x1b[37m


define HEADER

 _____                                                                                                     _____ 
( ___ )---------------------------------------------------------------------------------------------------( ___ )
 |   |                                                                                                     |   | 
 |   | .______    __    __       _______. __    __          _______.____    __    ____  ___      .______   |   | 
 |   | |   _  \  |  |  |  |     /       ||  |  |  |        /       |\   \  /  \  /   / /   \     |   _  \  |   | 
 |   | |  |_)  | |  |  |  |    |   (----`|  |__|  |       |   (----` \   \/    \/   / /  ^  \    |  |_)  | |   | 
 |   | |   ___/  |  |  |  |     \   \    |   __   |        \   \      \            / /  /_\  \   |   ___/  |   | 
 |   | |  |      |  `--'  | .----)   |   |  |  |  |    .----)   |      \    /\    / /  _____  \  |  |      |   | 
 |   | | _|       \______/  |_______/    |__|  |__|    |_______/        \__/  \__/ /__/     \__\ | _|      |   | 
 |___|                                                                                                     |___| 
(_____)---------------------------------------------------------------------------------------------------(_____)

endef
export HEADER

all: $(LIBFT) $(NAME) 
	@echo ""
	@echo "${GREEN}$$HEADER"
	@echo "$(YELLOW)Created: $(words $(OBJ)) object file(s) for push_swap"
	@echo "$(YELLOW)Created: $(NAME)$(RESET)"


$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFT_DIR) -lft

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $? -I./$(LIBFT_DIR)
	@mv a.o srcs
	@mv move.o srcs
	@mv utils.o srcs
	@mv sort.o srcs

clean:	
	@$(RM) $(OBJ)
	@make -s -C $(LIBFT_DIR) clean
	@echo ""
	@echo "${RED}$$HEADER"
	@echo "$(YELLOW)Removed: $(words $(OBJ)) object file(s) from push_swap"

fclean:	clean
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean

re:	fclean all clean