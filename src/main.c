#include "filler.h"

void	reset(t_filler *info)
{
	if (info->line)
		ft_strdel(&info->line);
	info->piece.row = 0;
	info->piece.col = 0;
	info->piece.data = 0;
	if (info->li_piece)
		info->li_piece = clean_list(info->li_piece);
	info->soluce.row = 0;
	info->soluce.col = 0;
	info->soluce.data = 0;
}

char	**update_map_opp(t_filler *info)
{
	int		i;
	int		j;

	skip_line(info);
	skip_line(info);
	info->line = NULL;
	i = 0;
	while (i < info->map.row)
	{
		if (ft_get_next_line(0, &info->line) <= 0)
			panic("Retour GNL\n", info);
		j = 0;
		while (info->line[j] != '\0')
		{
			if (info->line[j] != '.')
				info->map2d[i][j - 4] = ft_toupper(info->line[j]);
			j++;
		}
		i++;
		ft_strdel(&info->line);
	}
	ft_strdel(&info->line);
	return (info->map2d);
}

char	**update_map(t_filler *info)
{
	t_coords	coords[info->size_piece];
	t_list		*ref_block;
	int			i;

	i = 0;
	ref_block = create_node(info->soluce.row, info->soluce.col, 0);
	init_coord(coords, info->size_piece);
	coord_generator(coords, ref_block, info->li_piece, info->li_piece);
	while (i < info->size_piece)
	{
		if (coords[i].data)
			info->map2d[coords[i].row][coords[i].col] = info->you;
		i++;
	}
	ref_block = clean_list(ref_block);
	return (info->map2d);
}

void	update(t_filler *info)
{
	info->map2d = update_map(info);
	info->map2d = update_map_opp(info);
	info->hmap = init_value(info->hmap, info->map.row, info->map.col);
	info->hmap = set_hmap(info);
	info->test = init_value(info->test, info->map.row, info->map.col);
	info->test = set_test(info);
	set_list_block(info);
}



int	main(void)
{
	t_filler	*info;

	info = new_struct();
	set_info_game(info);
	while (1)
	{
		set_piece(info);
		solver(info);
		update(info);
		reset(info);
	}
	info = clean_before_exit(info);
	system ("leaks briffard.filler >> leaks.report");
	return (0);
}
