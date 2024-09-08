/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:36:11 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/08 18:17:04 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_stuff(t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->input.commands->words[i])
	{
		free(mini->input.commands->words[i]);
		i++;
	}
	free(mini->input.commands->words);
}