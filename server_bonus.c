/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:18:45 by ozahdi            #+#    #+#             */
/*   Updated: 2024/03/11 10:10:45 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_x;

static void	ft_print(int signum, int character, int c_pid)
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
		kill(c_pid, SIGUSR1);
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
		ft_print(signum, character, client_pid);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_sigaction = signal_hundler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	write(1, "Server Bonus PID : ", 20);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
}
