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
    t_list  *block_piece;

    i = 0;
    counter = 0;
    block_piece = info->li_piece;
    while (i < size)
    {
        if (map[coord[i].row][coord[i].col] == info->you && block_piece->block.data)
            counter += 1;
        i++;
        block_piece = block_piece->next;
    }
    if (counter == 1)
        return (0);
    return (1);
}

int overlapping_opp(t_coords coord[], char **map, t_filler *info, int size)
{
    int i;
    int counter;
    t_list  *block_piece;

    i = 0;
    counter = 0;
    block_piece = info->li_piece;
    while (i < size)
    {
        if (map[coord[i].row][coord[i].col] == info->opp && block_piece->block.data)
            return (1);
        i++;
        block_piece = block_piece->next;
    }
    return (0);
}

int  we_can_place(t_coords coord[], t_filler *info)
{
    if (out_of_map(coord, info->map, info->size_piece))
        return (0);
    if (overlapping_you(coord, info->map2d, info, info->size_piece))
        return (0);
    if (overlapping_opp(coord, info->map2d, info, info->size_piece))
        return (0);
    return (1);
}