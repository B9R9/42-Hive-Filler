#include "filler.h"

void	free_info(t_info **info)
{
	if (info && *info)
	{
		ft_strdel(&((*info)->map));
		free(*info);
		*info = NULL;
	}
}

void	free_piece(t_piece **piece)
{
	if (piece && *piece)
	{
		ft_strdel(&((*piece)->piece));
		free(*piece);
		*piece = NULL;
	}
}
