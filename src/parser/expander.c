/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:55:52 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/15 19:04:33 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	expander(t_mini *mini, int *i)
{
	int	index;

	if (mini->input.words[*i] == '$' && mini->input.words[*i + 1])
		(*i)++;
	index = *i;
	if (mini->quoted == 0 || mini->double_quote)
	{
		printf("%s\n", mini->envp[search_var(mini, i)]);
	}
}

int	search_var(t_mini *mini, int *i)
{
	while (mini->envp[*i])
	
}