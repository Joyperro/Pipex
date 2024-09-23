# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dclement <dclement@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 12:21:34 by dclement          #+#    #+#              #
#    Updated: 2024/09/23 12:55:52 by dclement         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -Ilibft/

LIBFT_PATH = libft/

LIBFT = $(LIBFT_PATH)libft.a

SRC = pipex.c utils.c

OBJ = $(SRC:.c=.o)

EXEC_NAME = pipex

all : $(LIBFT) $(EXEC_NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(EXEC_NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT)
	@echo "\n$(G)Pipex executable compiled!$(DEF_COLOR)-> pipex\n"

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@rm -f $(OBJ)
fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@rm -f $(NAME) $(EXEC_NAME)
re: fclean all

.PHONY: all clean fclean re