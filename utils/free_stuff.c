/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:36:11 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/27 10:41:41 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_stuff(t_mini *mini)
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