/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:15:45 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/22 12:34:29 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	check_expansion(t_mini *mini, char *expanded, int i)
{
	if (mini->expansion)
	{
		free(mini->input.words[i]);
		mini->input.words[i] = expanded;
		mini->expansion = 0;
	}
	else
		free(expanded);
}

void	process_expansion(t_mini *mini, char *var, char *expanded, int *j)
{
	char	*temp;
	int		start;

	start = *j;
	while (var[*j] && var[*j] != '$')
		(*j)++;
	if (start != *j)
	{
		temp = ft_strjoin(expanded, ft_substr(var, start, *j - start));
		free(expanded);
		expanded = temp;
	}
	if (var[*j] == '$')
	{
		mini->expansion = 1;
		temp = ft_strjoin(expanded, expand_single_var(mini, var, j));
		free(expanded);
		expanded = temp;
	}
}
