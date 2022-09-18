/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 21:34:54 by briffard          #+#    #+#             */
/*   Updated: 2022/09/18 22:56:52 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


void	get_symbol(t_filler *info)
{
	if (ft_get_next_line(0, &info->line) < 1)
		panic("Retour GNL\n", info);
	if (ft_strncmp(info->line, "$$$ exec p", 10) != 0)
		panic ("No match for player line\n", info);
	if (info->line[10] == '2')
	{
		info->you = 'X';
		info->opp = 'O';
	}
	ft_strdel(&info->line);
}

void	get_plateau_size(t_filler *info)
{
	info->line = NULL;
	if (ft_get_next_line(0, &info->line) < 1)
		panic ("Retour GNL\n", info);
	if (ft_strcmp(info->line, "Plateau", 7) != 0)
		panic ("No match for plateau line\n", info);
	info->map.row = ft_atoi(&info->line[7]);
	if (info->map.row < 1)
		panic ("Row < 1\n", info);
	info->map.col = ft_atoi(&info->line[8 + ft_numlength\
			(info->map.row)]);
	if (info->map.col < 1)
		panic("col < 1\n", info);
	ft_strdel(&info->line);
	skip_line(info);
}

int		set_player(char **map, t_coords max, char symbol)
{
	int	i;
	int	j;

	i = 0;
	while (i < max.row)
	{
		j = 0;
		while (j < max.col)
		{
			if (map[i][j] == symbol)
				return (1);
			else
				return (2);
			j++;
		}
		i++;
	}
}

void	set_info_game(t_filler *info)
{
	get_symbol(info);
	get_plateau_size(info);
	info->map = set_2d_arr(info, 4);
	info_player = set_player(info->map2d, info->map, info->you);
}
