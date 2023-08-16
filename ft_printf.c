/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helgayli <helgayli@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:00:38 by helgayli          #+#    #+#             */
/*   Updated: 2023/08/16 14:59:32 by helgayli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int i;
	int len;
	char tmp;

	i = 0;
	len = ft_strlen(str) - 1;
	while (len > i)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

void	ft_print_hex_upper(int decimalNumber, char c)
{
	char	*hex;
	int		index;
	int		remainder;

	index = 0;
	hex = malloc(sizeof(char) * 16);
	if (decimalNumber == 0)
		hex[index++] = '0';
	if (decimalNumber < 0)
	{
		write(1,"-",1);
		decimalNumber *= -1;	
	}
	while (decimalNumber > 0)
	{
		remainder = decimalNumber % 16;
		if (remainder < 10)
			hex[index++] = remainder + '0';
		else
			hex[index++] = remainder - 10 + c;
		decimalNumber /= 16;
	}
	hex[index++] = '\0';
	ft_putstr_fd(ft_strrev(hex), 1);
	free(hex);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	len;
	
	len = 0;
	if (s == NULL)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
		len++;
	}
	return (len);
}

void	ft_putnbr_fd(int n, int fd,int is_unsigned)
{
	long	num;

	num = n;
	if (num < 0)
	{
		if (is_unsigned != 1)
			write(fd, "-", 1);
		num *= -1;
	}
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd, is_unsigned);
		ft_putnbr_fd(num % 10, fd, is_unsigned);
	}
	else
	{
		num += 48;
		write(fd, &num, 1);
	}
}

char	*check_operator(va_list args, char *str)
{
	if (*str == 'd' || *str == 'i')
		ft_putnbr_fd(va_arg(args, int), 1, 0);
	else if (*str == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*str == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (*str == '%')
		write(1, "%", 1);
	else if (*str == 'u')
		ft_putnbr_fd(va_arg(args, int), 1, 1);
	else if (*str == 'x')
		ft_print_hex_upper(va_arg(args, int), 'a');
	else if (*str == 'X')
		ft_print_hex_upper(va_arg(args, int), 'A');
	else if (*str == 'p')
	{
		write(1, "0x", 2);
		ft_print_hex_upper(va_arg(args, int), 'a');
	}
	return (str);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
			{
			str++;
			check_operator(args, (char *)str);
			}
		else
			write(1, str, 1);
		str++;
	}
	va_end(args);
	return (1);
}
// #include <stdio.h>
// int main()
// {
// 	char *ptr = NULL;
// 	ft_printf("Signed : %p || UnSigned : %X || String : %s \n", ptr, 0, NULL);
// 	int i = printf("Signed : %p || UnSigned : %X", ptr, 0);
// 	printf("\n%d\n", i);
// 	return (0);
// }
