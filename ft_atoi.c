/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:08:35 by mwane             #+#    #+#             */
/*   Updated: 2021/06/15 15:06:01 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(char *nbr)
{
	long	nb;
	int		i;
	int		nega;
	int		m;

	nb = 0;
	i = 0;
	nega = -1;
	m = 1;
	while (nbr[i] == '\t' || nbr[i] == '\n' || nbr[i] == ' '
		|| nbr[i] == '\f' || nbr[i] == '\r' || nbr[i] == '\v')
		nbr++;
	if (nbr[i] == '+' || nbr[i] == '-')
	{
		nega += (nbr[i] - 44) + 1;
		i++;
	}
	while (nbr[i] && nbr[i] <= '9' && nbr[i] >= '0')
		i++;
	while (i > 0 && nbr[--i] <= '9' && nbr[i] >= '0')
	{
		nb += (nbr[i] - '0') * m;
		m *= 10;
	}
	return (-nb * nega);
}
