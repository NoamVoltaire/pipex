/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxilary_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:53:34 by nvoltair          #+#    #+#             */
/*   Updated: 2024/04/16 14:45:16 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (ft_putstr_fd("(null)", 1));
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

void	ft_putnbr(int fd, long int n)
{
	long	boi;

	boi = n;
	if (boi == -2147483648)
	{
		ft_putchar_fd(fd, '-');
		ft_putchar_fd(fd, '2');
		ft_putnbr_fd(fd, 147483648);
	}
	else
	{
		if (boi >= 0 && boi <= 9)
			ft_putchar_fd(fd, '0' + (boi));
		else if (boi < 0)
		{
			ft_putchar_fd(fd, '-');
			ft_putnbr_fd(fd, boi * -1);
		}
		else if (boi > 9)
		{
			ft_putnbr_fd(fd, boi / 10);
			ft_putnbr_fd(fd, boi % 10);
		}
	}
}

void	ft_putnbr_fd(int fd, unsigned int n)
{
	if (n >= 0 && n <= 9)
		ft_putchar_fd(fd, '0' + (n));
	else if (n < 0)
	{
		ft_putchar_fd(fd, '-');
		ft_putnbr_fd(fd, n * -1);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(fd, n / 10);
		ft_putnbr_fd(fd, n % 10);
	}
}

int	nbrlen(int fd, long long nbr)
{
	int	len;

	len = 0;
	ft_putnbr(fd, nbr);
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len++;
	while (nbr && (len++ > -1))
		nbr /= 10;
	return (len);
}

int	nbrlen_unsigned(int fd, long long nbr)
{
	int	len;

	len = 0;
	ft_putnbr_fd(fd, nbr);
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len++;
	while (nbr && (len++ > -1))
		nbr /= 10;
	return (len);
}
