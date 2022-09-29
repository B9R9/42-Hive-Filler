/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:07:46 by briffard          #+#    #+#             */
/*   Updated: 2022/09/29 15:16:03 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdio.h>

typedef struct s_coords
{
	int	row;
	int	col;
	int	data;
}			t_coords;

typedef struct s_list
{
	int				row;
	int				col;
	int				data;
	struct s_list	*next;
}			t_list;

typedef struct s_piece
{
	int			row;
	int			col;
	int			size;
	t_list		*list;
}				t_piece;

typedef struct s_filler
{
	char		you;
	char		opp;
	int			row;
	int			col;
	int			size;
	int			dist;
	int			match;
	char		*strmap;
	char		**map2d;
	t_list		*mybloacks;
	t_list		*oppblocks;
	t_coords	solution;
}				t_filler;

/*Prototype*/
/*can_we_place*/
int			we_can_place(t_coords *coord, t_filler *info, t_piece *piece);
/*create_map*/
int			new_map(t_filler **info);
t_list		*set_list_block(t_filler *info, char symbol, t_list *li);
t_list		*push_back_piece(t_list *li, int row, int col, int block);
/*create_piece*/
int			new_token(t_piece **piece);
t_list		*create_node(int row, int col, int block);
/*create_struct*/
int			create_struct(t_filler **info, t_piece **piece);
/*distance*/
void		find_distance(t_filler *info, t_piece *piece, t_coords *ref);
/*free*/
t_list		*clean_list(t_list *li);
void		clean2str(char *s1, char *s2);
int			clean_all(t_filler *info, t_piece *piece);
/*set_info*/
int			set_plateau_info(t_filler *info);
int			set_player_info(t_filler *info);
int			set_piece_info(t_piece *piece);
/*solver*/
int			find_place(t_filler *info, t_piece *piece);
t_coords	*new_coords_arr(int size);
void		coord_gen(t_coords *new, \
		t_list *my_blocks, t_list *ref, t_list *piece);
void		init_coord(t_coords *coord, int size);

/*tools*/
void		print_solution(t_coords solution);
int			free_spot(int row, int col, t_filler *info);
int			not_in(t_list	*li, int i, int j);
int			skip_line(void);
/*update*/
int			update_info(t_filler *info, t_piece *piece);
/*exit*/
t_piece		*clean_piece(t_piece *piece);
t_filler	*clean_filler(t_filler *info);

#endif
