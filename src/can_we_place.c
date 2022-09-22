/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_we_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:03:15 by briffard          #+#    #+#             */
/*   Updated: 2022/09/22 14:10:02 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	out_of_map(t_coords *coord, t_coords max, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (coord[i].col >= max.col)
			return (true);
		if (coord[i].col < 0)
			return (true);
		if (coord[i].row >= max.row)
			return (true);
		if (coord[i].row < 0)
			return (true);
		i++;
	}
	return (false);
}

int	overlapping_you(t_coords *coord, char **map, t_filler *info, int size)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < size)
	{
		if (map[coord[i].row][coord[i].col] == info->you && coord[i].data)
			counter += 1;
		i++;
	}
	if (counter == 1)
		return (false);
	return (true);
}

int	overlapping_opp(t_coords *coord, char **map, t_filler *info, int size)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < size)
	{
		if (map[coord[i].row][coord[i].col] == info->opp && coord[i].data)
			return (true);
		i++;
	}
	return (false);
}

int	we_can_place(t_coords *coord, t_filler *info)
{
	if (out_of_map(coord, info->map, info->size_piece))
		return (false);
	if (overlapping_you(coord, info->map2d, info, info->size_piece))
		return (false);
	if (overlapping_opp(coord, info->map2d, info, info->size_piece))
		return (false);
	return (true);
}
