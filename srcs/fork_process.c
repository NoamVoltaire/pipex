/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:23:00 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/25 11:56:05 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*	************************************************************************* */

int	wait_process(int pid, int dip)
{
	int	status;
	int	exit_status;

	status = 0;
	exit_status = 0;
	waitpid(pid, NULL, 0);
	waitpid(dip, &status, 0);
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	return (exit_status);
}

/*	************************************************************************* */

void	process_it(t_pipex *pipex, int *pipefd, int is_first, char **envp)
{
	if (is_first)
	{
		if (pipex->fds[0] == -1)
			exit(1);
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		dup2(pipex->fds[0], 0);
		close(pipex->fds[0]);
		if (pipex->cmd[1])
			execve(pipex->cmd[1][0], pipex->cmd[0], envp);
	}
	else
	{
		if (pipex->fds[1] == -1)
			exit(1);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		dup2(pipex->fds[1], 1);
		close(pipex->fds[1]);
		if (pipex->cmd[3])
			execve(pipex->cmd[3][0], pipex->cmd[2], envp);
	}
	exit(0);
}

/*	************************************************************************* */

int	fork_process(t_pipex *pipex, char **envp)
{
	int	pipefd[2];
	int	pid;
	int	dip;

	pipe(pipefd);
	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
		process_it(pipex, pipefd, 1, envp);
	close(pipefd[1]);
	dip = fork();
	if (dip < 0)
		return (-1);
	if (dip == 0)
		process_it(pipex, pipefd, 0, envp);
	close(pipefd[0]);
	return (wait_process(pid, dip));
}
