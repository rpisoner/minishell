/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_word_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:31:53 by rpisoner          #+#    #+#             */
/*   Updated: 2024/10/02 17:37:23 by rpisoner         ###   ########.fr       */
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
			// write_word(mini->input.raw_info, i, aux - i);
			// printf("1.LEN: [%ld]\n", (mini->input.raw_info + aux) - ((mini->input.raw_info + i)));
			return ((mini->input.raw_info + aux)
				- ((mini->input.raw_info + i)));
		}
		aux++;
	}
	// write_word(mini->input.raw_info, i, aux - i);
	// printf("3.LEN: [%ld]\n", (mini->input.raw_info + aux) - ((mini->input.raw_info + i)));
	return ((mini->input.raw_info + aux) - ((mini->input.raw_info + i)));
}
