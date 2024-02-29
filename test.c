// #include "minitalk.h"
// // int *con_bit(int c)
// // {
// //     int i;
// //     int x;
// //     int tmp;
// //     int *arr;

// //     i = 8;
// //     x = 0;
// //     arr = malloc(8 * sizeof(int));
// //     while (i--)
// //     {
// //         tmp = ((c >> i) & 1);
// //         arr[x++] = tmp;
// //     }
// //     return arr;
// // }
// // int main() {
// //     int *binaryRepresentation;
// //     binaryRepresentation = con_bit('a'); // Call con_bit with ASCII value of 'a'
    
// //     printf("Binary representation of 'a': ");
// //     for (int i = 0; i < 8; i++) {
// //         printf("%d", binaryRepresentation[i]); // Print each bit of the binary representation
// //     }
// //     printf("\n");
    
// //     free(binaryRepresentation); // Free the allocated memory to prevent memory leaks
// //     return 0;
// // }
// #include <stdio.h>
// #include <stdlib.h>

// int *con_bit(int c) {
//     int i = 8;
//     int x = 0;
//     int *arr = malloc(8 * sizeof(int));
//     while (i--) {
//         arr[x++] = ((c >> i) & 1);
//     }
//     return arr;
// }

// int ft_strlen(char *av) {
//     int i = 0;
//     while (av[i])
//         i++;
//     return i;
// }
// void ft_send(int *res, int pid)
// {
//     int *src;
//     src = res;
//     int i = 0;
//     while (src[i])
//     {
//         if(src[i] == 0)
//         {
//             if(!(kill(pid,SIGUSR1)))
//                 exit(1);
//         }
//         else if(src[i] == 1)
//         {
//             if(!(kill(pid,SIGUSR2)))
//                     exit(1);
//         }
//         i++;
//     }
// }
// int main(int ac, char **av) {
//     if (ac == 3) {
//         int b = atoi(av[1]);
//         int len = ft_strlen(av[2]);
//         int *res = malloc(len * 8 * sizeof(int)); // Correct memory allocation
//         if (!res)
//             return 0;
//         int x = 0;
//         for (int i = 0; i < len; i++) {
//             int *tmp = con_bit(av[2][i]);
//             for (int j = 0; j < 8; j++) { // Correct copying of binary representation
//                 res[x++] = tmp[j];
//             }
//             free(tmp); // Free tmp to prevent memory leak
//         }
//         // printf("Binary representation of '%s': ", av[2]);
//         // for (int i = 0; i < len * 8; i++) { // Correct loop condition
//         //     printf("%d", res[i]);
//         // }
//         // printf("\n");
//         ft_send(res,b);
//         free(res); // Free res to prevent memory leak
//     } else {
//         printf("You should to enter two arguments: Server PID & Message\n");
//     }
//     return 0;
// }
#include <unistd.h>
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
int main()
{
    ft_putnbr(89766);
}