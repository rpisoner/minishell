/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:37 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/08 11:38:44 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	do_export(t_mini *mini, int i)
{
	int		len;
	char	**new_env;
	int		j;

	len = 0;
	while (mini->envp[len])
		len++;
	new_env = (char **)malloc(sizeof(char *) * (len + 2));
	j = -1;
	while (mini->envp[++j])
		new_env[j] = ft_strdup(mini->envp[j]);
	new_env[len] = ft_strdup(mini->input.words[i + 1]);
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