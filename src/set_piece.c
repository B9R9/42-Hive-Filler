/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:59:09 by briffard          #+#    #+#             */
/*   Updated: 2022/09/19 16:04:14 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	get_size_piece(t_filler *info)
{
	info->line = NULL;
	if (ft_get_next_line(0, &info->line) < 1)
		panic("Retour GNL: get_size_piece\n", info);
	if (ft_strncmp(info->line, "Piece", 5) != 0)
		panic("No match for Piece line\n", info);
	info->piece.row = ft_atoi(&info->line[6]);
	if (info->piece.row < 1)
		panic ("Piece.row < 1\n", info);
	info->piece.col = ft_atoi(&info->line[7 + ft_numlength(info->piece.row)]);
	if (info->piece.col < 1)
		panic("Piece.col < 1\n", info);
	ft_strdel(&info->line);
}

static t_list	*set_list_piece(t_filler *info)
{
	t_list	*li;
	int		i;
	int		j;

	li = info->li_piece;
	info->line = NULL;
	i = 0;
	while (i < info->piece.row)
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
		ft_strdel(&info->line);
		i++;
	}
	return (li);
}


void	set_piece(t_filler *info)
{
	get_size_piece(info);
	info->li_piece = set_list_piece(info);
	// for(t_list *temp = info->li_piece; temp != NULL; temp = temp->next)
	// 	dprintf(2, "PIECE: %d %d %d\n", temp->block.row, temp->block.col, temp->block.data);
	info->size_piece = info->piece.row * info->piece.col;
}
