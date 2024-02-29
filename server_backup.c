// #include "minitalk.h"
// int main()
// {
//     int a = 97;
//     printf("shifting a >> 1 = %d\n", a >> 30);
//     printf("shifting a << 1 = %d", a << 9);
// }
// #include "minitalk.h"

// int bits[8];
// int current_bit = 0;
// void handle_sigusr1(int sig) {
//     bits[current_bit++] = 0;
//     if (current_bit == 8) {
//         int character = 0;
//         for (int i = 0; i < 8; i++) {
//             character |= bits[i] << (7 - i);
//         }
//         printf("%c", character);
//         fflush(stdout);
//         current_bit = 0;
//     }
// }

// void handle_sigusr2(int sig) {
//     bits[current_bit++] = 1;
//     if (current_bit == 8) {
//         int character = 0;
//         for (int i = 0; i < 8; i++) {
//             character |= bits[i] << (7 - i);
//         }
//         printf("%c", character);
//         fflush(stdout);
//         current_bit = 0;
//     }
// }

// int main() {
//     printf("Server started. PID: %d\n", getpid());

//     struct sigaction usr1;
//     usr1.sa_handler = handle_sigusr1;
//     sigemptyset(&usr1.sa_mask);
//     usr1.sa_flags = 0;
//     sigaction(SIGUSR1, &usr1, NULL);

//     struct sigaction usr2;
//     usr2.sa_handler = handle_sigusr2;
//     sigemptyset(&usr2.sa_mask);
//     usr2.sa_flags = 0;
//     sigaction(SIGUSR2, &usr2, NULL);

//     while (1) {
//         pause(); // Wait for signals
//     }

//     return 0;
// }


#include "minitalk.h"
void ft_printy(int signum)
{
    static int arr[8];
    static int x = 0;
    static int character = 0;
    int  i = 0;
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
void signal_hundler(int signum,siginfo_t *info, void *content)
{
    static int arr[8];
    static int x = 0;
    static int character = 0;
    static int pid;
    int i = 0;
    (void)content;
	if (!pid)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		character = 0;
		x = 0;
		pid = 0;
	}
    if(signum == SIGUSR1 || signum == SIGUSR2)
        ft_printy(signum);
    // if(signum == SIGUSR1)
    //     arr[x++] = 0;
    // else if(signum == SIGUSR2)
    //     arr[x++] = 1;
    // if(x == 8)
    // {
    //     while(i < 8) 
    //     {
    //         character |= arr[i] << (7 - i);
    //         i++;
    //     }
    //     write(1,&character,1);
    //     x = 0;
    //     character = 0;
    // }
}
int main()
{
    int pid = getpid();
    struct sigaction sa;
    sa.sa_sigaction = signal_hundler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1,&sa,NULL);
    sigaction(SIGUSR2,&sa,NULL);
    printf("server PID : %d\n",pid);
    while (1)
        pause();
}





























// #include "minitalk.h"
// int main()
// {
//     int a = 97;
//     printf("shifting a >> 1 = %d\n", a >> 30);
//     printf("shifting a << 1 = %d", a << 9);
// }
// #include "minitalk.h"

// int bits[8];
// int current_bit = 0;
// void handle_sigusr1(int sig) {
//     bits[current_bit++] = 0;
//     if (current_bit == 8) {
//         int character = 0;
//         for (int i = 0; i < 8; i++) {
//             character |= bits[i] << (7 - i);
//         }
//         printf("%c", character);
//         fflush(stdout);
//         current_bit = 0;
//     }
// }

// void handle_sigusr2(int sig) {
//     bits[current_bit++] = 1;
//     if (current_bit == 8) {
//         int character = 0;
//         for (int i = 0; i < 8; i++) {
//             character |= bits[i] << (7 - i);
//         }
//         printf("%c", character);
//         fflush(stdout);
//         current_bit = 0;
//     }
// }

// int main() {
//     printf("Server started. PID: %d\n", getpid());

//     struct sigaction usr1;
//     usr1.sa_handler = handle_sigusr1;
//     sigemptyset(&usr1.sa_mask);
//     usr1.sa_flags = 0;
//     sigaction(SIGUSR1, &usr1, NULL);

//     struct sigaction usr2;
//     usr2.sa_handler = handle_sigusr2;
//     sigemptyset(&usr2.sa_mask);
//     usr2.sa_flags = 0;
//     sigaction(SIGUSR2, &usr2, NULL);

//     while (1) {
//         pause(); // Wait for signals
//     }

//     return 0;
// }


#include "minitalk.h"
void ft_printy(int signum)
{
    static int arr[8];
    static int x;
    static int character;
    int  i;

    x = 0;
    i = 0;
    character = 0;
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
void signal_hundler(int signum,siginfo_t *info, void *content)
{
    static int arr[8];
    static int x = 0;
    static int character = 0;
    static int pid;
    int i = 0;
    (void)content;
	if (!pid)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		character = 0;
		x = 0;
		pid = 0;
	}
    if(signum == SIGUSR1 || signum == SIGUSR2)
        ft_printy(signum);
}
int main()
{
    int pid = getpid();
    struct sigaction sa;
    sa.sa_sigaction = signal_hundler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1,&sa,NULL);
    sigaction(SIGUSR2,&sa,NULL);
    printf("server PID : %d\n",pid);
    while (1)
        pause();
}




/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:24:44 by nsidqi            #+#    #+#             */
/*   Updated: 2024/02/27 20:26:53 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
void ft_print(int signum)
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
void signal_hundler(int signum,siginfo_t *info, void *context)
{
    static int arr[8];
    static int x = 0;
    static int character = 0;
    int i = 0;
    static pid_t			client_pid;

	(void)context;
	if (client_pid != info->si_pid)
	{
		x = 0;
		character = 0;
	}
	client_pid = info->si_pid;
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
    sa.sa_sigaction = signal_hundler;
    // sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1,&sa,NULL);
    sigaction(SIGUSR2,&sa,NULL);
    printf("server PID : %d\n",pid);
    while (1)
        pause();
}