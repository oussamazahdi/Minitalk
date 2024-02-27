/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:18:45 by ozahdi            #+#    #+#             */
/*   Updated: 2024/02/27 09:16:10 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
    while (i <= len)
    {
        if(src[i] == 0)
            kill(pid,SIGUSR1);
        else if(src[i] == 1)
            kill(pid,SIGUSR2);
        usleep(10000);
        i++;
    }
}
int main(int ac, char **av)
{
    if(ac == 3) {
        int *res;
        int i;
        int x;
        int j = 0;
        int *tmp;
        int len =(ft_strlen(av[2])) * 8;
        // int l = 0;
        
        i = 0;
        x = 0;
        res = malloc(ft_strlen(av[2]) * 8 * sizeof(int));
        if(!res)
            return 0;
        while (av[2][i]) {
            tmp = con_bit(av[2][i]);
            j = 0;
            while (j < 8)
                res[x++] = tmp[j++];
            i++;
            free(tmp);
        }
        // printf("oussama in binary is : ");
        // printf("Binary representation of '%s': ", av[2]);
        // for (int k = 0; k < (ft_strlen(av[2]) * 8); k++) { // Correct loop condition
        //     printf("%d", res[k]);
        // }
        // printf("\n");
        // while (l < len)
        // {
        //     printf("%d",res[l]);
        //     l++;
        // }
        
        ft_send(res, atoi(av[1]), len);
        free(res);
    }
    else
        printf("You should to enter two arguments : Server PID & Message");
}
