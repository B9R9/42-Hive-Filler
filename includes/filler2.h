/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:54:54 by briffard          #+#    #+#             */
/*   Updated: 2022/09/18 14:25:53 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

/*includes*/
# include<fcntl.h>
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include <string.h>
# include "libft.h"

typedef enum e_bool{
	FALSE,
	TRUE,
}	t_bool;

typedef struct s_piece {
	unsigned short	line;
	unsigned short	col;
	char			*piece;
} t_piece;

typedef struct s_player {
	char	symbol;
	unsigned short player;
}	t_player;

typedef struct s_coordonnee {
	unsigned int line;
	unsigned int col;
}	t_coord;

typedef struct s_map {
	unsigned int	line;
	unsigned int	col;
	char			*map;
	char			**d_map;
} t_map;

typedef struct s_block_list {
	t_coord		coord;
	struct s_block_list	*next;
}	t_b_list;

typedef struct s_info
{
	t_player	player;
	t_player	opponent;
	t_map		map;
	t_coord		target1;
	t_coord		target2;
	t_piece		piece;
	t_b_list	*list_player;
	t_b_list	*list_opp;
}	t_info;

/*malloc_hander*/
t_info	*create_info(void);
t_piece	*create_piece(void);
char	**create_d_map(t_info *info);
t_info	*create_list(t_info *info);

/*set_struct*/
void	set_info(t_info *info);

/*player_info*/
void	get_player_info(t_info *info);
void	get_map_info(t_info *info);
void	get_map(t_info *info);
void	get_piece(t_info *info);

/*set map*/
void	set_map(t_info *info);

/*remove*/
void	print_fd(char *filename, char *message);

/*exit*/
void	panic(char *message, t_info *info);

/*tools*/
void	skip_line(t_info *info);

/*free handlers*/
void	free_info(t_info **info);
void	free_piece(t_piece **piece);

/*get lines into a string*/
void	get_lines(unsigned short nb_lines, char **dst);

#endif
