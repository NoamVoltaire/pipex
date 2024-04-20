/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:21:58 by noam              #+#    #+#             */
/*   Updated: 2024/04/20 19:17:19 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void fork_process(t_pipex *pipex, char **envp)
{
	int pipefd[2];
	int pid;
	int dip;
	char str[1000];

	// printpipex(pipex);
	pipe(pipefd);
	pid = fork();
	if (pid < 0)
		return ;
	if (pid == 0)
	{
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		dup2(pipex->fds[0], 0);
		// close(pipefd[1]);
		execve(pipex->cmd[1][0], pipex->cmd[0], envp);
		exit(1);
	}
	waitpid(pid, NULL, 0);
	close(pipefd[1]);
	
	// printf("child 1 done\n");
	// printf("pipefd = %s\n", (read(pipefd[0], str, 1000) > 0) ? "yes" : "no");
	// printf("pipe = %s\n", str);
	// printf("cmds[2][1] = %s\n", pipex->cmd[2][1]);
		// close(pipex->fds[0]);
		
	dip = fork();
	if (dip < 0)
		return ;
	if (dip == 0)
	{
		// sleep(2);
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		dup2(pipex->fds[1], 1);
		// close(pipex->fds[0]);
		// close(pipex->fds[1]);
		// ft_printf_fd(0, "testout\n");
		execve(pipex->cmd[3][0], pipex->cmd[2], envp);
		exit(1);
	}
	waitpid(dip, NULL, 0);
	// close(pipex->fds[1]);
	// printf("child 2\n");
	// close(pipefd[1]);
	close(pipefd[0]);
}

void printpipex(t_pipex *pipex)
{
	int i = 0;
	printf("fd1 = %d\n", pipex->fds[0]);
	printf("fd2 = %d\n", pipex->fds[1]);
	while (i < 4)
	{
		if (pipex->cmd[i])
			printf("cmd[%d][0] = %s\n", i, pipex->cmd[i][0]);
		// printf("cmd[%d][1] = %s\n", i, pipex->cmd[i][1]);
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;
	// int pipefd[2];
	// int pid;
	// int dip;
	int i = 0;

	// while(envp[i])
	// {
	// 	printf("envp[%d] = %s\n", i, envp[i]);
	// 	i++;
	// }
	pipex = NULL;
	if (ac != 5)
	{
		// perror("Error");
		write(1, "\n", 1);
		return 0;
	}
	pipex = init_pipex(av, envp);

	fork_process(pipex, envp);
	// printf("len cmds = %d\n", len((void***)pipex->cmd));
if (pipex->cmd[3] == NULL)
	return (127);
// if (pipex->fds[0] == -1 || pipex->fds[1] == -1)
	// return 0;	// free(pipex);
	// printpipex(pipex);
	free_pipex(pipex);
	
	// ft_printf_fd(1, "\n");
}
/* ************************************************************************** */
/*							REFACTORING
** after testing with tester.pipex.sh, i found that the program faileds when
**
** 	the absolute path is written to the command. i will fix this by
**		- checking if the command is an absolute path before filling cmds
**		- check with access() if the command is executable

**	the cmd is a program in the curr dir. i will fix this by
**		- if argv[1] starts with "./" "
**		- checking if the command in curr dir (envp[0]+argv[1]) is executable

**	envp is NULL. i will fix this by
**		- checking before filling cmds if envp is NULL
**		- if NULL, i will fill cmds with the command only

**	--------------------------------------------------------------------
**	secondary error, returns
**
**		- if CMD NULL shouldn't write error

**	--------------------------------------------------------------------
** parsing
**
**	- init_pipex
**		- get fds
**		- check if ./ 
**		- else check if absolute path
**		- else if envp get cmd get path



*/
