/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helgayli <helgayli@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:00:38 by helgayli          #+#    #+#             */
/*   Updated: 2023/08/15 01:22:16 by helgayli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_print_hex_upper(int decimalNumber)
{
	char	*hex;
	int		index;
	int		remainder;

	index = 0;
	hex = malloc(sizeof(char) * 16);
	while (decimalNumber > 0)
	{
		remainder = decimalNumber % 16;
		if (remainder < 10)
		{
			hex[index++] = remainder + '0';
		}
		else
		{
			hex[index++] = remainder - 10 + 'A';
		}
		decimalNumber /= 16;
	}
	ft_putstr_fd(hex, 1);
	free(hex);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
	else
	{
		num += 48;
		write(fd, &num, 1);
	}
}

char	*check_operator(va_list args, char *str)
{
	if (*str == '%' && *str + 1 == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*str == '%' && *str + 1 == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*str == '%' && *str + 1 == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (*str == '%' && *str + 1 == '%')
		write(1, "%", 1);
	else
		write(1, str, 1);
	str++;
	return (str);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	while (*str != '\0')
	{
		str = check_operator(args, (char *)str);
		str++;
	}
	va_end(args);
	return (1);
}

int main(void)
{
	long	i;

	i = 68702702548;
	ft_print_hex_upper(i);
	return (0);
}
