/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:18:09 by briffard          #+#    #+#             */
/*   Updated: 2022/09/19 16:25:03 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	skip_line(t_filler *info)
{
	info->line = NULL;
	if (ft_get_next_line(0, &info->line) < 1)
		panic("Retour Skip_line\n", info);
	ft_strdel(&info->line);
}

char	**adjust_pointer(char **map, char *strmap, t_coords max, int adjust)
{
	int	i;
	int	j;

	i = 0;
	j = adjust;
	while (i < max.row)
	{
		map[i] = &strmap[j];
		j += adjust + max.col;
		i++;
	}
	return (map);
}

void	print_soluce(t_coords soluce)
{
	ft_putnbr(soluce.row);
	ft_putchar(' ');
	ft_putnbr(soluce.col);
	ft_putchar('\n');
}

void    init_coord(t_coords coord[], int size)
{
    int i;

    i = -1;
    while (++i < size)
        coord[i] = (t_coords) {.row = 0, .col = 0};
}

void	coord_generator(t_coords new[], t_list *my_blocks, t_list *ref, t_list *piece)
{
	int	i;
	t_list	*temp;

	i = 0;
	temp = piece;
	while (temp != NULL)
	{
		new[i].row = (temp->block.row - ref->block.row) + my_blocks->block.row;
		new[i].col = (temp->block.col - ref->block.col) + my_blocks->block.col;
		new[i].data = temp->block.data;
		temp = temp->next;
		i++;
	}
}


