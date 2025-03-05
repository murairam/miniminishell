/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:31:37 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/03/01 16:35:07 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_if_other_heredoc(t_token *current)
{
	t_token	*tmp;

	tmp = current->next;
	while (tmp)
	{
		if (tmp->type == T_REDIR_HERE)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	save_heredoc_line(int fd, char *tmp, t_data *data,
		int quotes_status)
{
	if (quotes_status == 0)
		tmp = expanding(tmp, data);
	if (tmp)
		write(fd, tmp, ft_strlen(tmp));
	write(fd, "\n", 1);
	if (tmp)
		free(tmp);
}

void	pipe_and_fork(t_cmd *current, t_data *data)
{
	if (current->next)
	{
		if (pipe(data->pipe_fd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
	}
	data->prev_pid = fork();
	if (data->prev_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}

void	wait_commands(t_data *data)
{
	signal(SIGINT, SIG_IGN);
	while (errno != ECHILD)
	{
		if (wait(&data->wstatus) == data->prev_pid)
		{
			if (WIFEXITED(data->wstatus))
				data->exit_status = WEXITSTATUS(data->wstatus);
			else
			{
				data->exit_status = 128 + WTERMSIG(data->wstatus);
				if (data->exit_status == 131)
					ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO);
				else if (data->exit_status == 139)
					ft_putstr_fd("Segmentation fault (core dumped)\n",
						STDERR_FILENO);
			}
			if (data->exit_status == 130)
				ft_putstr_fd("\n", STDERR_FILENO);
		}
	}
	if (g_received_signal == SIGINT)
		data->exit_status = 130;
}
