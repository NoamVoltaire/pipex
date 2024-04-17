/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:18:48 by nvoltair          #+#    #+#             */
/*   Updated: 2024/04/16 17:15:13 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static	char	*gato(char const *s1, char const *s2, char *glue)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (s1[i])
	{
		glue[i] = *((char *)s1 + i);
		i++;
	}
	while (s2[b])
	{
		glue[i] = *((char *)s2 + b);
		i++;
		b++;
	}
	glue[i] = '\0';
	return (glue);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*gluedstr;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	gluedstr = (char *)malloc(sizeof(char) * len + 1);
	if (!gluedstr)
		return (NULL);
	gluedstr = gato(s1, s2, gluedstr);
	return (gluedstr);
}

// int	main(int acount, char **arg)
// {
// 	char	*a;

// 	if (acount == 3)
// 	{
// 	a = ft_strjoin(arg[1],arg[2]);
// 	printf("%s%s\n", arg[1],arg[2]);
// 	printf("%s\n", a);
// 	free(a);
// 	}
// 	else if (acount < 2)
// 		printf("need more arg");
// 	else
// 		printf("need less args");
// }
//GOOD?