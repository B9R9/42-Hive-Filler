/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:45:36 by briffard          #+#    #+#             */
/*   Updated: 2022/09/22 14:45:37 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler	*clean_before_exit(t_filler *info)
{
	if (info->line)
		ft_strdel(&info->line);
	if (info->hmap)
		freearray(info->hmap, info->map.row);
	if (info->test)
		freearray(info->test, info->map.row);
	if (info->li_blocks)
		info->li_blocks = clean_list(info->li_blocks);
	if (info->li_piece)
		info->li_piece = clean_list(info->li_piece);
	if (info->map2d)
		free(info->map2d);
	if (info->strmap)
		ft_strdel(&info->strmap);
	free(info);
	return (NULL);
}

void	panic(char *mess, t_filler *info)
{
	perror(mess);
	info = clean_before_exit(info);
	system ("leaks briffard.filler  >> leaks.report");
	exit (EXIT_FAILURE);
}
