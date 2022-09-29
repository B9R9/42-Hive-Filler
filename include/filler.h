/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:26:20 by briffard          #+#    #+#             */
/*   Updated: 2022/09/23 11:14:00 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

/*INCLUDES*/
# include <stdio.h>
# include	"libft.h"

/*STRUCT*/
typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef struct s_coords
{
	int	row;
	int	col;
	int	data;
}				t_coords;

typedef struct s_list
{
	t_coords		block;
	struct s_list	*next;
}				t_list;

typedef struct s_filler
{
	int			player;
	char		you;
	char		opp;
	t_coords	map;
	t_coords	piece;
	int			size_piece;
	t_list		*li_blocks;
	t_list		*li_piece;
	char		*strmap;
	char		**map2d;
	int			**hmap;
	int			**test;
	t_coords	soluce;
	char		*line;
}			t_filler;

/*prototype*/
/*set game*/
void		set_info_game(t_filler *info);
void		set_list_block(t_filler *info);

/*exit*/
void		panic(char *mess, t_filler *info);
t_filler	*clean_before_exit(t_filler *info);

/*tool*/
void		skip_line(t_filler *info);
char		**adjust_pointer(char **map, char *strmap, \
			t_coords max, int adjust);
void		print_soluce(t_coords soluce);
void		init_coord(t_coords *coord, int size);
void		coord_generator(t_coords *new, t_list *my_blocks, \
			t_list *ref, t_list *piece);
int			free_space(int row, int col, t_filler *info);
t_list		*set_zone(t_filler *info);
t_list		*order_by_zone(t_list *li);

/*malloc*/
char		**set_2d_arr(t_filler *info, int adjust);
t_filler	*new_struct(void);
t_coords	*new_coords_arr(t_filler *info);

/*set piece*/
void		set_piece(t_filler *info);

/*list_handler*/
t_list		*push_back_piece(t_list *li, int row, int col, t_bool block);
int			not_in(t_list	*li, int i, int j);
t_list		*create_node(int row, int col, t_bool block);
void		swap(t_list *a, t_list *b);

/*set_hmap*/
int			**set_hmap(t_filler *info);
int			**set_around(int spot, t_filler *info);
int			**new_2d_iarr(t_filler *info);
int			**init_value(int **arr, int max_row, int max_col);

/*set_test*/
int			**set_test(t_filler *info);
t_coords	define_end(t_filler *info);
int			**fill_top(t_coords start, t_coords end, int **map);
int			**fill_down(t_coords start, t_coords end, int **map);

/*clean*/
t_list		*clean_list(t_list *li);
void		freearray(int **arr, size_t row);
void		clean2str(char *s1, char *s2);

/*can we place*/
int			we_can_place(t_coords *coord, t_filler *info);

/*solver*/
void		solver(t_filler *info);
#endif