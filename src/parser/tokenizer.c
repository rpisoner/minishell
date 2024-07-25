/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:26:36 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/25 17:03:53 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_delimiter(char c)
{
	return (ft_isspace(c));
}

void	divide_commands(char *input)
{
	char	word[100];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(input[i] != '\0')
	{
		if (is_delimiter(input[i]))
		{
			if (j > 0)
			{
				word[j] = '\0';
				printf("Word found: %s\n", word);
				j = 0;
			}	
		}
		else
		{
			word[j++] = input[i];
		}
		i++;
	}
	if (j > 0)
	{
		word[j] = '\0';
		printf("Word found: %s\n", word);
	}
}