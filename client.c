/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:18:45 by ozahdi            #+#    #+#             */
/*   Updated: 2024/02/28 19:35:25 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// int *con_bit(int c)
// {
//     int i;
//     int x;
//     int tmp;
//     int *arr;

//     i = 8;
//     x = 0;
//     arr = malloc(8 * sizeof(int));
//     while (i--)
//     {
//         tmp = ((c >> i) & 1);
//         arr[x++] = tmp;
//     }
//     return arr;
// }
// int ft_strlen(char *av)
// {
//     int i;

//     i = 0;
//     while (av[i])
//         i++;
//     return (i);
// }
// void ft_send(int *res, int pid , int len)
// {
//     int *src;
//     src = res;
//     int i = 0;
//     while (i < len)
//     {
//         if(src[i] == 0)
//             kill(pid,SIGUSR1);
//         else if(src[i] == 1)
//             kill(pid,SIGUSR2);
//         usleep(100);
//         i++;
//     }
// }

// int main(int ac, char **av)
// {
//     if(ac == 3)
//     {
//         int     i;
//         int     x;
//         int     j;
//         int     *tmp;
//         int     len;
        
//         i = 0;
//         x = 0;
//         len = ft_strlen(av[2]) * 8;
//         int     res[len * sizeof(int)];
//         while (av[2][i]) {
//             tmp = con_bit(av[2][i]);
//             j = 0;
//             while (j < 8)
//                 res[x++] = tmp[j++];
//             i++;
//             free(tmp);
//         }
//         ft_send(res, atoi(av[1]), len);
//     }
// }

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
int ft_strlen(char *av)
{
    int i;

    i = 0;
    while (av[i])
        i++;
    return (i);
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
        ft_send(res, atoi(av[1]), len);
    }
}
