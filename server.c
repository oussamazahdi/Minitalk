#include "minitalk.h"
void ft_print(int signum, int character)
{
    static int arr[8];
    static int x = 0;
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
    static int character = 0;
    static pid_t			client_pid;

	(void)context;
	if (client_pid != info->si_pid)
	{
		character = 0;
	}
	client_pid = info->si_pid;
    if(signum == SIGUSR1 || signum == SIGUSR2)
        ft_print(signum, character);
}
int main()
{
    int pid = getpid();
    struct sigaction sa;
    sa.sa_sigaction = signal_hundler;
    sa.sa_flags = 0;
    sigaction(SIGUSR1,&sa,NULL);
    sigaction(SIGUSR2,&sa,NULL);
    printf("server PID : %d\n",pid);
    while (1)
        pause();
}
// void ft_print(int signum)
// {
//     static int arr[8];
//     static int x = 0;
//     static int character = 0;
//     int i = 0;
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






// void signal_hundler(int signum,siginfo_t *info, void *context)
// {
//     static int arr[8];
//     static int x = 0;
//     static int character = 0;
//     int i = 0;
//     static pid_t			client_pid;

// 	(void)context;
// 	if (client_pid != info->si_pid)
// 	{
// 		x = 0;
// 		character = 0;
// 	}
// 	client_pid = info->si_pid;
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
// int main()
// {
//     int pid = getpid();
//     struct sigaction sa;
//     sa.sa_sigaction = signal_hundler;
//     // sigemptyset(&sa.sa_mask);
//     sa.sa_flags = 0;
//     sigaction(SIGUSR1,&sa,NULL);
//     sigaction(SIGUSR2,&sa,NULL);
//     printf("server PID : %d\n",pid);
//     while (1)
//         pause();
// }


