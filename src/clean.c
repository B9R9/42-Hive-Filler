#include "filler.h"

t_list *clean_node(t_list *li)
{
    t_list *temp;

    if (li->next == NULL)
    {
        free(li);
        li = NULL;
        return (li);
    }
    temp = li->next;
    free(li);
    li = NULL;
    return (temp);
}

t_list  *clean_list(t_list *li)
{
    while (li != NULL)
        li = clean_node(li);
    return (li);
}

void freeArray(int **arr, size_t row)
{
	size_t	i;

	i = 0;
	while (i < row)
		free(arr[i++]);
	free(arr);
}

void	clean2str(char *s1, char *s2)
{
	if (s1)
		ft_strdel(&s1);
	if (s2)
		ft_strdel(&s2);
}

void    panic(char *mess, t_filler *info)
{
    (void)info;
    perror(mess);
    exit(EXIT_FAILURE);

}