# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briffard <briffard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 11:42:00 by briffard          #+#    #+#              #
#    Updated: 2022/09/23 10:46:14 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = briffard.filler

#COMPILATION
CC		=	gcc
CCFLAGS	=	-Werror -Wextra -Wall
LIB_LFT	=	-L ./libft/ -lft
LIBFT	=	./libft/libft.a

#INCLUDE
INCL	=	-I ./include
INCL_LFT=	-I ./libft/includes

#CLEAN & FCLEAN
RM_DIR	=	rm -rf
RM		=	rm	-f

#SOURCE FILES
SRC_DIR	=	./src/
FILES	=	can_we_place.c \
			clean.c \
			exit.c \
			list_handler.c \
			main.c \
			malloc.c \
			set_game.c \
			set_hmap_2.c \
			set_hmap.c \
			set_piece.c \
			set_test.c \
			set_test_2.c \
			solver.c \
			tools_2.c \
			tools.c \

#OBJECT FILES
OBJ_DIR			=	./objectFiles/
OBJS		=	$(addprefix $(OBJ_DIR), $(FILES:%.c=%.o))

all: $(NAME) 

$(NAME): $(LIBFT) $(OBJS) 
	@$(CC) $(CCFLAGS) -o $(NAME) $(OBJS) $(LIB_LFT)
	@echo "$(NAME) has been created"

$(LIBFT):
	@make -C ./libft

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CCFLAGS) $(INCL_LFT) $(INCL) -o $@ -c $<

clean:
	@$(RM_DIR) $(OBJ_DIR)
	@echo "FILLER: Object Files have been deleted"
	@make -C ./libft clean

fclean: clean
	@$(RM) $(NAME)
	@echo "FILLER: Player file has been deleted"
	@make -C ./libft fclean

re: fclean all

.PHONY: all re clean fclean
