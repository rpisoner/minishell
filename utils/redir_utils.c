/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:15:41 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/26 10:16:19 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/minishell.h"

void	manage_in_redir(t_mini *mini, int i)
{
	if (ft_strcmp(mini->input.words[i], "<") == 0)
	{
		mini->input.infile = open(mini->input.words[i + 1], O_RDONLY);
		reassign_words(mini->input.words);
	}
	else if (ft_strcmp(mini->input.words[i], "<<") == 0)
	{
		mini->here_doc = 1;
		mini->input.infile = open("here_doc", O_RDONLY);
		emulate_here_doc(mini, mini->input.words[i + 1]);
		reassign_words(mini->input.words);
	}
}

void	manage_out_redir(t_mini *mini, int i)
{
	if (ft_strcmp(mini->input.words[i], ">") == 0)
	{
		mini->input.outfile = open(mini->input.words[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		mini->input.words[i] = NULL;
	}
	else if (ft_strcmp(mini->input.words[i], ">>") == 0)
	{
		mini->input.outfile = open(mini->input.words[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		mini->input.words[i] = NULL;
	}
}
