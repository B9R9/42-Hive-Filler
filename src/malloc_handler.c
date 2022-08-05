/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:03:00 by briffard          #+#    #+#             */
/*   Updated: 2022/08/05 13:41:19 by briffard         ###   ########.fr       */
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

char	**create_d_map(t_info *info)
{
	char	**new;
	size_t	i;
	size_t	max_line;
	size_t	j;

	i = 0;
	max_line = info->line;
	j = 4;
	new = (char **)malloc(sizeof(char *) * info->line);
	if (!new)
		panic("In malloc_handler: create_d_map:", info);
	while (i < max_line)
	{
		new[i] = &info->map[j];
		j += 5 + info->col;
		i++;
	}
	return (new);
}
