#include "filler.h"

int  out_of_map(t_coords coord[], t_coords max, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (coord[i].col >= max.col)
            return (1);
        if (coord[i].col < 0)
            return (1);
        if (coord[i].row >= max.row)
            return (1);
        if (coord[i].row < 0)
            return (1);
        i++;
    }
    return (0);

}

int overlapping_you(t_coords coord[], char **map, t_filler *info, int size)
{
    int     i;
    int     counter;

    i = 0;
    counter = 0;
    while (i < size)
    {
        if (map[coord[i].row][coord[i].col] == info->you && coord[i].data)
            counter += 1;
        i++;
    }
    if (counter == 1)
        return (0);
    return (1);
}

int overlapping_opp(t_coords coord[], char **map, t_filler *info, int size)
{
    int i;
    int counter;

    i = 0;
    counter = 0;
    while (i < size)
    {
        if (map[coord[i].row][coord[i].col] == info->opp && coord[i].data)
            return (1);
        i++;
    }
    return (0);
}

int  we_can_place(t_coords coord[], t_filler *info)
{
	/*	for(int x = 0; x < info->size_piece; x++)
		{	
			dprintf(2, "COORDs: %d %d %d\n", coord[x].row, coord[x].col, coord[x].data);
		 	dprintf(2,"\n");
		 }
	 dprintf(2, "\n");
	 */
    if (out_of_map(coord, info->map, info->size_piece))
        return (0);
    if (overlapping_you(coord, info->map2d, info, info->size_piece))
        return (0);
    if (overlapping_opp(coord, info->map2d, info, info->size_piece))
        return (0);
    return (1);
}