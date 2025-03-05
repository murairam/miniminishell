/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:22:04 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/03/01 19:03:09 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_all_and_exit(t_data *data, int exit_code)
{
	if (data)
	{
		ft_free_all(data);
		if (data->env)
			ft_free_env((data->env));
		close_fds(data);
	}
	rl_clear_history();
	exit(exit_code);
}

void	ft_free_all(t_data *data)
{
	if (data)
	{
		if (data->heredoc)
		{
			free(data->heredoc);
			data->heredoc = NULL;
		}
		if (data->tokens)
			free_tokens(&(data->tokens));
		if (data->commands)
			ft_free_cmds(&(data->commands));
	}
}

void	free_tokens(t_token **tokens)
{
	t_token	*temp;
	t_token	*current;

	if (!*tokens)
		return ;
	current = *tokens;
	while (current)
	{
		temp = current->next;
		if (current->value)
			free(current->value);
		free(current);
		current = temp;
	}
	*tokens = NULL;
}

void	ft_free_cmds(t_cmd **commands)
{
	t_cmd	*temp;
	t_cmd	*current;

	if (!*commands)
		return ;
	current = *commands;
	while (current)
	{
		temp = current->next;
		if (current->cmd_args)
			ft_free_tab(current->cmd_args);
		free_tokens(&(current->redirs));
		free(current);
		current = temp;
	}
	*commands = NULL;
}
