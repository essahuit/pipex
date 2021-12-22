/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:11:37 by kessalih          #+#    #+#             */
/*   Updated: 2021/12/22 15:17:44 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_perror(void)
{
	perror("");
	exit(EXIT_FAILURE);
}

void	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
		ft_perror();
	pid1 = fork();
	if (pid1 == -1)
		ft_perror();
	if (pid1 == 0)
		child_proc(envp, argv[2], fd, fd1);
	pid2 = fork();
	if (pid2 == -1)
		ft_perror();
	if (pid2 == 0)
		child_proc_two(envp, argv[3], fd, fd2);
	close(fd[1]);
	close(fd[0]);
	waitpid(pid2, NULL, 0);
	waitpid(pid1, NULL, 0);
}
