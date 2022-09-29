/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:25:43 by briffard          #+#    #+#             */
/*   Updated: 2022/08/03 11:25:59 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

/*DEFINE*/
/*COLOR*/
# define DEFAULT	"\x1B[0m"
# define RED		"\x1B[31m"
# define GREEN	"\x1B[32m"
# define YELLOW	"\x1B[33m"
# define BLUE	"\x1B[34m"
# define MAGENTA	"\x1B[35m"
# define CYAN	"\x1B[36m"
# define WHITE	"\x1B[37m"
/*FT_PRINTF*/
# define RESETALL	"\033[0m"
# define BOLD	"\033[1m"
# define UNDERLINED	"\033[4m"
# define BLINK	"\033[5m"
# define RESETBOLD	"\033[21m"
# define RESETUNDERLINED	"\033[24m"
# define RESETBLINK	"\033[25m"

#endif