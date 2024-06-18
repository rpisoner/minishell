/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:00:46 by jolivare          #+#    #+#             */
/*   Updated: 2024/06/18 15:44:39 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int main() {
	char *input;
	while (1) {
		input = readline("minishell> ");
		if (input && *input) {
			add_history(input);
		}
		if (input && ft_strcmp(input, "exit") == 0) {
			free(input);
			break;
		}
		if (input) {
			printf("Has ingresado: %s\n", input);
			free(input);
		}
	}
	clear_history();
	return 0;
}

