/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:14:08 by briffard          #+#    #+#             */
/*   Updated: 2022/08/04 12:06:32 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


/*
 * Doit on verifier que toutes la lignes soientt exactement les memes ou juste
 * focus sur les parties qui nous interresse*/
void	get_player_info(t_info *info)
{
	char	*line;

	line = NULL;
	if (ft_get_next_line(0, &line) < 0)
		panic("In player_info: get_player_info: retour GNL", info);
	if (ft_strncmp("$$$ exec p", line, 10) != 0)
		panic("Error player info: strcmp", info);
	info->player = ft_atoi(&line[10]);
	if (info->player != 1 && info->player != 2)
		panic("Error player info: retour atoi", info);
	info->opposite = (info->player == 1) + 1;
	if (!ft_strnstr(line, "briffard.filler", ft_strlen(line)))
		panic("Error player info: ret_strnstr", info);
	ft_strdel(&line);
}

void	get_map_info(t_info *info)
{
	char	*line;

	line = NULL;
	if (ft_get_next_line(0, &line) < 0)
		panic("In player_info: get_map_info: GNL ret", info);
	if (strncmp("Plateau", line, ft_strlen("Plateau")) != 0)
		panic("In get_map_info: get_map_info: Checking beginning", info);
	info->line = ft_atoi(&line[8]);
	if (info->line < 1)
		panic("In get_map_info: get_map_info: line dimension", info);
	info->col = ft_atoi(&line[8 + ft_numlength(info->line)]);
	if (info->col < 1)
		panic("In get_map_info: get_map_info: col dimension", info);
	ft_strdel(&line);
}

void	get_map(t_info *info)
{
	char	*line;
	size_t	index;
	char	*temp;

	line = NULL;
	index = 0;
	skip_line(info);
	while(index < info->line)
	{
		if (ft_get_next_line(0, &line) < 1)
			panic("In player_info.c: get_map: ret_GNL", info);
		if (!info->map)
		{
			info->map = ft_strdup(line);
			skip_line(info);
		}
		temp = ft_strjoin(info->map, line);
		if (!temp)
			panic("in player_info.c: get_map:", info);
		ft_strdel(&info->map);
		ft_strdel(&line);
		info->map = temp;
		index++;
	}
}