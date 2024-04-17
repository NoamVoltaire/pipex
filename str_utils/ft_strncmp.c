/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:19:58 by nvoltair          #+#    #+#             */
/*   Updated: 2024/04/16 17:15:46 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		sum;

	i = 0;
	sum = 0;
	while ((s1[i] || s2[i]) && sum == 0 && (i < n))
	{
		sum = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
		i++;
	}
	return (sum);
}

// int	main(int ac, char **av)
// {
// 	if (ac > 2)
// 	{
// 		if (ft_strncmp(av[1], av[2], 5) == strncmp(av[1], av[2], 5))
// 			printf("YES OK");
// 		else
// 			printf("NOPE");
// 	}
// 	else
// 		printf("need more arg");

// }
//GOOD