/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_word_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:31:53 by rpisoner          #+#    #+#             */
/*   Updated: 2024/10/09 11:23:19 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	next_word_size(t_mini *mini, int i)
{
	int	aux;

	while (mini->input.raw_info[i] == ' ')
		i++;
	aux = i;
	while (mini->input.raw_info[aux])
	{
		if (mini->quoted == 0 && (mini->input.raw_info[aux] == '|'
				|| mini->input.raw_info[aux] == ' '
				|| mini->input.raw_info[aux] == '>'
				|| mini->input.raw_info[aux] == '<'))
		{
			return ((mini->input.raw_info + aux)
				- ((mini->input.raw_info + i)));
		}
		aux++;
	}
	return ((mini->input.raw_info + aux) - ((mini->input.raw_info + i)));
}
