/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:57:29 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/24 13:39:46 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	reassign_words(char **str)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (str[i])
	{
		str[j] = str[i];
		str[j + 1] = NULL;
		i++;
		j++;
	}
}

void	emulate_here_doc(t_mini *mini, char *limiter)
{
	char	*text;
	char	*complete_limiter;

	mini->input.aux_fd = open("here_doc", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (mini->input.aux_fd < 0)
		exit (1);
	complete_limiter = ft_strjoin(limiter, "\n");
	while (1)
	{
		text = get_next_line(0);
		if (text == NULL)
			break;
		if (!ft_strcmp(complete_limiter, text))
			break ;
		write(mini->input.aux_fd, text, ft_strlen(text));
		free (text);
	}
	if (text)
		free (text);
	close (mini->input.aux_fd);
	free(complete_limiter);
	mini->input.infile = open("here_doc", O_RDONLY);
	if (mini->input.infile < 0)
		exit (1);
}

void	manage_single_redir(t_mini *mini)
{
	int	i;

	i = -1;
	mini->input.infile = -1;
	mini->input.outfile = -1;
	while (mini->input.words[++i])
	{
		manage_in_redir(mini, i);
		manage_out_redir(mini, i);
	}
}

void	manage_redir(t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	while (mini->parsed[i])
	{
		j = 0;
		while (mini->parsed[i]->cmd[j])
		{
			if (ft_strcmp(mini->input.words[i], "<") == 0)
			{
				mini->input.infile = open(mini->parsed[i]->cmd[j + 1], O_RDONLY);
				reassign_words(mini->parsed[i]->cmd);
			}
			else if (ft_strcmp(mini->input.words[i], "<<") == 0)
			{
				mini->here_doc = 1;
				emulate_here_doc(mini, mini->parsed[i]->cmd[j + 1]);
				reassign_words(mini->parsed[i]->cmd);
				//print_stuff(mini->parsed[i]->cmd[j]);
			}
			if (ft_strcmp(mini->parsed[i]->cmd[j], ">") == 0)
			{
				mini->parsed[i]->outfile = open(mini->parsed[i]->cmd[j + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
				mini->parsed[i]->cmd[j] = NULL;
			}
			else if (ft_strcmp(mini->parsed[i]->cmd[j], ">>") == 0)
			{
				mini->parsed[i]->outfile = open(mini->parsed[i]->cmd[j + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
				mini->parsed[i]->cmd[j] = NULL;
			}
			j++;
		}
		i++;
	}
}
