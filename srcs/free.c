/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:47:47 by noam              #+#    #+#             */
/*   Updated: 2024/04/20 19:54:28 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* ************************************************************************** */

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/* ************************************************************************** */

void	free_cmds(char ***cmds, int len)
{
	int	i;
	int	j;

	i = 0;
	while (len >= 0)
	{
		if (cmds[len])
			free_array(cmds[len]);
		len--;
	}
	free(cmds);
}

/* ************************************************************************** */


void	free_pipex(t_pipex *pipex)
{
	free(pipex->fds);
	free_cmds(pipex->cmd, (arrs_len((void ***)pipex->cmd) - 1));
	free(pipex);
}
