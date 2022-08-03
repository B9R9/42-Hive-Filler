/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:28:45 by briffard          #+#    #+#             */
/*   Updated: 2022/08/03 11:35:00 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PRINTF_H
# define MINI_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "colors.h"
# include "libft.h"

typedef struct s_string {
	char				*str;
	size_t				size;
	struct s_string		*next;
}	t_string;

/*DISPATCH TABLE*/
/*FUNCTION IN DISPATCH FLAG ARRAY*/
void			conv_to_str(t_string **li, va_list ap);

typedef void					(*t_dispatchflags)(t_string **li, va_list ap);
static const t_dispatchflags	g_funcflagsarray[26] = {
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	conv_to_str,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
};

int				mini_printf(const char *formart, ...);
void			push_t_string(t_string **li, const char *str);
t_string		*new_node(const char *str);
size_t			write_all(char *str);

#endif
