/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:19:43 by briffard          #+#    #+#             */
/*   Updated: 2022/08/04 09:21:07 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	panic(char *message, t_info *info)
{
	perror(message);
	if (info)
	{
		free(info);
		info = NULL;
	}
	exit(EXIT_FAILURE);
}
