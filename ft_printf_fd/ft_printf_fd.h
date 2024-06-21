/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:48:42 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/21 15:24:01 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf_fd(int fd, const char *form, ...);
int		check_what_it_is(int fd, char *form, va_list args);
int		ft_putchar_fd(int fd, char c);
int		ft_putstr_fd(char *s, int fd);
void	ft_putnbr(int fd, long int n);
void	ft_putnbr_fd(int fd, int n);
void	check_backslashes(int fd, char *form);
int		ft_putnbr_base(int fd, int nbr);
int		ft_putnbr_base_cap(int fd, int nbr);
int		ft_putnbr_base_p(int fd, unsigned long long nbr);
int		nbrlen(int fd, long long nbr);
int		nbrlen_unsigned(int fd, long long nbr);

#endif