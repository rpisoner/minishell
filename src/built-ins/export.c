/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:37 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/11 12:20:17 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_existing(t_mini *mini, char *str)
{
	int		i;
	char	*aux;

	i = -1;
	(void)mini;
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
	free_strs(new_env);
}
