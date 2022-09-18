/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:26:20 by briffard          #+#    #+#             */
/*   Updated: 2022/09/18 14:58:39 by briffard         ###   ########.fr       */
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
}


/*prototype*/

/*malloc_handler -> struct_hander*/
t_filler	*new_struct(void);


