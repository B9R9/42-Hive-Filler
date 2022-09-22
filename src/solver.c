/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:34:11 by briffard          #+#    #+#             */
/*   Updated: 2022/09/22 14:38:17 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	stick(t_coords *coords, t_filler *info, int zone_ref)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < info->size_piece)
	{
		if (info->hmap[coords[i].row][coords[i].col] < zone_ref)
			counter += 50;
		else if (info->hmap[coords[i].row][coords[i].col] == zone_ref)
			counter += 100;
		else if (info->hmap[coords[i].row][coords[i].col] > zone_ref)
			counter += 1;
		i++;
	}
	if (counter >= info->soluce.data)
		info->soluce = (t_coords) \
			{.row = coords[0].row, .col = coords[0].col, .data = counter};
}

void	try_to_stick(t_filler *info, t_list *block_ref)
{
	t_list		*block_piece;
	t_coords	*new_coords;

	new_coords = new_coords_arr(info);
	block_piece = info->li_piece;
	while (block_piece != NULL)
	{
		init_coord(new_coords, info->piece.row * info->piece.col);
		coord_generator(new_coords, block_ref, block_piece, info->li_piece);
		if (we_can_place(new_coords, info))
			stick(new_coords, info, block_ref->block.data);
		block_piece = block_piece->next;
	}
	free(new_coords);
	new_coords = NULL;
}

void	place(t_filler *info, t_coords *coords, int *data, int zoneref)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (*data == 0)
		info->soluce = (t_coords){.row = coords[0].row, .col = coords[0].col};
	while (i < info->size_piece)
	{
		if (info->test[coords[i].row][coords[i].col] == 1)
			counter += 3;
		if (info->hmap[coords[i].row][coords[i].col] <= zoneref)
			counter += 10;
		if (info->hmap[coords[i].row][coords[i].col] == zoneref)
			counter += 1;
		i++;
	}
	if (counter > *data)
	{
		info->soluce = (t_coords){.row = coords[0].row, .col = coords[0].col};
		*data = counter;
	}
}

void	find_place(t_filler *info)
{
	int			position;
	t_coords	*new_coords;
	t_list		*ref_block;

	new_coords = new_coords_arr(info);
	ref_block = create_node(0, 0, 0);
	position = 0;
	while (position < info->map.row * info->map.col)
	{
		ref_block->block.row = position / info->map.col;
		ref_block->block.col = position % info->map.col;
		ref_block->block.data = info->hmap \
			[position / info->map.col][position % info->map.col];
		init_coord(new_coords, info->size_piece);
		coord_generator(new_coords, ref_block, info->li_piece, info->li_piece);
		if (we_can_place(new_coords, info))
			place(info, new_coords, &info->soluce.data, ref_block->block.data);
		position++;
	}
	ref_block = clean_list(ref_block);
	free(new_coords);
	new_coords = NULL;
}

void	solver(t_filler *info)
{
	t_list	*temp;

	temp = info->li_blocks;
	while (temp->block.data < 3)
	{
		if (free_space(temp->block.row, temp->block.col, info))
			try_to_stick(info, temp);
		temp = temp->next;
	}
	if (info->soluce.data == 0)
		find_place(info);
	print_soluce(info->soluce);
}
