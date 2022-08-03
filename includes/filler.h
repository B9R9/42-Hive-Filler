/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:54:54 by briffard          #+#    #+#             */
/*   Updated: 2022/08/03 11:55:06 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

/*includes*/
# include<fcntl.h>
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include <string.h>
# include "libft.h"

void	print_fd(char *filename, char *message);

#endif
