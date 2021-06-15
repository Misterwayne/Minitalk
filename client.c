/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:34:49 by mwane             #+#    #+#             */
/*   Updated: 2021/06/15 15:21:33 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *nbr);

void        decimal_conversion(char ascii, int power, int pid)
{
  	if (power > 0)
  	  decimal_conversion(ascii / 2, power - 1, pid);
  	if ((ascii % 2) == 1)
  	  kill(pid, SIGUSR1);
  	else
  	  kill(pid, SIGUSR2);
  	usleep(1);
}

void        ascii_to_binary(char *str, int pid, int code)
{
    int       i;

    i = 0;
    while (str[i] != '\0')
    {
        decimal_conversion(str[i], 7, pid);
        i += 1;
    }
}

int     main(void)
{
    int count = 0;
    char    buffer[10];
    int pid;
    int fd = open("pid.txt", O_RDWR | O_CREAT); 


    read(fd, &buffer, 10);
    pid = ft_atoi(buffer);
    ascii_to_binary("OkO\n", pid, 1);
    return 0;
}
