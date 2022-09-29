/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:59:09 by briffard          #+#    #+#             */
/*   Updated: 2022/09/29 15:16:03 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**update_map(t_filler *info, t_piece *piece)
{
	t_coords	*coords;
	t_list		*ref_block;
	int			i;

	i = 0;
	coords = new_coords_arr(piece->size);
	if (!coords)
		return (NULL);
	ref_block = create_node(info->solution.row, info->solution.col, 0);
	if (!ref_block)
		return (NULL);
	init_coord(coords, piece->size);
	coord_gen(coords, ref_block, piece->list, piece->list);
	while (i < piece->size)
	{
		if (coords[i].data)
			info->map2d[coords[i].row][coords[i].col] = info->you;
		i++;
	}
	ref_block = clean_list(ref_block);
	free(coords);
	coords = NULL;
	return (info->map2d);
}

char	**update_map_opp(t_filler *info)
{
	char	*line;
	int		i;
	int		j;

	if (skip_line())
		return (NULL);
	if (skip_line())
		return (NULL);
	line = NULL;
	i = 0;
	while (i < info->row)
	{
		if (ft_get_next_line(0, &line) <= 0)
			return (NULL);
		j = 0;
		while (line[j] != '\0')
		{
			if (line[j] != '.')
				info->map2d[i][j - 4] = ft_toupper(line[j]);
			j++;
		}
		i++;
		ft_strdel(&line);
	}
	return (info->map2d);
}

int	update_info(t_filler *info, t_piece *piece)
{
	info->map2d = update_map(info, piece);
	if (!info->map2d)
		return (1);
	info->map2d = update_map_opp(info);
	if (!info->map2d)
		return (1);
	info->mybloacks = set_list_block(info, info->you, info->mybloacks);
	if (!info->mybloacks)
		return (1);
	info->oppblocks = set_list_block(info, info->opp, info->oppblocks);
	if (!info->oppblocks)
		return (1);
	return (0);
}
