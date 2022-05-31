/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:42:35 by ntanjaou          #+#    #+#             */
/*   Updated: 2022/02/13 17:21:43 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/errno.h>
# include <stdlib.h>
# include <stdio.h>

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_path(char **envp);
char	*ft_strdup(const char *src);
char	*ft_strconcatinate(char const *s1, char const *s2, char const *s3);
char	*get_cmd(char *path, char **av, int i);
int		child_process_1(int fd[2], char *path, char **av, char **env);
int		child_process_2(int fd[2], char *path, char **av, char **env);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_free(char **tab, char *cmd);
void	ft_is_erreur(char **mycmd, char **mypath);
void	ft_erreur_file(char *file);
size_t	ft_strlen(const char *s);

#endif