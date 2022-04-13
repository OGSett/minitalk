/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:02:05 by yel-mekk          #+#    #+#             */
/*   Updated: 2022/04/11 00:02:10 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*ascii_to_binary(char c)
{
	char	*binary_chain;
	int		i;

	binary_chain = malloc(9);
	i = 7;
	while (i >= 0)
	{
		binary_chain[i--] = (c % 2) + '0';
		c = c / 2;
	}
	binary_chain[8] = '\0';
	return (binary_chain);
}

static void	send_8bit_blocks(int pid, char	*binary_chain)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		if (binary_chain[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(700);
	}
}

int	main(int ac, char **av)
{
	char	*binary_chain;
	int		i;
	int		pid;

	i = -1;
	if (ac != 3)
	{
		ft_printf("please recheck your arguments!\n");
		return (-1);
	}
	pid = compute_num(av[1]);
	if (pid <= 0 || kill(pid, 0) == -1)
	{
		ft_printf("please recheck your arguments!\n");
		return (-1);
	}
	while (av[2][++i])
	{
		binary_chain = ascii_to_binary(av[2][i]);
		send_8bit_blocks(pid, binary_chain);
		free(binary_chain);
	}
	return (0);
}
