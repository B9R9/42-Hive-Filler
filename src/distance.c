/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:46:37 by briffard          #+#    #+#             */
/*   Updated: 2022/09/29 15:15:44 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	calculate_distance(t_list *a, t_coords b)
{
	int	diff_col;
	int	diff_row;
	int	result;

	diff_col = ft_abs_int(a->col - b.col);
	diff_row = ft_abs_int(a->row - b.row);
	result = diff_col + diff_row;
	return (result);
}

void	get_distance(int *dist, t_list *opp, t_coords ref)
{
	t_list	*temp;
	int		ret;

	temp = opp;
	while (temp != NULL)
	{
		ret = calculate_distance(temp, ref);
		if (ret < *dist)
			*dist = ret;
		temp = temp->next;
	}
}

int	define_distance(t_filler *info, t_piece *piece, t_coords *ref)
{
	int	ret;
	int	i;

	i = 0;
	ret = info->size;
	while (i < piece->size)
	{
		if (ref[i].data)
			get_distance(&ret, info->oppblocks, ref[i]);
		i++;
	}
	return (ret);
}

void	find_distance(t_filler *info, t_piece *piece, t_coords *ref)
{
	int	distance;

	distance = define_distance(info, piece, ref);
	if (distance < info->dist)
	{
		info->dist = distance;
		info->solution = (t_coords){ref[0].row, ref[0].col, 0};
		info->match = 1;
	}
}
