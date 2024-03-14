/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:18:45 by ozahdi            #+#    #+#             */
/*   Updated: 2024/03/11 10:09:59 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_len;

static void	end_of_message_handler(int signum)
{
	static int	i;

	if (signum == SIGUSR1)
		i++;
	if (i == g_len)
		write(1, "Message has been received!\n", 28);
}

static int	*con_bit(int c)
{
	int		i;
	int		x;
	int		tmp;
	int		*arr;

	i = 8;
	x = 0;
	arr = malloc (8 * sizeof(int));
	while (i--)
	{
		tmp = ((c >> i) & 1);
		arr[x++] = tmp;
	}
	return (arr);
}

static void	ft_send(int *res, int pid, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (res[i] == 0)
			kill(pid, SIGUSR1);
		else if (res[i] == 1)
			kill(pid, SIGUSR2);
		usleep(70);
		usleep(50);
		i++;
	}
}

static int	*ft_fill(int *res, char *str)
{
	int	i;
	int	*tmp;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		tmp = con_bit(str[i]);
		j = 0;
		while (j < 8)
			res[x++] = tmp[j++];
		i++;
		free (tmp);
	}
	return (res);
}

int	main(int ac, char **av)
{
	int	*res;
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid == 0 || pid < 0)
		{
			write(1, "Invalid PID!\n", 14);
			return (-1);
		}
		g_len = ft_strlen(av[2]);
		res = malloc(g_len * 8 * sizeof(int));
		signal(SIGUSR1, end_of_message_handler);
		res = ft_fill(res, av[2]);
		ft_send(res, pid, (g_len * 8));
		free(res);
	}
	else
		write(1, "You need to enter two arguments : Server PID & Message!", 56);
	return (0);
}
