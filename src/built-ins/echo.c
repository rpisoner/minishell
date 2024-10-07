/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:46:41 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/07 13:04:53 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	print_next_chars(t_mini *mini, int i, int j)
{
	while (mini->input.words[i][j])
	{
		printf("%c", mini->input.words[i][j]);
		j++;
	}
	printf("\n");
}

// void	manage_n_flag(t_mini *mini, int i)
// {
	
// }

void	do_echo(t_mini *mini, int i)
{
	int	j;

	j = 0;
	if (mini->meta_char == 1 && mini->input.words[i + 1][0] == '?')
	{
		printf("%d", mini->status);
		if (mini->input.words[i][j + 1])
			print_next_chars(mini, i + 1, j + 1);
		return ;
	}
	else
	{
		j = 5;
		while (mini->input.raw_info[j])
		{
			printf("%c", mini->input.raw_info[j]);
			j++;
		}
		printf("\n");
	}
	mini->meta_char = 0;
}

