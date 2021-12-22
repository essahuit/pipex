/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:09:37 by kessalih          #+#    #+#             */
/*   Updated: 2021/12/22 15:09:40 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	l;

	i = 0;
	if (!dst && !len)
		return (ft_strlen(src));
	l = ft_strlen(dst);
	if (len < ft_strlen(dst) + 1)
		return (ft_strlen(src) + len);
	while (src[i] && i < (len - l - 1))
	{
		dst[l + i] = src[i];
		i++;
	}
	dst[l + i] = '\0';
	return (l + ft_strlen(src));
}
