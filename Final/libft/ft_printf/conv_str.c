/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:51:51 by briffard          #+#    #+#             */
/*   Updated: 2022/08/03 11:53:43 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_printf.h"

t_string	*new_node(const char *str)
{
	t_string	*node;

	node = (t_string *)malloc(sizeof(*node));
	if (!node)
		exit(EXIT_FAILURE);
	node->str = ft_strdup(str);
	node->size = 0;
	node->next = NULL;
	return (node);
}

t_string	*push_back(t_string *li, t_string *element)
{
	t_string	*temp;

	if (li == NULL)
		return (element);
	temp = li;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = element;
	element->next = NULL;
	return (li);
}

void	push_t_string(t_string **li, const char *str)
{
	t_string	*element;

	element = new_node(str);
	*li = push_back(*li, element);
	(*li)->size += 1;
}

void	format_str(const char *str, t_string **li)
{
	if (str == NULL)
		str = "(null)";
	if (is_bonus(str))
	{
		ft_putstr(str);
		return ;
	}
	push_t_string(li, str);
}

void	conv_to_str(t_string **li, va_list ap)
{
	format_str(va_arg(ap, char *), li);
}
