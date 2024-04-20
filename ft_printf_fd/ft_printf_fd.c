/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:22:03 by nvoltair          #+#    #+#             */
/*   Updated: 2024/04/20 19:21:29 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_printf_fd(int fd, const char *form, ...)
{
	va_list		args;
	long long	i;
	int			len;

	i = 0;
	len = 0;
	va_start(args, form);
	while (form[i])
	{
		if (form[i] == '%' && form[i + 1])
		{
			len += check_what_it_is(fd, ((char *)form + i), args);
			i += 2;
		}
		else if (form[i] == '\\' && form[i + 1])
		{
			check_backslashes(fd, (char *)form + i);
			i += 2;
		}
		else if (form[i] != '%' && form[i] != '\\' && (len++ > -1))
			write(fd, &form[i++], 1);
	}
	va_end (args);
	return (len);
}

int	check_what_it_is(int fd, char *form, va_list args)
{
	if (*(form + 1) == 'c')
		return (ft_putchar_fd(fd, va_arg(args, int)));
	else if (*(form + 1) == 's')
		return (ft_putstr_fd((va_arg(args, char *)), fd));
	else if (*(form + 1) == 'p')
		return (ft_putnbr_base_p(fd, va_arg(args, unsigned long long)));
	else if (*(form + 1) == 'd' || *(form + 1) == 'i')
		return (nbrlen(fd, va_arg(args, int)));
	else if (*(form + 1) == 'u')
		return (nbrlen_unsigned(fd, va_arg(args, unsigned int)));
	else if (*(form + 1) == 'x')
		return (ft_putnbr_base(fd, va_arg(args, int)));
	else if (*(form + 1) == 'X')
		return (ft_putnbr_base_cap(fd, va_arg(args, int)));
	else if (*(form + 1) == '%')
		write(fd, "%", 1);
	return (1);
}

void	check_backslashes(int fd, char *form)
{
	if (*(form + 1) == '\\')
		write(fd, "\\", 1);
	if (*(form + 1) == 'n')
		write(fd, "\n", 1);
	if (*(form + 1) == 't')
		write(fd, "\t", 1);
	if (*(form + 1) == 'v')
		write(fd, "\v", 1);
	if (*(form + 1) == 'f')
		write(fd, "\f", 1);
	if (*(form + 1) == 'r')
		write(fd, "\r", 1);
}

int	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

/*
int main() {

	ft_printf_fd(2, "Error: %s\n", "This is an error message");
	ft_printf_fd(1, "Hello, World!\n");
	
	
//     int integerValue = 42;
//     long long longrValue = __LONG_MAX__;
// 	long long *ptr = &longrValue;
//     // float floatValue = 3.14;
//     char charValue = 'A';
//     char stringValue[] = "Hello, World!";
//     unsigned int unsignedValue = -1;

//     ft_printf_fd(1, "ft_Char:		_|%c\n", charValue);
//     ft_printf_fd(1, "ft_String: 		_|%s\n", stringValue);
//     ft_printf_fd(1, "ft_Hexadecimal void:	_|%p\n", ptr);
//     ft_printf_fd(1, "ft_Decimal:	 	_|%d\n", integerValue);
//     ft_printf_fd(1, "ft_Integer:		_|%i\n", integerValue);
//     ft_printf_fd(1, "ft_Unsigned Int:	_|%u\n", unsignedValue);
//     ft_printf_fd(1, "ft_Hexadecimal:		_|%x\n", integerValue);
// 	ft_printf_fd(1, "ft_Hexadecimal Cap:	_|%X\n", integerValue);
//    ft_printf_fd(1, "%d\n\n", ft_printf_fd(1, "Ayo%p\n\n", &integerValue));
	
//     printf("Char:			_|%c\n", charValue);
//     printf("String: 		_|%s\n", stringValue);
//     printf("Hexadecimal void:	_|%p\n", ptr);
//     printf("Decimal:	 	_|%d\n", integerValue);
//     printf("Integer:		_|%i\n", integerValue);
//     printf("Unsigned Int:		_|%u\n", unsignedValue);
//     printf("Hexadecimal:		_|%x\n", integerValue);
//     printf("Hexadecimal Cap:	_|%X\n", integerValue);
//     printf("%d\n\n", printf("Ayo%p\n\n", &integerValue));

//     return 0;
}
*/