/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:26:36 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/29 16:38:34 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_delimiter(char c)
{
	return (ft_isspace(c));
}

void	divide_commands(char *input)
{
	char	*word;
	int		i;
	int		j;
	int		len;

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
			if (j == 0)
			{
				len = ft_strlen(input + i);
				word = (char *)malloc(sizeof(char) * (len + 1));
				if (!word)
				{
					printf("Error en malloc\n");
					exit (1);
				}
			}
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
