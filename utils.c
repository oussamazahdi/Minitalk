/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:02:20 by ozahdi            #+#    #+#             */
/*   Updated: 2024/02/29 11:07:16 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
int ft_strlen(char *av)
{
    int i;

    i = 0;
    while (av[i])
        i++;
    return (i);
}
int	ft_atoi(char *src)
{
	int				sign;
	long long		result;
	long long		t;

	sign = 1;
	result = 0;
	while (*src == 32 || (*src >= 9 && *src <= 13))
		src++;
	if (*src == '+' || *src == '-')
	{
		if (*src == '-')
			sign = -1;
		src++;
	}
	while (*src >= '0' && *src <= '9')
	{
		t = result;
		result *= 10;
		result += *src++ - '0';
		if (result / 10 != t && sign == 1)
			return (-1);
		else if (result / 10 != t && sign == -1)
			return (0);
	}
	return (result * sign);
}