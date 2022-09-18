/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:34:11 by briffard          #+#    #+#             */
/*   Updated: 2022/09/19 00:20:40 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	stick(t_coords coords[], t_filler *info, int zone_ref)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;

	while (i < info-<piece.row * info->piece.col)
	{
		if (hmap[coords[i].row][coords[i].col] < zone_ref)
			counter += 3;
		else if (hmap[coords[i].row][coords[i].col] == zone_ref)
			counter += 2;
		else if (hmap[coords[i].row][coords[i].col] > zone_ref)
			counter += 1;
		i++;
	}
	if (counter > info->soluce.data)
		info->soluce = (t_coords)\
			{.row = coords[0], .col = coords[0], .data = counter};
}

void	try_to_stick(t_filler *info, t_list *block_ref)
{
	t_list		*block_piece;
	t_coords	new_coords[info->piece.row * info->piece.col];

	block_piece = info->li_piece;
	while (block_piece != NULL)
	{
		init_coord(new_coord, info->piece.row * info->piece.col);
		coord_generator(new_coord, block_ref, block_piece, info->li_piece);
		if (we_can_place(new_coord, info))
			stick(new_coord, info, block_ref->data);
		block_piece =block_piece->next;
	}
}

void	place(t_filler *info)
{
	int	i;

	i = 0;
	while (i < info->piece.row * info->piece.col)
	{
		if(test[coords[i].row][coords[i].col] == 1)
			counter += 3;
		i++;
	}
	if (counter > info->soluce.data)
		info->soluce = (t_coords)\
			{.row = coords[0], .col = coords[0], .data = counter};

}

void	find_place(t_filler *info)
{
	int	position;
	t_list	*ref_block;

	ref_block = new_node(0, 0 , 0);
	position = 0;
	while (position < info->map.row * info->map.col)
	{
		ref_block->row = position / info->map.col;
		ref_block->col = position % info->map.col;
		init_coord(new_coord, info->piece.row * info->piece.col);
		coord_generator(new_coord, ref_block,info->li_piece, info->li_piece);
		if (we_can_place(new_coords, info))
			place(info);
		position++;
	}
}

void	solver(t_filler *info)
{
	t_list	*temp;

	temp = info->block
	while (temp->data < 4)
	{
		try_to_stick(info, temp);
		temp = temp->next;
	}
	if (info->point == 0)
		find_place(info);
	print_soluce(info->soluce);
}
