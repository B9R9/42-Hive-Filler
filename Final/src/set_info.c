/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:51:57 by briffard          #+#    #+#             */
/*   Updated: 2022/09/29 13:53:28 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	set_player_info(t_filler *info)
{
	char	*line;

	line = NULL;
	if (ft_get_next_line(0, &line) < 1)
		return (1);
	if (ft_strncmp(line, "$$$ exec p", 10) != 0)
		return (1);
	if (line[10] == '2' || line [10] == '1')
	{
		if (line[10] == '2')
		{
			info->you = 'X';
			info->opp = 'O';
		}
	}
	else
		return (1);
	ft_strdel(&line);
	return (0);
}

int	set_plateau_info(t_filler *info)
{
	char	*line;

	line = NULL;
	if (ft_get_next_line(0, &line) < 1)
		return (1);
	if (ft_strncmp(line, "Plateau", 7) != 0)
		return (1);
	info->row = ft_atoi(&line[7]);
	if (info->row < 1)
		return (1);
	info->col = ft_atoi(&line[8 + ft_numlength \
			(info->row)]);
	if (info->col < 1)
		return (1);
	ft_strdel(&line);
	if (skip_line())
		return (1);
	return (0);
}

int	set_piece_info(t_piece *piece)
{
	char	*line;

	line = NULL;
	if (ft_get_next_line(0, &line) < 1)
		return (1);
	if (ft_strncmp(line, "Piece", 5) != 0)
		return (1);
	piece->row = ft_atoi(&line[6]);
	if (piece->row < 1)
		return (1);
	piece->col = ft_atoi(&line[6 + ft_numlength(piece->row)]);
	if (piece->col < 1)
		return (1);
	ft_strdel(&line);
	return (0);
}
