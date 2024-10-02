/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:29:46 by rpisoner          #+#    #+#             */
/*   Updated: 2024/10/02 17:12:22 by rpisoner         ###   ########.fr       */
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
		while (mini->parsed[i]->cmd[j] != NULL)
		{
			printf("Parsed[%d]->", i);
			if (mini->parsed[i]->cmd[j] != NULL)
				printf("cmd[%d]: [%s]\n", j, mini->parsed[i]->cmd[j]);
			j++;
		}
		printf("Parsed[%d]->", i);
		printf("cmd[%d]: [(null)]\n", j);
		printf("\n");
	}
}

void	write_word(char *word, int init, int len)
{
	int	i;

	i = 0;
	write(1, "Palabra [", 9);
	while (i < len)
	{
		write(1, &word[init], 1);
		i++;
		init++;
	}
	write(1, "], ", 3);
}
