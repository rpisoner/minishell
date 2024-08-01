/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:29:46 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/01 10:54:04 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_mini	mini;
	int		i;

	i = 0;
	(void)argv ;
	initialize_envp(envp, &mini);
	if (argc == 1)
	{
		while (1)
		{
			input = readline("minishell>");
			// while (input[i] != '\"')
			// 	i++;
			// if (input[i] == '\"')
			// {
			// 	i++;
			// 	ft_substr(input, i, )
			// }
			divide_commands(input);
			if (input && ft_strcmp(input, "env") == 0)
				get_env(&mini);
			if (input && *input)
				add_history(input);
			if (input && ft_strcmp(input, "exit") == 0)
			{
				free(input);
				break ; 
			}
			free (input);
		}
		clear_history();
		return (0);
	}
}
