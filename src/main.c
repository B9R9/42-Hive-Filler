#include "filler.h"


double	ft_sqrt(double x)
{
	double	n;

	n = 1;
	if (x > 0)
	{
		while (n * n <= x)
		{
			if (n * n == x)
				return (n);
			n++;
		}
	}
	return (0);
}

double sqr(double a)
{
    return a*a;
}
 
double distance(t_coord a, t_coord b)
{
	double ab;

	ab = (sqr((double)b.line - (double)a.line)) - (sqr((double)b.col - (double)a.col));
	return (ft_sqrt(ab));
}

void	u_swap(unsigned int *a, unsigned int *b)
{
	unsigned	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

t_b_list	*sort_list(t_b_list *li, t_coord ref)
{
	t_b_list	*temp;
	t_b_list	*tempo;

	temp = li;
	while (temp)
	{
		tempo = temp->next;
		while (tempo)
		{
			if (distance(ref, temp->coord) > distance(ref, tempo->coord))
			{
				u_swap(&temp->coord.line, &temp->coord.line);
				u_swap(&temp->coord.col, &temp->coord.col);
			}
			tempo = tempo->next;
		}
		temp = temp->next;
	}
	return (li);
}


int main (void)
{
	t_info	*info;
	//t_piece	*piece;

	info = create_info();

	get_player_info(info);
	get_map_info(info);
	get_map (info);
	get_piece(info);
	dprintf(2,"%f\n", distance(info->target1, info->target2));
	ft_strdel(&info->map.map);
	ft_strdel(&info->piece.piece);
	free(info->map.d_map);
	free(info);
	info = NULL;
	system("leaks briffard.filler > ret_leaks.txt");
	return (0);
}
