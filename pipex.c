/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:55:47 by ntanjaou          #+#    #+#             */
/*   Updated: 2022/02/15 12:26:28 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	char	*path;
	int		fd[2];
	int		pid_1;
	int		pid_2;

	if (ac == 5)
	{
		path = get_path(envp);
		if (pipe(fd) < 0 || !path)
			exit(1);
		pid_1 = child_process_1(fd, path, av, envp);
		pid_2 = child_process_2(fd, path, av, envp);
		free(path);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid_1, NULL, 0);
		waitpid(pid_2, NULL, 0);
	}
	else
		write(1, "Argument's number is invalid !", 30);
	return (0);
}
