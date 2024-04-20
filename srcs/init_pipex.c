/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:23:33 by noam              #+#    #+#             */
/*   Updated: 2024/04/19 14:12:08 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* ************************************************************************** */

char	*cmd_dir(char **path, char *cmd_name)
{
	int		i;
	char	*tmp;
	char	*cmd_path;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(tmp, cmd_name);
		if (access(cmd_path, F_OK) != -1)
		{
			if (access(cmd_path, X_OK) == -1)
				ft_printf_fd(2, "pipex: permission denied: %s\n", cmd_path);
			free(tmp);
			free_array(path);
			return (cmd_path);
		}
		free(tmp);
		free(cmd_path);
		i++;
	}
	ft_printf_fd(2, "pipex: command not found: %s\n", cmd_name);
	free_array(path);
	return (NULL);
}

/* ************************************************************************** */

char	**get_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(ft_strchr(envp[i], '/'), ':', 0);
			// ft_printf_fd(1, "path = %s\n", path[0]);
			return (path);
		}
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */

int	get_fds(char *arg, int input)
{
	int	ret;

	if (input)
		ret = open(arg, O_RDONLY, 0777);
	else if (!input)
		ret = open(arg, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (ret);
}

/* ************************************************************************** */

void	check_fd(char *file, int input)
{
	if (access (file, F_OK) != -1 && input)
	{
		if (access (file, R_OK) == -1)
			ft_printf_fd(2, "pipex: permission denied: %s\n", file);
	}
	if (access (file, F_OK) != -1 && !input)
	{
		if (access (file, W_OK) == -1)
			ft_printf_fd(2, "pipex: permission denied: %s\n", file);
	}
	if (access (file, F_OK) == -1 && input)
		ft_printf_fd(2, "pipex: no such file or directory: %s\n", file);
}

/* ************************************************************************** */

t_pipex	*init_pipex(char **args, char **envp)
{
	t_pipex	*pipex;
	int		*fd_in_out;
	char	***cmds;

	fd_in_out = malloc(sizeof(int) * 2);
	cmds = malloc(sizeof(char **) * 4);
	check_fd(args[1], 1);
	fd_in_out[0] = get_fds(args[1], 1);
	cmds[0] = ft_split(args[2], ' ', 0);
	// if (fd_in_out[0] != -1)
		cmds[1] = ft_split(cmd_dir(get_path(envp), cmds[0][0]), ' ', 1);
	// check_fd(args[4], 0);
	fd_in_out[1] = get_fds(args[4], 0);
	cmds[2] = ft_split(args[3], ' ', 0);
	// if (fd_in_out[1] != -1)
		cmds[3] = ft_split(cmd_dir(get_path(envp), cmds[2][0]), ' ', 1);

	// if (fd_in_out[0] == -1 || fd_in_out[1] == -1)
	// 	exit (0);
	// if (!cmds[1] || !cmds[3])
	// 	exit (1);
	
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	pipex->fds = fd_in_out;
	pipex->cmd = cmds;
	// printpipex(pipex);
	return (pipex);
}

/* ************************************************************************** **

memo:

	typedef struct s_pipex
	{
		int			*fds;
		char		***cmd;
	}	t_pipex;

	cmds[0] = cmds
	cmds[1] = cmd_path
	cmds[2] = cmds
	cmds[3] = cmd_path

	if fd KO or cmd KO
	init_pipex gives -1 in fds
	if cmd KO, cmds[1] and cmds[3] are NULL (no cmds[1][0]etc)
	--------------------------------------------------------------------
tests
	// printf ("fd opended\n fd[0] = %d\n", fd_in_out[0]);
	// printf ("cmd = %s\n",cmds[0][0]);
	// printf ("cmd_path = %s\n\n",cmds[1]);

	// printf ("fd opended\n fd[0] = %d\n", fd_in_out[0]);
	// printf ("cmd = %s\n",cmds[2][0]);
	// printf ("cmd_path = %s\n",cmds[3][0]);


** ************************************************************************** */