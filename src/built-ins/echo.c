/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:46:41 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/16 11:00:45 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	manage_echo_status(t_mini *mini, char	**str, int i)
{
	if (mini->meta_char && ft_strcmp(str[i], "?") == 0)
	{
		if (str[i + 1] != NULL)
			return (1);
		else if (!str[i + 1])
			return (2);
	}
	return (0);
}

static int	manage_echo_new_line(t_mini *mini, char	**str, int i)
{
	int	j;

	j = 0;
	if (ft_strcmp(str[i], "-n") == 0)
	{
		mini->line = 1;
		if (str[i + 1] != NULL)
			return (1);
		return (2);
	}
	if (str[i][j] == '-' && str[i][j + 1] == 'n' && str[i][j + 2] == 'n')
	{
		mini->line = 1;
		if (str[i + 1] != NULL)
			return (3);
		return (4);
	}
	return (0);
}

static void	print_new_line(t_mini *mini)
{
	if (!mini->line)
		printf("\n");
	mini->line = 0;
}

static int	manage_line_flag(t_mini *mini, char **str, int *i)
{
	if (manage_echo_new_line(mini, str, *i) == 1)
	{
		while (ft_strcmp(str[(*i)], "-n") == 0)
			(*i)++;
	}
	else if (manage_echo_new_line(mini, str, *i) == 2)
		return (1);
	else if (manage_echo_new_line(mini, str, *i) == 3)
		(*i)++;
	else if(manage_echo_new_line(mini, str, *i) == 4)
		return (2);
	return (0);
}

void	do_echo(t_mini *mini, char	**str, int i)
{
	while (mini->input.words[++i])
	{
		if (manage_line_flag(mini, str, &i) == 1 || manage_line_flag(mini, str, &i) == 2)
			return ;
		if (manage_echo_status(mini, str, i) == 1)
		{
			printf("%d ", mini->status);
			i++;
		}
		else if (manage_echo_status(mini, str, i) == 2)
		{
			printf("%d\n", mini->status);
			return ;
		}
		if (str[i + 1] == NULL)
			break ;
		printf("%s ", str[i]);
	}
	printf("%s", str[i]);
	print_new_line(mini);
}
