/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:37:40 by kessalih          #+#    #+#             */
/*   Updated: 2021/12/22 15:14:05 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;

	if (argc == 5)
	{
		fd1 = open(argv[1], O_RDONLY);
		if (fd1 == -1)
			ft_perror();
		fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (fd2 == -1)
			ft_perror();
		pipex(fd1, fd2, argv, envp);
	}
	else
		write(2, "number of arguments not correct", 31);
}
