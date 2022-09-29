/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:48:24 by briffard          #+#    #+#             */
/*   Updated: 2022/09/29 13:49:00 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler	*clean_filler(t_filler *info)
{
	if (info->myBlocks)
		info->myBlocks = clean_list(info->myBlocks);
	if (info->oppBlocks)
		info->oppBlocks = clean_list(info->oppBlocks);
	ft_strdel(&info->strmap);
	free(info->map2d);
	info->map2d = NULL;
	free(info);
	info = NULL;
	return (NULL);
}

t_piece	*clean_piece(t_piece *piece)
{
	if (piece->list)
		piece->list = clean_list(piece->list);
	free(piece);
	piece = NULL;
	return (NULL);
}
