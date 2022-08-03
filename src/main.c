#include "filler.h"

void	panic(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}


int main (void)
{
	t_info	*info;
	char *line;

	info = NULL;
	while (1)
	{
		if (!info)
		{
			info = (t_info *)malloc(sizeof(*info));
			if (!info)
				panic("t_info");
			ft_get_next_line(0, &line);
			print_fd("line.txt",line);
			ft_get_next_line(0, &line);
			print_fd("plateau.txt", line);
		}
		mini_printf("8 2\n");
		while (ft_get_next_line(0, &line))
			print_fd("reste.txt", line);
	}
	return (0);
}
