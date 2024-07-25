/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:29:46 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/25 11:10:16 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_exec	exec;

	exec.envp = envp;
	int		i;

	i = 0;
	(void)argv;
	if (argc == 1)
	{
		while (1)
		{
			input = readline("minishell>");
			if (input && ft_strcmp(input, "env") == 0)
				get_env(&exec);
			if (input && *input)
				add_history(input);
			if (input && ft_strcmp(input, "exit") == 0)
			{
				free(input);
				break ; 
			} 
		}
		clear_history();
		return (0);
	}
}
