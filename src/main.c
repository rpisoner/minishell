/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:29:46 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/08 18:23:55 by jolivare         ###   ########.fr       */
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
			//	free(input);
			//	free_stuff(&mini);
				clear_history();
				exit(0);
			}
			divide_commands(&mini);
			printf("Hola1\n");
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
			printf("Hola2\n");
			//execute_commands(&mini);
			free (input);
			free_stuff(&mini);
		}
		clear_history();
		return (0);
	}
}
