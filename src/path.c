/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:39:46 by rpisoner          #+#    #+#             */
/*   Updated: 2024/08/15 12:09:15 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**search_path(char **envp)
{
	char	**path;
	size_t	i;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path = ft_split(envp[i] + 5, ':');
		i++;
	}
	return (path);
}
/*
void	set_command_free(t_mini *mini, char *cmd, char *command_path, int j)
{
	mini->commands_paths[j] = ft_strdup(cmd);
	free(command_path);
}

void	command_path(t_mini *mini, char *command, int j)
{
	size_t	i;
	char	*slash_join;
	char	**command_and_flags;
	char	*command_path;

	i = 0;
	command_and_flags = ft_split(command, ' ');
	slash_join = ft_strjoin(mini->path[i], "/");
	command_path = ft_strjoin(slash_join, command_and_flags[0]);
	free(slash_join);
	while (mini->path[i] != NULL && access(command_path, X_OK) != 0)
	{
		i++;
		free(command_path);
		slash_join = ft_strjoin(mini->path[i], "/");
		command_path = ft_strjoin(slash_join, command_and_flags[0]);
		free(slash_join);
	}
	if (ft_strchr(command, '/') != 0)
		set_command_free(mini, command, command_path, j);
}
*/