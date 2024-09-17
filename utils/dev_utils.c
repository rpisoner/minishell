/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:29:46 by rpisoner          #+#    #+#             */
/*   Updated: 2024/09/17 11:51:33 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_stuff(char **stuff)
{
	size_t	i;

	i = 0;
	while (stuff[i])
	{
		printf("Words[%ld]: %s\n", i, stuff[i]);
		i++;
	}
	printf("Words[%ld]: %s\n", i, stuff[i]);
}

void	print_parsed_cmd(t_mini *mini)
{
	int	i;
	int	j;

	i = -1;
	while (mini->parsed[++i])
	{
		j = 0;
		while (mini->parsed[i]->cmd[j])
		{
			printf("Parsed[%d]->", i);
			printf("cmd[%d]: [%s]\n", j, mini->parsed[i]->cmd[j]);
			j++;
		}
		printf("\n");
	}
}
