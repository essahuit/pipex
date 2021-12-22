/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:10:08 by kessalih          #+#    #+#             */
/*   Updated: 2021/12/22 15:10:12 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(to_find) == 0 && ft_strlen(str) != 0)
		return (str);
	if (ft_strlen(str) == ft_strlen(to_find))
	{
		if (ft_strcmp(str, to_find) == 0)
			return (str);
		return (0);
	}
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (str[j + i] == to_find[j] && to_find[j] != '\0')
				j++;
			if (j == ft_strlen(to_find))
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
