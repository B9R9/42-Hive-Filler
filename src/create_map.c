/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:25:49 by briffard          #+#    #+#             */
/*   Updated: 2022/09/29 15:17:03 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	save_map(char **map, int row)
{
	char	*temp;
	char	*line;
	int		i;

	i = 0;
	temp = NULL;
	line = NULL;
	while (i < row)
	{
		if (ft_get_next_line(0, &line) < 1)
			return (1);
		if (!*map)
			temp = ft_strdup(line);
		else
			temp = ft_strjoin(*map, line);
		clean2str(line, *map);
		if (!temp)
			return (1);
		*map = temp;
		i++;
	}
	*map = ft_strtoupper(*map);
	return (0);
}

char	**adjust_pointer(char **map, char *strmap, t_coords max, int adjust)
{
	int	i;
	int	j;

	i = 0;
	j = adjust;
	while (i < max.row)
	{
		map[i] = &strmap[j];
		j += adjust + max.col;
		i++;
	}
	return (map);
}

char	**set_map2d(t_filler *info, int adjust)
{
	int			i;
	t_coords	max;
	char		**new;

	i = -1;
	max = (t_coords){info->row, info->col, 0};
	new = (char **)malloc(sizeof(char *) * max.row);
	if (!new)
		return (NULL);
	while (++i < max.row)
		new[i] = NULL;
	new = adjust_pointer(new, info->strmap, max, adjust);
	return (new);
}

t_list	*set_list_block(t_filler *info, char symbol, t_list *li)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->row)
	{
		j = 0;
		while (j < info->col)
		{
			if (info->map2d[i][j] == symbol && not_in(li, i, j))
			{
				li = push_back_piece(li, i, j, 0);
				if (!li)
					return (NULL);
			}
			j++;
		}
		i++;
	}
	return (li);
}

int	new_map(t_filler **info)
{
	if (set_plateau_info(*info))
		return (1);
	if (save_map(&(*info)->strmap, (*info)->row))
		return (1);
	(*info)->map2d = set_map2d(*info, 4);
	if (!(*info)->map2d)
		return (1);
	(*info)->mybloacks = set_list_block(*info, \
			(*info)->you, (*info)->mybloacks);
	if (!(*info)->mybloacks)
		return (1);
	(*info)->oppblocks = set_list_block(*info, \
			(*info)->opp, (*info)->oppblocks);
	if (!(*info)->oppblocks)
		return (1);
	(*info)->size = (*info)->row * (*info)->col;
	return (0);
}
