/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:18:45 by ozahdi            #+#    #+#             */
/*   Updated: 2024/03/05 16:01:49 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_x;

static void	ft_print(int signum, int character)
{
	static int	arr[8];
	int			i;

	i = 0;
	if (signum == SIGUSR1)
		arr[g_x++] = 0;
	else if (signum == SIGUSR2)
		arr[g_x++] = 1;
	if (g_x == 8)
	{
		while (i < 8)
		{
			character |= arr[i] << (7 - i);
			i++;
		}
		write(1, &character, 1);
		g_x = 0;
		character = 0;
	}
}

static void	signal_hundler(int signum, siginfo_t *info, void *context)
{
	static int		character;
	static pid_t	client_pid;

	(void)context;
	if (client_pid != info->si_pid)
	{
		g_x = 0;
		character = 0;
	}
	client_pid = info->si_pid;
	if (signum == SIGUSR1 || signum == SIGUSR2)
		ft_print(signum, character);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	sa.sa_sigaction = signal_hundler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "Server PID : ", 14);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
}
