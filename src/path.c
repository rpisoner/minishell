/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:39:46 by rpisoner          #+#    #+#             */
/*   Updated: 2024/09/08 18:16:06 by jolivare         ###   ########.fr       */
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

void	f_path(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

int	test_path(char *paths, t_mini *mini)
{
	char	*join;
	char	*command;

	join = ft_strjoin(paths, "/");
	command = ft_strjoin(join, mini->input.commands->words[0]);
	free(join);
	if (access (command, X_OK) == 0)
	{
		mini->pipex->path = command;
		return (0);
	}
	free(command);
	return (1);
}

int	get_cmd_path(t_mini *mini)
{
	int		i;
	char	**paths;

	i = 0;
	if (ft_strchr(mini->input.commands->words[0], '/') != NULL)
	{
		mini->pipex->path = mini->input.commands->words[0];
		return (0);
	}
	paths = search_path(mini->envp);
	if (!paths)
		return (1);
	while (paths[i])
	{
		if (test_path(paths[i], mini) == 0)
		{
			f_path(paths);
			return (0);
		}
		i++;
	}
	f_path(paths);
	return (1);
}
