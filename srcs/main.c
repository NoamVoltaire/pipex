/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:21:58 by noam              #+#    #+#             */
/*   Updated: 2024/04/17 18:54:17 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;
	// int pipefd[2];
	// int pid;
	// int dip;

	pipex = NULL;
	if (ac != 5)
	{
		perror("Error");
		exit(1);
	}
	pipex = init_pipex(av, envp);
	//fork procces(pipex, envp (pipefd))
	// free(pipex);
	ft_printf_fd(1, "cool\n");
}