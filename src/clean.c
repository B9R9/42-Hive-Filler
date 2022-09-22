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

t_filler    *clean_before_exit(t_filler *info)
{
    if (info->line)
        ft_strdel(&info->line);
    if (info->hmap)
        freeArray(info->hmap, info->map.row);
    if (info->test)
        freeArray(info->test, info->map.row);
    if (info->li_blocks)
        info->li_blocks = clean_list(info->li_blocks);
    if (info->li_piece)
        info->li_piece = clean_list(info->li_piece);
    if (info->map2d)
        free(info->map2d);
    if (info->strmap)
        ft_strdel(&info->strmap);
    free(info);
    return (NULL);
}

void    panic(char *mess, t_filler *info)
{
    perror(mess);
    info = clean_before_exit(info);
    system ("leaks briffard.filler  >> leaks.report");
    exit(EXIT_FAILURE);

}