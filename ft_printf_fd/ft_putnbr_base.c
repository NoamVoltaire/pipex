/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:54:15 by nvoltair          #+#    #+#             */
/*   Updated: 2024/04/16 14:59:48 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

void	prt(int fd, char c)
{
	write(fd, &c, 1);
}

void	writestuff(int fd, unsigned long long nbr, char *base)
{
	char	symb;

	if (nbr >= 16)
		writestuff(fd, nbr / 16, base);
	symb = base[nbr % 16];
	prt(fd, symb);
	while (*base != symb)
		base++;
}

int	ft_putnbr_base(int fd, unsigned int nbr)
{
	int		len;
	char	*hum;

	hum = "0123456789abcdef";
	len = 0;
	if (nbr < 0)
		nbr = nbr * -1;
	writestuff(fd, nbr, hum);
	if (!nbr)
		return (1);
	while (nbr && (len++ > -1))
		nbr /= 16;
	return (len);
}

int	ft_putnbr_base_cap(int fd, unsigned int nbr)
{
	int		len;
	char	*hum;

	hum = "0123456789ABCDEF";
	len = 0;
	if (nbr < 0)
		nbr = nbr * -1;
	writestuff(fd, nbr, hum);
	if (!nbr)
		return (1);
	while (nbr && (len++ > -1))
		nbr /= 16;
	return (len);
}

int	ft_putnbr_base_p(int fd, unsigned long long nbr)
{
	int		len;
	char	*hum;

	hum = "0123456789abcdef";
	len = 0;
	if (nbr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
		write(fd, "0x", 2);
	writestuff(fd, nbr, hum);
	while (nbr && (len++ > -1))
		nbr /= 16;
	return (len + 2);
}

//0123456789ABCDEF
//0123456789abcdef
// int main ()
// {
// 	ft_putnbr_base(42);
// }
/*
int	main()
{
	ft_putnbr_base(0,"01");
	// printf("%s\n", ft_putnbr_base(42,"01"));
	//  printf("%d\n", ft_strlen("01"));

}

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

int		main(void)
{
	write(1, "42:", 3);
	ft_putnbr_base(42, "0123456789");
	write(1, "\n2a:", 4);
	ft_putnbr_base(42, "0123456789abcdef");
	write(1, "\n-2a:", 5);
	ft_putnbr_base(-42, "0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "0");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "+-0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "\t0123456789abcdef");
}
*/