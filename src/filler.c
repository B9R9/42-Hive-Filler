#include "filler.h"
#include "libft.h"


int main (void)
{
	char *line;

	while(ft_get_next_line(0, &line))
		print_fd("retour.txt", line);
	return (0);
}
