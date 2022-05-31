/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:04:30 by ntanjaou          #+#    #+#             */
/*   Updated: 2022/02/13 17:20:33 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_is_erreur(char **mycmd, char **mypath)
{
	write(2, "command not found : ", 20);
	if (*mycmd)
		write(2, *mycmd, ft_strlen(*mycmd));
	write(2, "\n", 1);
	if (mypath[0])
		ft_free(mypath, NULL);
	ft_free(mycmd, NULL);
}

char	*get_path(char **envp)
{
	char	*path;
	int		i;
	int		len;

	if (!envp[0])
		return (NULL);
	len = ft_strlen("PATH=");
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], len - 1) == 0)
		{
			path = ft_substr(envp[i], len, ft_strlen(envp[i]) - len);
			return (path);
		}
		i++;
	}
	return (0);
}

char	*ft_strconcatinate(char const *s1, char const *s2, char const *s3)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s3)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	i = 0;
	while (s3[i])
		str[j++] = s3[i++];
	str[j] = '\0';
	return (str);
}

void	ft_free(char **tab, char *cmd)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	free(cmd);
}

char	*get_cmd(char *path, char **av, int i)
{
	char	**mypaths;
	char	**mycmd;
	char	*cmd;

	mypaths = ft_split(path, ':');
	mycmd = ft_split(*av, ' ');
	if (access(mycmd[0], X_OK) == 0)
		return (mycmd[0]);
	else
	{	
		while (mypaths[++i])
		{
			cmd = ft_strconcatinate(mypaths[i], "/", mycmd[0]);
			if (access(cmd, X_OK) == 0)
			{
				ft_free(mypaths, NULL);
				ft_free(mycmd, NULL);
				return (cmd);
			}
			free(cmd);
		}
	}
	ft_is_erreur(mycmd, mypaths);
	return (NULL);
}
