#include "filler.h"


int free_loop_space(t_coords start, t_coords end, t_filler *info)
{
	int ref_col;

	ref_col = start.col;
	while (start.row <= end.row && start.col <= end.col)
	{
		if (info->map2d[start.row][start.col] == '.')
			return (true);
		if(start.col == end.col)
		{
			start.row++;
			start.col = ref_col - 1;
		}
		start.col++;
	}
	return (false);
}

int	free_space(int row, int col, t_filler *info)
{
	t_coords	start;
	t_coords	end;

	start = (t_coords){.row = row - 1, .col = col - 1};
	end = (t_coords) {.row = row + 1, .col = col + 1};
	if (row == 0)
		start.row = 0;
	if (end.row ==  info->map.row)
		end.row = info->map.row - 1;
	if (col == 0)
		start.col = 0;
	if (end.col == info->map.col)
		end.col = info->map.col - 1;
	if (free_loop_space(start, end, info))
		return (true);
	return (false);
}

