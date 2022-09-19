/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:13:30 by briffard          #+#    #+#             */
/*   Updated: 2022/09/19 12:56:52 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			define_end_row(char **map, t_coords max)
{
	int	i;
	int	j;

	i = max.row - 1;
	while (i >= 0)
	{
		j = max.col - 1;
		while (j >= 0)
		{
			if (map[i][j] != '.')
				return (i);
			j--;
		}
		i--;
	}
	return (max.row - 1);
}

int			define_end_col(char **map, t_coords max)
{
	int	i;
	int	j;

	i = max.col - 1;
	while (i >= 0)
	{
		j = max.row - 1;
		while (j >= 0)
		{
			if (map[j][i] != '.')
				return (i);
			j--;
		}
		i--;
	}
	return (max.col - 1);
}


t_coords	define_end(t_filler *info)
{
	t_coords end;

	end.row = define_end_row(info->map2d, info->map);
	end.col = define_end_col(info->map2d, info->map);
	end.data = 0;
	return (end);
}

int			**fill_down(t_coords start, t_coords end, int **map)
{
	while (start.row >= end.row)
	{
		map[start.row][start.col] = 1;
		start.row++;
	}
	while (start.col >= end.col)
	{
		map[start.row][start.col] = 1;
		start.col++;
	}
	return (map);
}

int			**fill_top(t_coords start, t_coords end, int **map)
{
	while (start.col >= end.col)
	{
		map[start.row][start.col] = 1;
		start.col++;
	}
	while (start.row >= end.row)
	{
		map[start.row][start.col] = 1;
		start.row++;
	}
	return (map);
}
