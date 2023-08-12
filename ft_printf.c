/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helgayli <helgayli@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:00:38 by helgayli          #+#    #+#             */
/*   Updated: 2023/08/12 10:39:56 by helgayli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		str = check_operator(args, (char *) str);
		str++;
	}
	va_end(args);
	return (1);
}

int	main(void)
{
	int	i;

	i = 10;
	ft_printf("xxxxxx%dxxxx", i);
	return (0);
}
