/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:57:16 by briffard          #+#    #+#             */
/*   Updated: 2022/09/29 13:59:03 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	skip_line(void)
{
	char	*line;

	line = NULL;
	if (ft_get_next_line(0, &line) < 1)
		return (1);
	ft_strdel(&line);
	return (0);
}

int	not_in(t_list *li, int i, int j)
{
	t_list	*temp;

	if (li == NULL)
		return (1);
	temp = li;
	while (temp != NULL)
	{
		if (temp->row == i && temp->col == j)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	look_around(t_coords start, t_coords end, t_filler *info)
{
	int	ref_col;

	ref_col = start.col;
	while (start.row <= end.row && start.col <= end.col)
	{
		if (info->map2d[start.row][start.col] == '.')
			return (1);
		if (start.col == end.col)
		{
			start.row++;
			start.col = ref_col - 1;
		}
		start.col++;
	}
	return (0);
}

int	free_spot(int row, int col, t_filler *info)
{
	t_coords	start;
	t_coords	end;
	t_coords	map;

	map = (t_coords){info->row, info->col, 0};
	start = (t_coords){row - 1, col - 1, 0};
	end = (t_coords){row + 1, col + 1, 0};
	if (row == 0)
		start.row = 0;
	if (end.row == map.row)
		end.row = map.row - 1;
	if (col == 0)
		start.col = 0;
	if (end.col == map.col)
		end.col = map.col - 1;
	if (look_around(start, end, info))
		return (1);
	return (0);
}

void	print_solution(t_coords solution)
{
	ft_putnbr(solution.row);
	ft_putchar(' ');
	ft_putnbr(solution.col);
	ft_putchar('\n');
}
