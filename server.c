/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:34:03 by mwane             #+#    #+#             */
/*   Updated: 2021/06/15 15:21:08 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>

void        putchar(char ascii)
{
    write(1, &ascii, 1);
}
char	*ft_itoa(int nb);

void        sighandler(int signum)
{
  static int    ascii = 0;
  static int    power = 0;

  if (signum == SIGUSR1)
    ascii += 1 << (7 - power);
  if ((power += 1) == 8)
    {
      putchar(ascii);
      power = 0;
      ascii = 0;
    }
}


int     main(void)
{
    pid_t   pid;
    char    *buffer;
    int fd = open("pid.txt", O_RDWR | O_CREAT); 

    pid = getpid();
    buffer = ft_itoa(pid);
    write(1, buffer, 5);
    write(fd, buffer, 5);
    close(fd);
    signal(SIGUSR1, sighandler);
    signal(SIGUSR2, sighandler);
    while (42);
    return (0);
}