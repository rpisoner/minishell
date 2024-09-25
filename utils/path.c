/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:34:12 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/25 12:02:56 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	free_path(char **paths)
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

static char	**get_path(t_mini *mini)
{
	int		i;
	char	**paths;

	i = 0;
	while (mini->envp[i])
	{
		if (ft_strncmp(mini->envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(&mini->envp[i][5], ':');
			return (paths);
		}
		i++;
	}
	return (NULL);
}

static int	check_path(char *paths, t_mini *mini, int i)
{
	char	*join;
	char	*command;

	join = ft_strjoin(paths, "/");
	command = ft_strjoin(join, mini->parsed[i]->cmd[0]);
	free(join);
	if (access (command, X_OK) == 0)
	{
		mini->cmd_path = command;
		return (0);
	}
	free(command);
	return (1);
}

int	get_values(t_mini *mini, int index)
{
	int		i;
	char	**paths;

	i = 0;
	if (ft_strchr(mini->parsed[i]->cmd[0], '/') != NULL)
	{
		mini->cmd_path = mini->parsed[i]->cmd[0];
		return (0);
	}
	paths = get_path(mini);
	if (!paths)
		return (1);
	while (paths[i])
	{
		if (check_path(paths[i], mini, index) == 0)
		{
			free_path(paths);
			return (0);
		}
		i++;
	}
	free_path(paths);
	return (1);
}