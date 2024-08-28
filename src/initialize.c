/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:37:39 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/28 11:16:51 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	initialize_data(t_mini *mini, char **envp)
{
	mini->envp = envp;
	mini->path = search_path(envp);
	mini->quoted = 0;
	mini->expanded = 0;
	mini->t_quote = '\0';
	mini->pipex = NULL;
}
