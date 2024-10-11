/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:48 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/11 10:49:06 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	search_env_var(t_mini *mini, char *var)
{
	int		i;
	char	*complete;

	i = 0;
	complete = ft_strjoin(var, "=");
	if (!complete)
		malloc_error();
	while (mini->envp && mini->envp[i])
	{
		if (ft_strncmp(mini->envp[i], complete, ft_strlen(complete)) == 0)
		{
			free(complete);
			return (i);
		}
		i++;
	}
	return (-1);
}

void	rearrange_env(t_mini *mini, char *var)
{
	int	pos;

	pos = search_env_var(mini, var);
	if (pos == -1)
		return ;
	if (mini->envp[pos] == NULL)
		return ;
	free(mini->envp[pos]);
	while (mini->envp[pos] != NULL)
	{
		mini->envp[pos] = mini->envp[pos + 1];
		pos++;
	}
}

void	do_unset(t_mini *mini, char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], "unset") == 0)
			rearrange_env(mini, str[i + 1]);
		i++;
	}
}
