/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:34:11 by briffard          #+#    #+#             */
/*   Updated: 2022/09/21 15:34:45 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	stick(t_coords coords[], t_filler *info, int zone_ref)
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
		info->soluce = (t_coords)\
			{.row = coords[0].row, .col = coords[0].col, .data = counter};
}

void	try_to_stick(t_filler *info, t_list *block_ref)
{
	t_list		*block_piece;
	t_coords	new_coords[info->size_piece];

	block_piece = info->li_piece;
	while (block_piece != NULL)
	{
		init_coord(new_coords, info->piece.row * info->piece.col);
		coord_generator(new_coords, block_ref, block_piece, info->li_piece);
		if (we_can_place(new_coords, info))
			stick(new_coords, info, block_ref->block.data);
		block_piece = block_piece->next;
	}
}

void	place(t_filler *info, t_coords coords[], int *data, int zoneref)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (*data == 0)
		info->soluce = (t_coords) {.row = coords[0].row, .col = coords[0].col};
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
		info->soluce = (t_coords) {.row = coords[0].row, .col = coords[0].col};
		*data = counter;
	}
}

void	find_place(t_filler *info)
{
	int	position;
	t_coords	new_coords[info->size_piece];
	t_list	*ref_block;

	ref_block = create_node(0, 0 , 0);
	position = 0;
	while (position < info->map.row * info->map.col)
	{
		ref_block->block.row = position / info->map.col;
		ref_block->block.col = position % info->map.col;
		ref_block->block.data = info->hmap[position / info->map.col][position % info->map.col];
		init_coord(new_coords, info->size_piece);
		coord_generator(new_coords, ref_block,info->li_piece, info->li_piece);
		if (we_can_place(new_coords, info))
			place(info, new_coords, &info->soluce.data, ref_block->block.data);
		position++;
	}
	ref_block = clean_list(ref_block);
}

int free_loop_space(t_coords start, t_coords end, t_filler *info)
{
	int ref_col;

	ref_col = start.col;
	while (start.row <= end.row && start.col <= end.col)
	{
		if (info->map2d[start.row][start.col] == '.')
			return (true);
		if(start.col == end.col)
		{
			start.row++;
			start.col = ref_col - 1;
		}
		start.col++;
	}
	return (false);
}

int	free_space(int row, int col, t_filler *info)
{
	t_coords	start;
	t_coords	end;

	start = (t_coords){.row = row - 1, .col = col - 1};
	end = (t_coords) {.row = row + 1, .col = col + 1};
	if (row == 0)
		start.row = 0;
	if (end.row ==  info->map.row)
		end.row = info->map.row - 1;
	if (col == 0)
		start.col = 0;
	if (end.col == info->map.col)
		end.col = info->map.col - 1;
	if (free_loop_space(start, end, info))
		return (true);
	return (false);
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


	// for(int i = 0; i < info->map.row; i++)
	// {
	// 	for (int j = 0; j < info->map.col; j++)
	// 		dprintf(2, "%d ", info->hmap[i][j]);
	// 	dprintf(2,"\n");
	// }
	// dprintf(2, "\n");
	// for(int i = 0; i < info->map.row; i++)
	// {
	// 	for (int j = 0; j < info->map.col; j++)
	// 		dprintf(2, "%d ", info->test[i][j]);
	// 	dprintf(2,"\n");
	// }
	// dprintf(2, "\n");

		// for(int x = 0; x < info->map.row; x++)
	// 	{	
	// 		for (int y = 0; y < info->map.col; y++)
	// 			dprintf(2, "%d ", info->test[x][y]);
	// 		dprintf(2,"\n");
	// 	}
	// 	dprintf(2, "\n");

