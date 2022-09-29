# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briffard <briffard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 11:42:00 by briffard          #+#    #+#              #
#    Updated: 2022/09/29 16:07:53 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = briffard.filler

#COMPILATION
CC		=	gcc
CCFLAGS	=	-Werror -Wextra -Wall
LIB_LFT	=	-L ./libft/ -lft

#INCLUDE
INCL	=	-I ./include
INCL_LFT=	-I ./libft/includes
LIBFT	=	./libft/libft.a

#CLEAN & FCLEAN
RM_DIR	=	rm -rf
RM		=	rm	-f

#SOURCE FILES
SRC_DIR	=	./src/
FILES	= create_map.c	\
		can_we_place.c	\
		create_piece.c	\
		create_struct.c	\
		distance.c		\
		exit.c			\
		free.c			\
		main.c			\
		set_info.c		\
		solver.c		\
		tools.c			\
		update.c		\

#OBJECT FILES
OBJ_DIR			=	./objectFiles/
OBJS		=	$(addprefix $(OBJ_DIR), $(FILES:%.c=%.o))

all: $(NAME)
	@echo "Player Created"

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CCFLAGS) -o $(NAME) $(OBJS) $(LIB_LFT)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CCFLAGS) $(INCL_LFT) $(INCL) -o $@ -c $<

$(LIBFT):
	@make -C ./libft/ 

clean:
	@$(RM_DIR) $(OBJ_DIR)
	@echo "Object Files have been deleted"
	@make -C ./libft/ clean

fclean: clean
	@$(RM) $(NAME)
	@echo "Player file has been deleted"
	@make -C ./libft/ fclean

re: fclean all

.PHONY: all re clean fclean
