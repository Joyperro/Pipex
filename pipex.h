/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:21:01 by dclement          #+#    #+#             */
/*   Updated: 2024/09/23 12:55:39 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../libft/libft.h"

void	error();
int		check(char **envp, char **argv);
char	*free_paths(char **paths);
char	*pathfinder(char *cmd, char **envp, char **argv);
void	execmds(char *cmd, char **envp, char **argv);

#endif