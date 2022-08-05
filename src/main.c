#include "filler.h"

int main (void)
{
	t_info	*info;

	info = create_info();

	get_player_info(info);
	get_map_info(info);
	get_map(info);
	//print_fd("info->map.txt", info->map);
	set_map(info);

	free(info->d_map);
	ft_strdel(&info->map);
	free(info);
	info = NULL;
	system("leaks briffard.filler > ret_leaks.txt");
	return (0);
}
