#include "filler.h"

int main (void)
{
	t_info	*info;
	t_piece	*piece;

	info = create_info();

	get_player_info(info);
	get_map_info(info);

	get_map(info);

	print_fd("info->map.txt", info->map);
	piece = get_piece(info);
	free_info(&info);
	free_piece(&piece);
	system("leaks briffard.filler > ret_leaks.txt");
	return (0);
}
