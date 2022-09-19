/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:26:39 by briffard          #+#    #+#             */
/*   Updated: 2022/09/19 12:47:51 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init_struct(t_filler *info)
{
	info->player = 0;
	info->you = 'O';
	info->opp = 'X';
	info->map.row = 0;
	info->map.col = 0;
	info->map.data = 0;
	info->soluce.row = 0;
	info->soluce.col = 0;
	info->soluce.data = 0;
	info->piece.row = 0;
	info->piece.col = 0;
	info->piece.data = 0;
	info->li_piece = NULL;
	info->li_blocks = NULL;
	info->strmap = NULL;
	info->map2d = NULL;
	info->hmap = NULL;
	info->test = NULL;
	info->line = NULL;
}

t_filler	*new_struct(void)
{
	t_filler	*new;

	new = (t_filler *)malloc(sizeof(*new));
	if (!new)
		panic("In malloc_handler: create_info", new);
	ft_bzero(new, sizeof (t_filler));
	init_struct(new);
	return (new);
}


void	save_map(int max_row, t_filler *info)
{
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	info->line = NULL;
	while (i < max_row)
	{
		if (ft_get_next_line(0, &info->line) < 1)
			panic ("Retour GNL: save map\n", info);
		if (!info->strmap)
			temp = ft_strdup(info->line);
		else
			temp = ft_strjoin(info->strmap, info->line);
		clean2str(info->line, info->strmap);
		if (!temp)
			panic ("In malloc.c: save map\n", info);
		info->strmap = temp;
		i++;
	}
	info->strmap = ft_strtoupper(info->strmap); //changer pour void fonction
}

char	**set_2d_arr(t_filler *info, int adjust)
{
	int			i;
	t_coords	max;
	char		**new;

	i = -1;
	max = (t_coords){ .row = info->map.row, .col = info->map.col};
	new = (char **)malloc(sizeof(char *) * max.row);
	if (!new)
		panic("In malloc.c: set_2d_arr\n", info);
	while (++i < max.row)
		new[i] = NULL;
	save_map(max.row, info);
	new = adjust_pointer(new, info->strmap, info->map, adjust);
	return (new);
}
