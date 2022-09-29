/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:32:48 by briffard          #+#    #+#             */
/*   Updated: 2022/09/29 13:43:44 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_list	*create_node(int row, int col, int block)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->row = row;
	node->col = col;
	node->data = block;
	node->next = NULL;
	return (node);
}

t_list	*push_back_piece(t_list *li, int row, int col, int block)
{
	t_list	*node;
	t_list	*temp;

	node = create_node(row, col, block);
	if (!node)
		return (NULL);
	if (li == NULL)
		return (node);
	temp = li;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;
	return (li);
}

static t_list	*save_piece(t_list *li, int i, int j, char c)
{
	if (c == '*')
		li = push_back_piece(li, i, j, 1);
	else
		li = push_back_piece(li, i, j, 0);
	return (li);
}

static t_list	*set_list_piece(t_piece *piece)
{
	char	*line;
	t_list	*li;
	int		i;
	int		j;

	li = NULL;
	line = NULL;
	i = -1;
	while (++i < piece->row)
	{
		if (ft_get_next_line(0, &line) < 1)
			return (NULL);
		j = 0;
		while (line[j] != '\0')
		{
			li = save_piece(li, i, j, line[j]);
			if (!li)
				return (NULL);
			j++;
		}
		ft_strdel(&line);
	}
	return (li);
}

int	new_token(t_piece **piece)
{
	if ((*piece)->list)
		(*piece)->list = clean_list((*piece)->list);
	if (set_piece_info(*piece))
		return (1);
	(*piece)->list = set_list_piece(*piece);
	if (!(*piece)->list)
		return (1);
	(*piece)->size = (*piece)->row * (*piece)->col;
	return (0);
}
