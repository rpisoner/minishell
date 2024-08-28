/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:56:09 by rpisoner          #+#    #+#             */
/*   Updated: 2024/08/27 16:57:04 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	quote_check(t_mini *mini, int i)
{
	if (mini->input.raw_info[i] == '\''
		|| mini->input.raw_info[i] == '\"')
	{
		if (mini->quoted == 0)
		{
			mini->quoted = 1;
			mini->t_quote = mini->input.raw_info[i];
		}
		else if (mini->input.raw_info[i] == mini->t_quote)
			mini->quoted = 0;
	}
}
