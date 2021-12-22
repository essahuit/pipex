/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:07:50 by kessalih          #+#    #+#             */
/*   Updated: 2021/12/22 15:07:53 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*ft_path(char **envp)
{
	int		i;
	char	*a;

	i = 0;
	a = "PATH=";
	while (envp[i])
	{
		if (ft_strstr(envp[i], a))
			return (envp[i]);
		i++;
	}
	ft_perror();
	return (NULL);
}
