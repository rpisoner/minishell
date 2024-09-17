/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:29:46 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/16 17:01:34 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
			mini.input.raw_info = input;
			if (!input)
			{
				free(input);
				clear_history();
				exit(0);
			}
			initialize_input(&mini);
			lexer(&mini);
			if (mini.cmd_num > 1)
				parse_commands(&mini);
			if (input && ft_strcmp(input, "env") == 0)
				get_env(&mini);
			if (input && *input)
				add_history(input);
			if (input && ft_strcmp(input, "exit") == 0)
			{
				free(input);
				free_stuff(&mini);
				clear_history();
				exit(0);
			}
			execute_commands(&mini);
			free (input);
			free_stuff(&mini);
		}
		clear_history();
		return (0);
	}
}
