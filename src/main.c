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

char	**update_map(t_filler *info)
{
	int		i;
	int		j;

	skip_line(info);
	skip_line(info);
	info->line = NULL;
	i = 0;
	while (i < info->map.row)
	{
		if (ft_get_next_line(0, &info->line) < 1)
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

void	update(t_filler *info)
{
	info->map2d = update_map(info);
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
	return (0);
}
