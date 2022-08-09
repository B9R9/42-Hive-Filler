#include "filler.h"


int main (void)
{
	t_info	*info;
	//t_piece	*piece;

	info = create_info();

	get_player_info(info);
	get_map_info(info);
	get_map (info);
	get_piece(info);

	ft_strdel(&info->map.map);
	ft_strdel(&info->piece.piece);
	free(info->map.d_map);
	free(info);
	info = NULL;
	system("leaks briffard.filler > ret_leaks.txt");
	return (0);
}
