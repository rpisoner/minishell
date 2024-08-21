/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:15:45 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/21 13:18:37 by jolivare         ###   ########.fr       */
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