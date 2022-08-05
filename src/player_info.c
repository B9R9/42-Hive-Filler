/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:14:08 by briffard          #+#    #+#             */
/*   Updated: 2022/08/05 13:41:01 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


/* *
 * Doit on verifier que toutes la lignes soientt exactement les memes ou juste
 * focus sur les parties qui nous interresse
 * */
void	get_player_info(t_info *info)
{
	char	*line;

	line = NULL;
	if (ft_get_next_line(0, &line) < 1)
		panic("In player_info: get_player_info: retour GNL", info);
	if (ft_strncmp("$$$ exec p", line, 10) != 0)
		panic("Error player info: strcmp", info);
	info->player = ft_atoi(&line[10]);
	if (info->player != 1 && info->player != 2)
		panic("Error player info: retour atoi", info);
	info->opposite = (info->player == 1) + 1;
	if (!ft_strnstr(line, "briffard.filler", ft_strlen(line)))
		panic("Error player info: ret_strnstr", info);
	ft_strdel(&line);
}

void	get_map_info(t_info *info)
{
	char	*line;

	line = NULL;
	if (ft_get_next_line(0, &line) < 1)
		panic("In player_info: get_map_info: GNL ret", info);
	if (strncmp("Plateau", line, ft_strlen("Plateau")) != 0)
		panic("In get_map_info: get_map_info: Checking beginning", info);
	info->line = ft_atoi(&line[8]);
	if (info->line < 1)
		panic("In get_map_info: get_map_info: line dimension", info);
	info->col = ft_atoi(&line[8 + ft_numlength(info->line)]);
	if (info->col < 1)
		panic("In get_map_info: get_map_info: col dimension", info);
	ft_strdel(&line);
	if (info->player == 2)
		info->symbol = 'X';
}

void	get_map(t_info *info)
{
	skip_line(info);
	get_lines(info->line, &info->map);
}

t_piece	*get_piece(t_info *info)
{
	(void)info;
	char	*line;
	t_piece	*piece;

	line = NULL;
	if (ft_get_next_line(0, &line) < 1)
		panic("In get_piece: GNL ret", info);
	if (strncmp("Piece ", line, ft_strlen("Piece ")) != 0)
		panic("In get_piece: Checking beginning", info);
	piece = create_piece();
	piece->line = ft_atoi(&line[6]);
	if (piece->line < 0)
		panic("In get_piece: line dimension", info);
	piece->col = ft_atoi(&line[6 + ft_numlength(piece->line)]);
	if (piece->col < 0)
		panic("In get_piece: col dimension", info);
	ft_strdel(&line);
	get_lines(piece->line, &piece->piece);
	print_fd("piece.txt", piece->piece);
	return (piece);
}
