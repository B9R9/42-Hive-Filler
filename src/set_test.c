/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:48:30 by briffard          #+#    #+#             */
/*   Updated: 2022/09/19 13:35:11 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	define_start_row(char **map, t_coords max)
{
	int	i;
	int	j;

	i = 0;
	while (i < max.row)
	{
		j = 0;
		while (j < max.col)
		{
			if (map[i][j] != '.')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

static int	define_start_col(char **map, t_coords max)
{
	int	i;
	int	j;

	i = 0;
	while (i < max.col)
	{
		j = 0;
		while (j < max.row)
		{
			if (map[j][i] != '.')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

static t_coords	define_start(t_filler *info)
{
	t_coords start;

	start.row = define_start_row(info->map2d, info->map);
	start.col = define_start_col(info->map2d, info->map);
	start.data = 0;
	return (start);
}

int	**fill_test_map(t_filler *info)
{
	t_coords	start;
	t_coords	end;

	start = define_start(info);
	end = define_end(info);
	// info->test = fill_top(start, end,info->test);
	info->test = fill_down(start, end, info->test);
	return (info->test);
}

int	**set_test(t_filler *info)
{
	if (!info->test)
		info->test = new_2d_iarr(info);
	info->test = fill_test_map(info);
	return (info->test);
}
