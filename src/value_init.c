/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:40:44 by briffard          #+#    #+#             */
/*   Updated: 2022/08/09 09:36:09 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_info(t_info *info)
{
	info->player.player = 1;
	info->player.symbol = 'O';
	info->opponent.player = 2;
	info->opponent.symbol = 'X';
	info->map.line = 0;
	info->map.col = 0;
	info->map.map = NULL;
	info->map.d_map = NULL;
}
