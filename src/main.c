/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:29:46 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/04 18:51:40 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_valid_input(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_mini	mini;

	(void)argv;
	initialize_data(&mini, envp);
	signals();
	if (argc == 1)
	{
		while (1)
		{
			input = readline("minishell>");
			if (!input)
			{
				free(input);
				clear_history();
				exit(0);
			}
			if (check_valid_input(input) == 1)
				continue ;
			mini.input.raw_info = input;
			initialize_input(&mini);
			lexer(&mini);
			if (input && *input)
				add_history(input);
			if (mini.cmd_num > 1)
				parse_commands(&mini);
			execute_commands(&mini);
			free (input);
			free_stuff(&mini);
		}
		clear_history();
		return (0);
	}
}
