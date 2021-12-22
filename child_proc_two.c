/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:05:59 by kessalih          #+#    #+#             */
/*   Updated: 2021/12/22 15:06:04 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	child_proc_two(char **envp, char *cmd, int *fd, int fd2)
{
	char	*path;
	char	**arpath;
	char	*cmdexec;
	char	**ar;

	dup2(fd2, 1);
	close(fd2);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	ar = ft_split(cmd, ' ');
	path = ft_strdup(ft_path(envp) + 5);
	arpath = ft_split(path, ':');
	cmdexec = ft_access(cmd, arpath);
	if (execve(cmdexec, ar, NULL) == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
}
