/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:44:18 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/03 11:47:48 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	*free_env(char **envp, int max)
{
	int	i;

	i = 0;
	if (max < 0)
	{
		while (envp && envp[i])
			free(envp[i++]);
	}
	else
	{
		while (i < max)
			free(envp[i++]);
	}
	free(envp);
	return (NULL);
}

char	**copy_envp(char **envp)
{
	int		len;
	char	**env_cpy;

	len = 0;
	while (envp[len] && envp[len])
		len++;
	env_cpy = ft_calloc((len + 1), sizeof(char *));
	if (!env_cpy)
		malloc_error();
	len = -1;
	while (envp && envp[++len])
	{
		env_cpy[len] = ft_strdup(envp[len]);
		if (!env_cpy[len])
		{
			free_env(env_cpy, len);
			return (NULL);
		}
	}
	return (env_cpy);
}

int	search_on_env(char **envp, char *var)
{
	int		i;
	char	*complete;

	i = 0;
	complete = ft_strjoin(var, "=");
	if (!complete)
		malloc_error();
	while (envp && envp[i])
	{
		if (!ft_strncmp(envp[i], complete, ft_strlen(complete)))
		{
			free(complete);
			return (i);
		}
		i++;
	}
	free(complete);
	return (-1);
}

char	**modify_shlvl(char **envp)
{
	int		i;
	int		num;
	char	*aux;
	char	*shlvl;

	i = search_on_env(envp, "SHLVL");
	if (i == -1)
	{
		shlvl = ft_strjoin("SHLVL=", "1");
		if (!shlvl)
			malloc_error();
		return (insert_into_env(envp, shlvl));
	}
	num = ft_atoi(&envp[i][6]);
	free(envp[i]);
	num += 1;
	aux = ft_itoa(num);
	if (!aux)
		malloc_error();
	envp[i] = ft_strjoin("SHLVL=", aux);
	if (!envp[i])
		malloc_error();
	free (aux);
	return (envp);
}

char	**insert_into_env(char **envp, char *insert)
{
	int		len;
	char	**new_env;

	len = 0;
	while (envp && envp[len])
		len++;
	new_env = ft_calloc((len + 2), sizeof(char *));
	if (!new_env)
		malloc_error();
	len = -1;
	while (envp && envp[++len])
		new_env[len] = envp[len];
	new_env[len] = insert;
	return (new_env);
}
