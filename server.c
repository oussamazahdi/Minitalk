/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:24:44 by nsidqi            #+#    #+#             */
/*   Updated: 2024/02/26 19:57:19 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_helper(int sig, char *chara, int *index)
{
	*chara = (*chara << 1) | (sig - SIGUSR1);
	(*index)++;
	if (*index == 8)
	{
		write(1, chara, 1);
		*chara = 0;
		*index = 0;
	}
}

void	ft_get(int sig, siginfo_t *info, void *content)
{
	static char	chara;
	static int	index;
	static int	pid;

	(void)content;
	if (!pid)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		chara = 0;
		index = 0;
		pid = 0;
	}
	if (sig == SIGUSR1 || sig == SIGUSR2)
		ft_helper(sig, &chara, &index);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_sigaction = ft_get;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	// ft_putnbr(pid);
	printf("PID : %d\n",pid);
	// write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
