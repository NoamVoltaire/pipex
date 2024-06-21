/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:57:40 by noam              #+#    #+#             */
/*   Updated: 2024/06/21 15:17:39 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

# include "../ft_printf_fd/ft_printf_fd.h"


typedef struct s_pipex
{
	int			*fds;
	char		***cmd;
}	t_pipex;
void printpipex(t_pipex *pipex);

char	**ft_split(char *s, char c, int free_s);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

t_pipex	*init_pipex(char **args, char **envp);
void	free_pipex(t_pipex *pipex);
void	free_array(char **array);
int		arrs_len(void ***array);


#endif