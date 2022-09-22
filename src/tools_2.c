/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:43:35 by briffard          #+#    #+#             */
/*   Updated: 2022/09/22 14:46:44 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	free_loop_space(t_coords start, t_coords end, t_filler *info)
{
	int	ref_col;

	ref_col = start.col;
	while (start.row <= end.row && start.col <= end.col)
	{
		if (info->map2d[start.row][start.col] == '.')
			return (true);
		if (start.col == end.col)
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
	end = (t_coords){.row = row + 1, .col = col + 1};
	if (row == 0)
		start.row = 0;
	if (end.row == info->map.row)
		end.row = info->map.row - 1;
	if (col == 0)
		start.col = 0;
	if (end.col == info->map.col)
		end.col = info->map.col - 1;
	if (free_loop_space(start, end, info))
		return (true);
	return (false);
}

t_list	*order_by_zone(t_list *li)
{
	t_list	*temp;

	temp = li;
	while (temp->next != NULL)
	{
		if (temp->block.data > temp->next->block.data)
		{
			swap(temp, temp->next);
			temp = li;
		}
		else
			temp = temp->next;
	}
	return (li);
}

t_list	*set_zone(t_filler *info)
{
	t_list	*temp;

	temp = info->li_blocks;
	while (temp != NULL)
	{
		temp->block.data = info->hmap[temp->block.row][temp->block.col];
		temp = temp->next;
	}
	return (info->li_blocks);
}
