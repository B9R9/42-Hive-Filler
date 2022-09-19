/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:20:15 by briffard          #+#    #+#             */
/*   Updated: 2022/09/19 12:46:07 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_list	*create_node(int row, int col, t_bool block)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(*node));
	if (!node)
		exit(EXIT_FAILURE);
	node->block.row = row;
	node->block.col = col;
	node->block.data = block;
	node->next = NULL;
return (node);
}

t_list	*push_back_piece(t_list *li, int row, int col, t_bool block)
{
	t_list	*node;
	t_list	*temp;

	node = create_node(row, col, block);
	if (li == NULL)
		return (node);
	temp = li;
	while (temp->next != NULL)
		temp =  temp->next;
	temp->next = node;
	return (li);
}

void	swap(t_list *a, t_list *b)
{
	int swap;

	swap = a->block.col;
	a->block.col = b->block.col;
	b->block.col = swap;
	swap = a->block.row;
	a->block.row = b->block.row;
	b->block.row = swap;
	swap = a->block.data;
	a->block.data = b->block.data;
	b->block.data = swap;
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

int	not_in(t_list	*li, int i, int j)
{
	t_list  *temp;

	temp = li;
	while (temp != NULL)
	{
		if (temp->block.row == i && temp->block.col == j)
			return (false);
		temp = temp->next;
	}
	return (true);
}
