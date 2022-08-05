/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:03:00 by briffard          #+#    #+#             */
/*   Updated: 2022/08/04 10:11:56 by briffard         ###   ########.fr       */
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

t_piece	*create_piece(void)
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
