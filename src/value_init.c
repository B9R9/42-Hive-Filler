/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:40:44 by briffard          #+#    #+#             */
/*   Updated: 2022/08/08 16:08:49 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_info(t_info *info)
{
	info->player = 0;
	info->opposite = 0;
	info->line = 0;
	info->col = 0;
	info->map = NULL;
	info->d_map = NULL;
	info->symbol = 'O';
	info->adv_symbol = 'X';
}
