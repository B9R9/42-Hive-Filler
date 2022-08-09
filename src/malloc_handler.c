/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:03:00 by briffard          #+#    #+#             */
/*   Updated: 2022/08/09 13:50:24 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_info	*create_info(void)
{
	t_info	*new;

	new = (t_info *)malloc(sizeof(t_info));
	if (!new)
		panic("In malloc_handler: create_info", new);
	ft_bzero(new, sizeof (t_info));
	return (new);
}
/*
t_piece	create_piece(void)
{
	t_piece	*new;

	new = (t_piece *)malloc(sizeof(t_piece));
	if (!new)
		panic("In malloc_handler: create_piece", NULL);
	ft_bzero(new, sizeof (t_piece));
	new->line = 0;
	new->col = 0;
	return (new);
}
*/
char	**create_d_map(t_info *info)
{
	char	**new;
	size_t	i;
	size_t	max_line;
	size_t	j;

	i = 0;
	max_line = info->map.line;
	j = 4;
	new = (char **)malloc(sizeof(char *) * max_line);
	if (!new)
		panic("In malloc_handler: create_d_map:", info);
	while (i < max_line)
	{
		new[i] = &info->map.map[j];
		j += 4 + info->map.col;
		i++;
	}
	return (new);
}



t_b_list	*create_element_list(size_t i, size_t j)
{
	t_b_list	*new;

	new = (t_b_list *)malloc(sizeof(*new));
	if (!new)
		panic("In malloc_handler: create_element", NULL);
	new->coord = (t_coord) { .line = i, .col = j};
	new->next = NULL;
	return (new);
}

t_b_list	push_front(t_b_list *element, t_b_list *li)
{
	if (li == NULL)
		return (element);
	element->next = li;
	return (element);
}

t_b_list	*create_list(t_info *info)
{
	size_t i;

	i = 0;
	while (i < info->map.line)
	{
		j = 0;
		while (j < info->map.col)
		{
			if (ft_toupper(info->map.d_map[i][j]) == info->player.symbol)
			{
				element = create_element_list(i, j);
				info->list = push_front(element, info->list);
			}
			j++;
		}
		i++;
	}
	return (info->list);
}
