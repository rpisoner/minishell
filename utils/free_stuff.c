/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:36:11 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/02 17:43:24 by rpisoner         ###   ########.fr       */
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
		free(mini->parsed[i]->cmd);
		mini->parsed[i]->cmd = NULL;
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
	free_input_words(mini);
	if (mini->cmd_num != 1)
		free_parsed(mini);
}
