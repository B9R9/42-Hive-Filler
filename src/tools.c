/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:18:09 by briffard          #+#    #+#             */
/*   Updated: 2022/09/18 22:56:52 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	skip_line(t_filler *info)
{
	info->line = NULL;
	if (ft_get_next_line(0, &info->line) < 1)
		panic("Retour Skip_line\n", info);
	ft_strdel(&info->line);
}

char	**adjust_pointer(char **map, char strmap, t_coords max, int adjust)
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
