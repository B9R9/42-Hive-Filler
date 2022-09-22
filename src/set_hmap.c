/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:33:28 by briffard          #+#    #+#             */
/*   Updated: 2022/09/22 16:17:54 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	**init_value(int **arr, int max_row, int max_col)
{
	int	i;
	int	j;

	i = 0;
	while (i < max_row)
	{
		j = 0;
		while (j < max_col)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (arr);
}

int	**new_2d_iarr(t_filler *info)
{
	int			**new;
	int			i;
	t_coords	max;

	max = info->map;
	i = 0;
	new = (int **)malloc(sizeof(int *) * max.row);
	if (!new)
		panic("In set_hmap.c: new_2d_iarr/n", info);
	while (i < max.row)
	{
		new[i] = (int *)malloc(sizeof(int) * max.col);
		if (!new[i])
		{
			freearray(new, i);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	new = init_value(new, max.row, max.col);
	return (new);
}

int	**set_1aera(int **map, t_coords max, char **ref, char symbol)
{
	int	i;
	int	j;

	i = 0;
	while (i < max.row)
	{
		j = 0;
		while (j < max.col)
		{
			if (ref[i][j] == symbol)
				map[i][j] = 1;
			j++;
		}
		i++;
	}
	return (map);
}

int	**fill_hmap(t_filler *info, int position, int zone)
{
	int	row;
	int	col;
	int	stop;

	stop = 1;
	while (position < info->map.col * info->map.row)
	{
		row = position / info->map.col;
		col = position % info->map.col;
		if (info->hmap[row][col] == 0)
			stop = 0;
		if (info->hmap[row][col] == zone)
			info->hmap = set_around(position, info);
		position++;
		if (position == info->map.col * info->map.row)
		{
			if (stop)
				break ;
			stop = 1;
			position = 0;
			zone++;
		}
	}
	return (info->hmap);
}

int	**set_hmap(t_filler *info)
{
	if (!info->hmap)
		info->hmap = new_2d_iarr(info);
	info->hmap = set_1aera(info->hmap, info->map, info->map2d, info->opp);
	info->hmap = fill_hmap(info, 0, 1);
	return (info->hmap);
}
