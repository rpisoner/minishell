/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isspace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:40:52 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/08 18:05:40 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_isspace(char c)
{
	if (c && (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r'))
		return (1);
	return (0);
}

void	create_new_command_node(t_mini *mini)
{
	t_command *new_node = (t_command *)malloc(sizeof(t_command));
	t_command *current_node;
	if (!new_node)
		malloc_error();
	new_node->words = NULL;
	new_node->next = NULL;

	if (!mini->input.commands)
		mini->input.commands = new_node;
	else
	{
		current_node = mini->input.commands;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}
}
