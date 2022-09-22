/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hmap_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:01:45 by briffard          #+#    #+#             */
/*   Updated: 2022/09/22 16:13:48 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	can_we_check(int position, t_filler *info, int adjust, int option)
{
	int			ref;
	t_coords	max;
	int			**map;

	map = info->hmap;
	max = info->map;
	ref = position + adjust;
	if (ref < 0 || ref >= max.col * max.row)
		return (false);
	if (map[ref / max.col][ref % max.col] != 0)
		return (false);
	if (option == 1)
		if (position / max.col != ref / max.col)
			return (false);
	if (option == 2)
		if (position % max.col != ref % max.col)
			return (false);
	return (true);
}

static int	conv(int position, int adjust, int option, t_coords max)
{
	if (option == 0)
		return ((position + adjust) / max.col);
	return ((position + adjust) % max.col);
}

int	**set_around(int spot, t_filler *info)
{
	int			row;
	int			col;
	t_coords	max;
	int			**map;

	max = info->map;
	map = info->hmap;
	row = spot / max.col;
	col = spot % max.col;
	if (can_we_check(spot, info, -1, 1))
		map[conv(spot, -1, 0, max)][conv(spot, -1, 1, max)] = map[row][col] + 1;
	if (can_we_check(spot, info, 1, 1))
		map[conv(spot, 1, 0, max)][conv(spot, 1, 1, max)] = map[row][col] + 1;
	if (can_we_check(spot, info, max.col, 2))
		map[conv(spot, max.col, 0, max)][conv(spot, max.col, 1, max)] \
			= map[row][col] + 1;
	if (can_we_check(spot, info, max.col * -1, 2))
		map[conv(spot, max.col * -1, 0, max)][conv(spot, max.col * -1, 1, max)] \
			= map[row][col] + 1;
	return (map);
}
