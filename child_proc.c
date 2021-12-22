/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:04:15 by kessalih          #+#    #+#             */
/*   Updated: 2021/12/22 15:05:32 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	child_proc(char **envp, char *cmd, int *fd, int fd1)
{
	char	*path;
	char	**arpath;
	char	*cmdexec;
	char	**ar;

	dup2(fd1, 0);
	close(fd1);
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
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
