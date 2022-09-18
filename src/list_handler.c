/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:20:15 by briffard          #+#    #+#             */
/*   Updated: 2022/09/18 23:28:41 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_list	*new_node(int row, int col, t_bool block)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(*node));
	if (!node)
		exit(EXIT_FAILURE);
	node->row = row;
	node->col = col;
	node->data = block;
	node->next = NULL;
	return (node);
}

t_list	*push_back_piece(t_list *li, int row, int col, t_bool block)
{
	t_list	*node;
	t_list	*temp;

	node = new_node(row, col, block);
	if (li == NULL)
		return (node);
	temp = li;
	while (temp->next != NULL)
		temp =  temp->next;
	temp->next = node;
	return (li);
}
