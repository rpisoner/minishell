/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:36:11 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/25 17:50:48 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_parsed(t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	while (mini->parsed[i] != NULL)
	{
		j = 0;
		while (mini->parsed[i]->cmd[j] != NULL)
		{
			if (mini->parsed[i]->cmd[j])
			{
				free(mini->parsed[i]->cmd[j]);
				mini->parsed[i]->cmd[j] = NULL;
			}
			j++;
		}
		free(mini->parsed[i]);
		mini->parsed[i] = NULL;
		i++;
	}
	free(mini->parsed);
	mini->parsed = NULL;
}

void	free_input_words(t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->input.words[i] != NULL)
	{
		free(mini->input.words[i]);
		i++;
	}
	free(mini->input.words);
}

void	free_stuff(t_mini *mini)
{
	if (mini->cmd_num != 1)
		free_parsed(mini);
	else
		free_input_words(mini);
}
