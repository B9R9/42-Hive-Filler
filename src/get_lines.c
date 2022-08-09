#include "filler.h"

void	get_lines(unsigned short nb_lines, char **dst)
{
	char	*line;
	size_t	i;
	char	*tmp;

	i = 0;
	while (i < nb_lines)
	{
		if (ft_get_next_line(0, &line) < 1)
			panic("In get_lines: ret_GNL", NULL);
		if (!(*dst))
		{
			*dst = ft_strdup(line);
			ft_strdel(&line);
			i++;
			continue ;
		}
		tmp = ft_strjoin(*dst, line);
		if (!tmp)
			panic("In get_lines: retour tmp", NULL);
		ft_strdel(dst);
		ft_strdel(&line);
		*dst = tmp;
		i++;
	}
}
