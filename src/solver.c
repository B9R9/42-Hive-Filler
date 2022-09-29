/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:53:44 by briffard          #+#    #+#             */
/*   Updated: 2022/09/29 15:16:03 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_coord(t_coords *coord, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		coord[i] = (t_coords){.row = 0, .col = 0, .data = 0};
}

void	coord_gen(t_coords *new, t_list *blocks, t_list *ref, t_list *piece)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = piece;
	while (temp != NULL)
	{
		new[i].row = (temp->row - ref->row) + blocks->row;
		new[i].col = (temp->col - ref->col) + blocks->col;
		new[i].data = temp->data;
		temp = temp->next;
		i++;
	}
}

t_coords	*new_coords_arr(int size)
{
	t_coords	*new;

	new = (t_coords *)malloc(sizeof(*new) * size);
	if (!new)
		return (NULL);
	return (new);
}

void	place_it(t_filler *info, t_piece *piece, t_list *ref)
{
	t_coords	*new_coords;
	t_list		*temp;
	int			place;

	place = 0;
	temp = piece->list;
	new_coords = new_coords_arr(piece->size);
	while (temp != NULL)
	{
		if (temp->data)
		{
			init_coord(new_coords, piece->size);
			coord_gen(new_coords, ref, temp, piece->list);
			if (we_can_place(new_coords, info, piece))
				find_distance(info, piece, new_coords);
		}
		temp = temp->next;
	}
	free(new_coords);
	new_coords = NULL;
}

int	find_place(t_filler *info, t_piece *piece)
{
	t_list	*temp;
	int		ret;

	ret = 0;
	temp = info->mybloacks;
	info->dist = info->size;
	info->match = 0;
	while (temp != NULL)
	{
		if (free_spot(temp->row, temp->col, info))
			place_it(info, piece, temp);
		temp = temp->next;
	}
	return (info->match);
}
