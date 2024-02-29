#include "minitalk.h"
/*------------------------------< Client >------------------------------*/
int *con_bit(int c)
{
    int i;
    int x;
    int tmp;
    int *arr;

    i = 8;
    x = 0;
    arr = malloc(8 * sizeof(int));
    while (i--)
    {
        tmp = ((c >> i) & 1);
        arr[x++] = tmp;
    }
    return arr;
}

void ft_send(int *res, int pid , int len)
{
    int *src;
    src = res;
    int i = 0;
    while (i < len)
    {
        if(src[i] == 0)
            kill(pid,SIGUSR1);
        else if(src[i] == 1)
            kill(pid,SIGUSR2);
        usleep(350);
        usleep(100);
        i++;
    }
}

int main(int ac, char **av)
{
    if(ac == 3)
    {
        int     i;
        int     x;
        int     j;
        int     *tmp;
        int     len;
        
        i = 0;
        x = 0;
        len = ft_strlen(av[2]) * 8;
        int     res[len * sizeof(int)];
        while (av[2][i]) {
            tmp = con_bit(av[2][i]);
            j = 0;
            while (j < 8)
                res[x++] = tmp[j++];
            i++;
            free(tmp);
        }
        ft_send(res, ft_atoi(av[1]), len);
    }
}
/*------------------------------< Server >------------------------------*/
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
    ft_putstr("Server PID : ");
    ft_putnbr(pid);
    while (1)
        pause();
}
/*------------------------------< Utils >------------------------------*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_putnbr(int nb)
{
    if(nb > 9)
    {
        ft_putnbr(nb / 10);
        ft_putchar((nb % 10) + '0');
    }
    if (nb>= 0 && nb <= 9)
    {
        ft_putchar(nb + '0');
    }
}
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
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
    while (str[i])
    {   
        ft_putchar(str[i]);
        i++;
    }
}