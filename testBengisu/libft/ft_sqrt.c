/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:07:59 by bkandemi          #+#    #+#             */
/*   Updated: 2022/06/22 19:42:41 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_sqrt(int nb)
{
	float	approx_1;
	float	approx_2;
	float	approx_3;
	int		i;

	approx_1 = 0;
	while (approx_1 * approx_1 <= nb)
		approx_1 += 0.1;
	approx_2 = approx_1;
	i = 0;
	while (i < 10)
	{	
		approx_3 = nb;
		approx_3 /= approx_2;
		approx_3 += approx_2;
		approx_3 /= 2;
		approx_2 = approx_3;
		i++;
	}
	return (approx_3);
}
