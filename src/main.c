/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:50:46 by briffard          #+#    #+#             */
/*   Updated: 2022/09/29 15:29:01 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	t_filler		*info;
	t_piece			*piece;

	if (create_struct(&info, &piece))
		return (clean_all(info, piece));
	if (set_player_info(info))
		return (clean_all(info, piece));
	if (new_map(&info))
		return (clean_all(info, piece));
	while (1)
	{
		if (new_token(&piece) || !find_place(info, piece))
			break ;
		print_solution(info->solution);
		if (update_info(info, piece))
			break ;
	}
	print_solution((t_coords){0, 0, 0});
	info = clean_filler(info);
	piece = clean_piece(piece);
	return (0);
}
