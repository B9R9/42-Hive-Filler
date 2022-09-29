/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:55:49 by briffard          #+#    #+#             */
/*   Updated: 2022/08/03 11:25:12 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_printf.h"

static t_string	*clean(t_string *li)
{
	t_string	*temp;

	if (li->next == NULL)
	{
		if (li->str)
			ft_strdel(&li->str);
		free(li);
		li = NULL;
		return (li);
	}
	temp = li->next;
	if (li->str)
		ft_strdel(&li->str);
	free(li);
	li = NULL;
	return (temp);
}

static size_t	print_all(t_string *li)
{
	t_string	*temp;
	char		*tempo;
	char		*dest;
	size_t		length;

	temp = li;
	dest = ft_strdup(temp->str);
	temp = temp->next;
	while (temp != NULL)
	{
		tempo = ft_strjoin(dest, temp->str);
		free(dest);
		dest = tempo;
		temp = temp->next;
	}
	length = write_all(dest);
	temp = li;
	while (temp != NULL)
		temp = clean(temp);
	ft_strdel(&dest);
	return (length);
}

static int	add_str_to_list(const char *format, t_string **li)
{
	char	*temp;
	size_t	i;

	i = 0;
	while (format[i] != '%' && format[i] != '\0')
		i++;
	temp = ft_strsub(format, 0, i);
	push_t_string(li, temp);
	free(temp);
	temp = NULL;
	return (i);
}

static void	dispatch(va_list ap, t_string **li, char c)
{
	g_funcflagsarray[c - 'a'](li, ap);
}

int	mini_printf(const char *format, ...)
{
	size_t		index;
	va_list		ap;
	t_string	*new;

	index = 0;
	new = NULL;
	va_start(ap, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			dispatch(ap, &new, format[index + 1]);
			index += 2;
		}
		else
			index += add_str_to_list(&format[index], &new);
	}
	va_end(ap);
	index = print_all(new);
	return (index);
}
