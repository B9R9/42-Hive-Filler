#include "filler.h"

int	main(void)
{
	t_filler	*info;

	info = new_struct();
	set_info_game(info);
	while (1)
	{
		set_piece(info);
		solver(info);
	}

	return (0);
}
