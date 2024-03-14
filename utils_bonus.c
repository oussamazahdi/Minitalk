/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:42:18 by ozahdi            #+#    #+#             */
/*   Updated: 2024/03/11 10:10:12 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + '0');
	}
}

int	ft_strlen(char *av)
{
	int		i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	ft_atoi(char *src)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (src[i])
	{
		if (src[i] >= '0' && src[i] <= '9')
			i++;
		else
			return (-1);
	}
	while (*src >= '0' && *src <= '9')
	{
		result *= 10;
		result += *src++ - '0';
	}
	return (result);
}
