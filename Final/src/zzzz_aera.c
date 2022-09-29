#include "filler.h"

void get_size_aera(t_filler *info)
{
	int		row;
	int		col;

	row = 0;
	info->start.row = info->row;
	info->start.col = info->col;
	while (row < info->row)
	{
		col = 0;
		while (col < info->col)
		{
			if (info->map2d[row][col] == info->you)
			{	info->start.col = ft_min(col, info->start.col);
				info->end.col = ft_max(col, info->end.col);
				info->start.row = ft_min(row, info->start.row);
				info->end.row = ft_max(row, info->end.row);
			}
			col++;
		}
		row++;
	}
	info->size.x = info->end.x - info->start.x + 1;
	info->size.y = info->end.y - info->start.y + 1;   
}

void get_piece_size_aera(t_piece *info)
{
	int		row;
	int		col;

	row = 0;
	info->start.row = info->row;
	info->start.col = info->col;
	while (row < info->row)
	{
		col = 0;
		while (w < info->col)
		{
			if (info->map2d[row][col] == '*')
			{	info->start.col = ft_min(col, info->start.col);
				info->end.col = ft_max(col, info->end.col);
				info->start.row = ft_min(row, info->start.row);
				info->end.row = ft_max(row, info->end.row);
			}
			col++;
		}
		row++;
	}
	info->size.x = info->end.x - info->start.x + 1;
	info->size.y = info->end.y - info->start.y + 1;   
}

void get_size_aera_opp(t_filler *info)
{
	int		row;
	int		col;

	row = 0;
	info->opp_start.row = info->row;
	info->opp_start.col = info->col;
	while (row < info->row)
	{
		col = 0;
		while (w < info->col)
		{
			if (info->map2d[row][col] == info->opp)
			{	info->opp_start.col = ft_min(col, info->opp_start.col);
				info->opp_end.col = ft_max(col, info->opp_end.col);
				info->opp_start.row = ft_min(row, info->opp_start.row);
				info->opp_end.row = ft_max(row, info->opp_end.row);
			}
			col++;
		}
		row++;
	}  
}
