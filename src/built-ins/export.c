/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:37 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/19 13:05:42 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_ordered_env(char **aux_env)
{
	int	i;

	i = -1;
	while (aux_env[++i])
		printf("declare -x %s\n", aux_env[i]);
}

static void	swap_content(char **aux_env, int pos1, int pos2)
{
	char	*aux_slot;

	if (aux_env[pos2] && ft_strcmp(aux_env[pos1], aux_env[pos2]) > 0)
	{
		aux_slot = aux_env[pos1];
		aux_env[pos1] = aux_env[pos2];
		aux_env[pos2] = aux_slot;
	}
}

void	print_alphabetically(t_mini *mini)
{
	int		i;
	int		j;
	int		size;
	char	**aux_env;

	size = 0;
	while (mini->envp[size])
		size++;
	aux_env = (char **)malloc(sizeof(char *) * (size + 1));
	if (!aux_env)
		malloc_error();
	i = -1;
	while (mini->envp[++i])
		aux_env[i] = ft_strdup(mini->envp[i]);
	aux_env[i] = NULL;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1)
			swap_content(aux_env, j, j + 1);
	}
	i = -1;
	print_ordered_env(aux_env);
	free_strs(aux_env);
}

int	check_existing(t_mini *mini, char *str)
{
	int		i;
	char	*aux;

	i = 0;
	(void)mini;
	if (!str)
	{
		print_alphabetically(mini);
		return (1);
	}
	while (str[i] != '=')
		i++;
	aux = ft_substr(str, 0, i);
	i = search_env_var(mini, aux);
	free(aux);
	if (i != -1)
	{
		free(mini->envp[i]);
		mini->envp[i] = ft_strdup(str);
		return (1);
	}
	return (0);
}

void	do_export(t_mini *mini, char **str, int i)
{
	int		len;
	char	**new_env;
	int		j;

	len = 0;
	if (check_existing(mini, str[i + 1]) == 1)
		return ;
	while (mini->envp[len])
		len++;
	new_env = (char **)malloc(sizeof(char *) * (len + 2));
	j = -1;
	while (mini->envp[++j])
		new_env[j] = ft_strdup(mini->envp[j]);
	new_env[len] = ft_strdup(str[i + 1]);
	new_env[len + 1] = NULL;
	j = -1;
	while (mini->envp[++j])
		free(mini->envp[j]);
	free(mini->envp);
	mini->envp = (char **)malloc(sizeof(char *) * (len + 2));
	j = -1;
	while (new_env[++j])
		mini->envp[j] = ft_strdup(new_env[j]);
	mini->envp[j] = NULL;
	free_strs(new_env);
}
