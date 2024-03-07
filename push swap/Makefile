# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 16:43:46 by ahaarij           #+#    #+#              #
#    Updated: 2024/03/06 16:49:10 by ahaarij          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -g3 -fsanitize=address
LIBFT_DIR = libft
LIBFT = ./libft/libft.a
RM = rm -rf
SRCS = main.c \
		utils.c \
		sort.c \
SRC = $(addprefix ./srcs/,$(SRCS))
OBJ = $(SRC:.c=.o)


all: $(LIBFT) $(NAME) 
	@echo "Done!"
	@echo "To test the program, run 'make test' or 'make test size=10'"
	@echo "for example for testing 10 random numbers"
	@echo "./push_swap 1 2 3 4 5 6 7 8 9 10"

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFT_DIR) -lft

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $? -I./$(LIBFT_DIR)
	@mv *.o src

clean:	
	@$(RM) src/*.o
	@make -s -C $(LIBFT_DIR) clean

fclean:	clean
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean

re:	fclean all clean