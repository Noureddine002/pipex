/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:25:19 by ntanjaou          #+#    #+#             */
/*   Updated: 2022/02/13 17:03:50 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_erreur_file(char *file)
{
	write(1, strerror(errno), 25);
	write(1, ": ", 2);
	write(1, file, ft_strlen(file));
	write(1, "\n", 1);
	exit(0);
}

int	child_process_1(int fd[2], char *path, char **av, char **env)
{
	char	*get_cmd_path;
	char	**cmd_arg;
	int		pid_1;
	int		fd_id;

	get_cmd_path = get_cmd(path, &av[2], -1);
	cmd_arg = ft_split(av[2], ' ');
	pid_1 = fork();
	if (pid_1 == -1)
		strerror(pid_1);
	if (pid_1 == 0)
	{
		fd_id = open(av[1], O_RDWR, 0777);
		if (fd_id < 0)
			ft_erreur_file(av[1]);
		dup2(fd_id, 0);
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		close(fd_id);
		execve(get_cmd_path, cmd_arg, env);
		exit(1);
	}
	ft_free(cmd_arg, get_cmd_path);
	return (pid_1);
}

int	child_process_2(int fd[2], char *path, char **av, char **env)
{
	char	*get_cmd_path;
	char	**cmd_arg;
	int		pid_2;
	int		fd_id;

	get_cmd_path = get_cmd(path, &av[3], -1);
	cmd_arg = ft_split(av[3], ' ');
	pid_2 = fork();
	if (pid_2 == -1)
		strerror(pid_2);
	if (pid_2 == 0)
	{
		fd_id = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (fd_id < 0)
			ft_erreur_file(av[4]);
		dup2(fd_id, 1);
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd_id);
		execve(get_cmd_path, cmd_arg, env);
		exit(1);
	}
	ft_free(cmd_arg, get_cmd_path);
	return (pid_2);
}
