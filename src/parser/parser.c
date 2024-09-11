/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:45:14 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/11 18:06:19 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	parse_commands(t_mini *mini)
{
	int	i;
	int	j;
	int k;
	int l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (mini->input.words[i])
	{
		// printf("input: [%s]\n", mini->input.words[i]);
		if (ft_strcmp(mini->input.words[i], "|"))
		{
			l = 0;
			mini->parsed[k]->cmd = (char **)malloc((i - j) * sizeof(char *));
			if (!mini->parsed[k]->cmd)
				malloc_error();
			while (j != i)
			{
				mini->parsed[k]->cmd[l] = mini->input.words[j];
				j++;
				l++;
			}
			k++;
			printf("j value: [%d]\n", j);
		}
		i++;
	}
	printf("Webo\n");
	printf("first parsed position: [%s]\n", mini->parsed[0]->cmd[0]);
}


