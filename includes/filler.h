/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:26:20 by briffard          #+#    #+#             */
/*   Updated: 2022/09/18 23:33:47 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

/*INCLUDES*/
#include <stdio.h>
#include "libft.h"

/*STRUCT*/

typedef	enum
{
	false,
	true
}			t_bool;

typedef	struct	s_coords
{
	int	row;
	int	col;
	int	data;
}				t_coords;


typedef struct	s_list
{
	t_coords	block;
	struct s_list	*next;
}				t_list;

typedef struct s_filler
{
	int			player;		//definis si le player se trouve en haut ou en bas
	char		you;		// definie quel est le symbol attribue au joueur
	char		opp;		//define quel est le symbol attribue au joueur
	t_coords	map;		//contient la taille de la map
	t_coords	piece;		//contient la taille de la piece
	t_list		*piece;		//list des blocks de la pieces avec leur coord et son type ( * ou .)
	t_list		*blocks;	// list des blocks sur la map coorespondant au symbol du joueurr
	char		*strmap;	//map recuperer dans une str
	char		**map;		//MAp 2d du plateau
	int			**hamp;		//Hmap de map
	int 		**test;		// map qui dssine un rectangle entre la you et opp
	t_coords	soluce;		// coordonnee de la solution a imprime data recupera les point marque par une piece sur le plateau
	char		*line;		// line pour gnl
}


/*prototype*/

/*malloc_handler -> struct_hander*/
t_filler	*new_struct(void);

/*set game*/
void	set_info_game(t_filler *info);

/*exit*/
void	panic(char *mess, t_filler *info);

/*tool*/
void	skip_line(t_filler *info);
char	**adjust_pointer(char **map, char *strmap, t_coords max, int adjust);

/*malloc*/
char	**set_2d_arr(t_filler *info, int adjust);

/*set piece*/
void	set_piece(t_filler *info);

/*list_handler*/
t_list	push_back_piece(t_list *li, int row, int col, t_bool block);

#endif
