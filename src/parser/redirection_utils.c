/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:57:08 by rpisoner          #+#    #+#             */
/*   Updated: 2024/10/09 11:27:58 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	copy_redirs(t_mini *mini, char *token, int i)
{
	int	j;

	j = 0;
	while (mini->input.raw_info[i]
		&& (mini->input.raw_info[i] == '>'
			|| mini->input.raw_info[i] == '<'))
	{
		token[j] = mini->input.raw_info[i];
		i++;
		j++;
	}
	token[j] = '\0';
}
