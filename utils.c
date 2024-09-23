/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:20:58 by dclement          #+#    #+#             */
/*   Updated: 2024/09/23 12:55:36 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error()
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	check(char **envp, char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (ft_strncmp(argv[i], "env -i", 6) == 0)
			return (-1);
		i++;
	}
	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	return (i);
}

char	*free_paths(char **paths)
{
	int i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (NULL);
}

char 	*pathfinder(char *cmd, char **envp, char **argv)
{
	char 	**paths;
	char 	*path;
	char 	*tmp;
	int 	i;

	i = check(envp, argv);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		error();
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			error();
		path = ft_strjoin(tmp, cmd);
		if (!path)
			error();
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (free_paths(paths));
}

void	execmds(char *cmd, char **envp, char **argv)
{
	char	**cmds;
	char	*path;
	int		i;

	i = 0;
	cmds = ft_split(cmd, ' ');
	if (cmds == NULL)
		error();
	path = pathfinder(cmds[0], envp, argv);
	if (!path)
	{
		while (cmds[i])
			free(cmds[i++]);
		free(cmds);
		error();
	}
	if (execve(path, cmds, envp) == -1)
		error();
}
