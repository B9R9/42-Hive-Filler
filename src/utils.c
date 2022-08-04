#include "filler.h"

void	print_fd(char *filename, char *message)
{
	int	fd;

	fd = open (filename, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
	{
		perror("Impossible de lire file\n");
		exit(1);
	}
	else
	{
		write (fd, message, strlen(message));
		ft_putstr_fd("\n", fd);
		close(fd);
	}
}

void	skip_line(t_info *info)
{
	char	*line;

	line = NULL;
	if (ft_get_next_line(0, &line) < 1)
		panic("In utils.c: skip_line: retour GNL", info);
	ft_strdel(&line);
}
