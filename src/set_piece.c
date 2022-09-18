/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:59:09 by briffard          #+#    #+#             */
/*   Updated: 2022/09/18 23:33:41 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_size(t_filler *info)
{
	info->line = NULL;
	if (ft_get_next_line(0, &info->line) < 1)
		panic("Retour GNL: get_size_piece\n", info);
	if (ft_strcmp(info->line, "Piece", 5) != 0)
		panic("No match for Piece line\n", info);
	info->piece.row = ft_atoi(info->line[6]);
	if (info->piece.row < 1)
		panic ("Piece.row < 1\n", info);
	info->piece.col = ft_atoi(&info->line[7 + ft_numlength(info->row)]);
	if (info->piece.col < 1)
		panic("Piece.col < 1\n", info);
	ft_strdel(&info->line);
}

t_list	*set_list(t_filler *info)
{
	t_list	*li;
	int		i;
	int		j;

	li = info->li_piece;
	info->line = NULL;
	i = 0;
	while (i < max_row)
	{
		if (ft_get_next_line(0, &info->line) < 1)
			panic("Retour GNL: set_list\n", info);
		j = 0;
		while (info->line[j] != '\0')
		{
			// li = push_back(li, i, j,(info->line[j] == '*') + 0);
			if (info->line[j] == '*')
				li = push_back_piece(li, i, j, true);
			else
				li = push_back_piece(li, i, j, false);
			j++;
		}
		i++;
	}
	return (li);
}


void	set_piece(t_filler *info)
{
	get_size_piece(info);
	info->li_piece = set_list(info);
}
