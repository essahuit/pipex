/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:06:31 by kessalih          #+#    #+#             */
/*   Updated: 2021/12/22 15:06:59 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*ft_checkaccess(char *cmd, char **cm)
{
	if (access(cmd, F_OK) == 0)
	{
		ft_free_two(cm);
		return (cmd);
	}
	return (NULL);
}

char	*ft_free_one(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (NULL);
}

char	*ft_access(char *cmd, char **arpath)
{
	char	*ncmd;
	char	*ocmd;
	char	**cm;
	int		i;

	i = 0;
	cm = ft_split(cmd, ' ');
	cmd = cm[0];
	if (ft_checkaccess(cmd, cm))
		return (cmd);
	ocmd = ft_strjoin("/", cmd);
	ft_free_two(cm);
	while (arpath[i])
	{
		ncmd = ft_strjoin(arpath[i], ocmd);
		if (access(ncmd, X_OK) == 0)
		{
			free(ocmd);
			return (ncmd);
		}
		i++;
		ft_free_one(ncmd, arpath[i]);
	}
	return (ft_free_one(ocmd, NULL));
}
