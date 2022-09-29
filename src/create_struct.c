/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:43:58 by briffard          #+#    #+#             */
/*   Updated: 2022/09/29 15:16:03 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_game(t_filler *info)
{
	info->you = 'O';
	info->opp = 'X';
	info->row = 0;
	info->col = 0;
	info->size = 0;
	info->dist = 0;
	info->solution = (t_coords){0, 0, 0};
	info->mybloacks = NULL;
	info->oppblocks = NULL;
	info->map2d = NULL;
	info->strmap = NULL;
}

void	init_piece(t_piece *piece)
{
	piece->row = 0;
	piece->col = 0;
	piece->size = 0;
	piece->list = NULL;
}

t_filler	*new_filler(void)
{
	t_filler	*new;

	new = (t_filler *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	init_game(new);
	return (new);
}

t_piece	*new_piece(void)
{
	t_piece	*new;

	new = (t_piece *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	init_piece(new);
	return (new);
}

int	create_struct(t_filler **info, t_piece **piece)
{
	*info = new_filler();
	if (!*info)
		return (1);
	*piece = new_piece();
	if (!*piece)
		return (1);
	return (0);
}
