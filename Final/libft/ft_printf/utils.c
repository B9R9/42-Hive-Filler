/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:00:49 by briffard          #+#    #+#             */
/*   Updated: 2022/08/03 11:00:57 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_printf.h"

size_t	write_all(char *str)
{
	size_t	size;

	size = ft_strlen(str);
	write (1, str, size);
	return (size);
}
