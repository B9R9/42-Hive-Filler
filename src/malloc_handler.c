/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:03:00 by briffard          #+#    #+#             */
/*   Updated: 2022/09/18 22:02:14 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"



static void	init_struct(t_filler *info)
{
	info->player = 0;
	info->you = 'O';
	info->opp = 'X';
	info->map.row = 0;
	info->map.col = 0;
	info->map.data = 0;
	info->soluce.row = 0;
	info->soluce.col = 0;
	info->soluce.data = 0;
	info->piece.row = 0;
	info->piece.col = 0;
	info->piece.data = 0;
	info->piece = NULL;
	info->blocks = NULL;
	info->strmap = NULL;
	info->map = NULL;
	info->hmap = NULL;
	info->test = NULL;
	info->line = NULL;
}


t_info	*new_struct(void)
{
	t_info	*new;

	new = (t_info *)malloc(sizeof(t_info));
	if (!new)
		panic("In malloc_handler: create_info", new);
	ft_bzero(new, sizeof (t_info));
	init_struct(info);
	return (new);
}
