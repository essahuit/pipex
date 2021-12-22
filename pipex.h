/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kessalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:11:17 by kessalih          #+#    #+#             */
/*   Updated: 2021/12/22 16:44:05 by kessalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

void	child_proc_two(char **envp, char *cmd, int *fd, int fd2);
void	child_proc(char **envp, char *cmd, int *fd, int fd1);
char	*ft_access(char *cmd, char **arpath);
void	ft_free_two(char **ar);
char	*ft_path(char **envp);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strstr(char *str, char *to_find);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	pipex(int fd1, int fd2, char **argv, char **envp);
void	ft_perror(void);

#endif
