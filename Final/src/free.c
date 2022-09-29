/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:49:14 by briffard          #+#    #+#             */
/*   Updated: 2022/09/29 13:50:38 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	clean2str(char *s1, char *s2)
{
	if (s1)
		ft_strdel(&s1);
	if (s2)
		ft_strdel(&s2);
}

t_list	*clean_node(t_list *li)
{
	t_list	*temp;

	if (li->next == NULL)
	{
		free(li);
		li = NULL;
		return (li);
	}
	temp = li->next;
	free(li);
	li = NULL;
	return (temp);
}

t_list	*clean_list(t_list *li)
{
	while (li != NULL)
		li = clean_node(li);
	return (li);
}

int	clean_all(t_filler *info, t_piece *piece)
{
	if (info)
		info = clean_filler(info);
	if (piece)
		piece = clean_piece(piece);
	return (1);
}
