#include "filler.h"

int we_place(t_filler *info, t_piece *piece, t_coords start, t_coords end)
{
    int temp;
    int place;

    place = false;
    temp = start.col;
    while (start.row <= end.row)
    {
        start.col = temp;
        while (start.col <= end.col)
        {
            if (place_is_ok(info, piece, start))
            {
                place = true;
                get_distance(info, piece, start);
            }
            start.col++;
        }
        start.row++;
    }
    return (place);
}

int find_place(t_filler *info, t_piece *piece)
{
    t_coords    play_aera_start;
    t_coords    play_aera_end;

    play_aera_start.col = info->start.col - piece->end.col;
    play_aera_start.row = info->start.row - piece->end.row;
    play_aera_end.col = info->end.col - piece->start.col;
    play_aera_end.row = info->end.row - piece->start.row;
    if (we_place(info, piece, play_aera_start, play_aera_end))
        return (1);
    return (0);
}