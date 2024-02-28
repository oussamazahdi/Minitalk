/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:24:44 by nsidqi            #+#    #+#             */
/*   Updated: 2024/02/28 19:36:14 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
// void ft_printy(int signum)
// {
//     static int arr[8];
//     static int x;
//     static int character;
//     int  i;

//     x = 0;
//     i = 0;
//     character = 0;
//     if(signum == SIGUSR1)
//         arr[x++] = 0;
//     else if(signum == SIGUSR2)
//         arr[x++] = 1;
//     if(x == 8)
//     {
//         while(i < 8) 
//         {
//             character |= arr[i] << (7 - i);
//             i++;
//         }
//         write(1,&character,1);
//         x = 0;
//         character = 0;
//     }
// }
// void signal_hundler(int signum,siginfo_t *info, void *content)
// {
//     static int arr[8];
//     static int x = 0;
//     static int character = 0;
//     static int pid;
//     int i = 0;
//     (void)content;
// 	if (!pid)
// 		pid = info->si_pid;
// 	if (pid != info->si_pid)
// 	{
// 		character = 0;
// 		x = 0;
// 		pid = 0;
// 	}
//     if(signum == SIGUSR1 || signum == SIGUSR2)
//         ft_printy(signum);
// }
// int main()
// {
//     int pid = getpid();
//     struct sigaction sa;
//     sa.sa_sigaction = signal_hundler;
//     sa.sa_flags = SA_SIGINFO;
//     sigaction(SIGUSR1,&sa,NULL);
//     sigaction(SIGUSR2,&sa,NULL);
//     printf("server PID : %d\n",pid);
//     while (1)
//         pause();
// }
void signal_hundler(int signum)
{
    static int arr[8];
    static int x = 0;
    static int character = 0;
    int i = 0;
    if(signum == SIGUSR1)
        arr[x++] = 0;
    else if(signum == SIGUSR2)
        arr[x++] = 1;
    if(x == 8)
    {
        while(i < 8) 
        {
            character |= arr[i] << (7 - i);
            i++;
        }
        write(1,&character,1);
        x = 0;
        character = 0;
    }
}
int main()
{
    int pid = getpid();
    struct sigaction sa;
    sa.sa_handler = signal_hundler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1,&sa,NULL);
    sigaction(SIGUSR2,&sa,NULL);
    printf("server PID : %d\n",pid);
    while (1)
        pause();
}
