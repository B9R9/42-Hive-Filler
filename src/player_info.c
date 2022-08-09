/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:14:08 by briffard          #+#    #+#             */
/*   Updated: 2022/08/09 14:46:27 by briffard         ###   ########.fr       */
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
	info->player.player = ft_atoi(&line[10]);
	if (info->player.player != 1 && info->player.player != 2)
		panic("Error player info: retour atoi", info);
	info->opponent.player = (info->player.player == 1) + 1;
	if (!ft_strnstr(line, "briffard.filler", ft_strlen(line)))
		panic("Error player info: ret_strnstr", info);
	ft_strdel(&line);
	if (info->player.player == 2)
	{
		info->player.symbol = 'X';
		info->opponent.symbol = 'O';
	}

}

void	get_map_info(t_info *info)
{
	char	*line;

	line = NULL;
	if (ft_get_next_line(0, &line) < 1)
		panic("In player_info: get_map_info: GNL ret", info);
	if (strncmp("Plateau", line, ft_strlen("Plateau")) != 0)
		panic("In get_map_info: get_map_info: Checking beginning", info);
	info->map.line = ft_atoi(&line[8]);
	if (info->map.line < 1)
		panic("In get_map_info: get_map_info: line dimension", info);
	info->map.col = ft_atoi(&line[8 + ft_numlength(info->map.line)]);
	if (info->map.col < 1)
		panic("In get_map_info: get_map_info: col dimension", info);
	ft_strdel(&line);
}

t_coord	find_opp(t_info *info)
{
	size_t max_line;
	size_t max_col;
	size_t i;
	size_t j;

	i = 0;
	max_line = info->map.line;
	max_col = info->map.col;
	while (i < max_line)
	{
		j = 0;
		while( j < max_col)
		{
			if (ft_toupper(info->map.d_map[i][j]) == info->opponent.symbol)
				return((t_coord){.line = i, .col = j});
			j++;
		}
		i++;
	}
	return (t_coord){.line = 0, .col = 0};
}


/*NO place for anticipation*/
void	attribute_targets(t_coord opp, t_info *info)
{
	info->target1 = (t_coord){.line = opp.line - 1, .col = opp.col};
	info->target2 = (t_coord){.line = opp.line + 1, .col = opp.col};
}

void	define_targets(t_info *info)
{
	t_coord	opp;
	
	opp = find_opp(info);
	attribute_targets(opp, info);
}

void	get_map(t_info *info)
{
	skip_line(info);
	get_lines(info->map.line, &info->map.map);
	info->map.d_map = create_d_map(info);
	info = create_list(info);
	define_targets(info);

}

void	get_piece(t_info *info)
{
	char	*line;

	line = NULL;
	if (ft_get_next_line(0, &line) < 1)
		panic("In get_piece: GNL ret", info);
	if (strncmp("Piece ", line, ft_strlen("Piece ")) != 0)
		panic("In get_piece: Checking beginning", info);
	//info->piece = create_piece();
	info->piece.line = ft_atoi(&line[6]);
	if (info->piece.line < 0)
		panic("In get_piece: line dimension", info);
	info->piece.col = ft_atoi(&line[6 + ft_numlength(info->piece.line)]);
	if (info->piece.col < 0)
		panic("In get_piece: col dimension", info);
	ft_strdel(&line);
	get_lines(info->piece.line, &info->piece.piece);
	print_fd("piece.txt", info->piece.piece);
}
