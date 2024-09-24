/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:36:11 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/24 13:01:07 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_parsed(t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	while (mini->parsed[i])
	{
		j = 0;
		while (mini->parsed[i]->cmd[j])
		{
			free(mini->parsed[i]->cmd[j]);
			//mini->parsed[i]->cmd[j] = NULL;
			j++;
		}
		free(mini->parsed[i]);
		i++;
	}
	free(mini->parsed);
}

void	free_input_words(t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->input.words[i])
	{
		free(mini->input.words[i]);
		i++;
	}
	free(mini->input.words);
}

void	free_stuff(t_mini *mini)
{
	//free_parsed(mini);
	free_input_words(mini);
}
