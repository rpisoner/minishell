/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:57:29 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/11 14:39:04 by jolivare         ###   ########.fr       */
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
			break ;
		if (ft_strcmp(complete_limiter, text) == 0)
			break ;
		write(mini->input.aux_fd, text, ft_strlen(text));
		free (text);
	}
	if (text)
		free (text);
	close (mini->input.aux_fd);
	free(complete_limiter);
}

void	manage_single_redir(t_mini *mini)
{
	int	i;

	i = -1;
	mini->input.infile = mini->my_stdin;
	mini->input.outfile = mini->my_stdout;
	while (mini->input.words[++i])
	{
		manage_in_redir(mini, i);
		manage_out_redir(mini, i);
	}
}

void	manage_redir(t_mini *mini, int i)
{
	int	j;

	j = -1;
	mini->parsed[i]->infile = -1;
	mini->parsed[i]->outfile = -1;
	while (mini->parsed[i]->cmd[++j])
	{
		manage_pipe_in(mini, i, j);
		manage_pipe_out(mini, i, j);
	}
}
