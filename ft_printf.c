/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helgayli <helgayli@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:00:38 by helgayli          #+#    #+#             */
/*   Updated: 2023/08/17 17:52:55 by helgayli         ###   ########.fr       */
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

int	len(int n, int is_unsigned)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		if (is_unsigned != 1)
			len++;
	}
	if (n == 0)
	{
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	write_data(char *str, int n, int i, int is_unsigned)
{
	if (n < 0)
	{
		if (is_unsigned != 1)
			str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int num, int is_unsigned)
{
	char	*str;
	long	n;
	int		i;

	n = num;
	i = len(n, is_unsigned);
	str = (char *)malloc(i + 1);
	if (str == NULL)
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	write_data(str, n, i, is_unsigned);
	return (str);
}

int	ft_print_hex_upper(unsigned int decimalNumber, char c)
{
	int	len;
	int index;
	
	index = 0;
	len = 0;
	char *hex = malloc(sizeof(char) * 100);
	if (decimalNumber == 0)
		hex[index++] = '0';
	while (decimalNumber > 0)
	{
		int remainder = decimalNumber % 16;
		hex[index++] = (remainder < 10) ? remainder + '0' : remainder - 10 + c;
		decimalNumber /= 16;
	}
	hex[index] = '\0';
	len += ft_putstr_fd(ft_strrev(hex), 1);
	free(hex);
	return (len);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	len;
	
	len = 0;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
		len++;
	}
	return (len);
}

int	check_operator(va_list args, char *str)
{
	int	len;
	
	len = 0;
	if (*str == 'd' || *str == 'i' || *str == 'u')
	{
		char *tmp = ft_itoa(va_arg(args, int), (*str == 'u')? 1 : 0);
		len += ft_putstr_fd(tmp, 1);
		free(tmp);
	}
	else if (*str == 'c')
		len += ft_putchar_fd(va_arg(args, int), 1);
	else if (*str == 's')
		len += ft_putstr_fd(va_arg(args, char *), 1);
	else if (*str == '%')
		len += ft_putchar_fd('%', 1);
	else if (*str == 'x' || *str == 'X')
		len += ft_print_hex_upper(va_arg(args, long), (*str == 'x')? 'a' : 'A');
	else if (*str == 'p')
	{
		len += ft_putstr_fd("0x", 1);
		len += ft_print_hex_upper(va_arg(args, long), 'a');
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	len;
	
	len = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
			{
			str++;
			len += check_operator(args, (char *)str);
			}
		else
			len += ft_putchar_fd(*str, 1);
		str++;
	}
	
	va_end(args);
	return (len);
}
// #include <stdio.h>
// #include <limits.h>

// int main()
// {
// 	char *str = "h";
// 	ft_printf(" %p ", str);
// 	printf(" %p ", str);
	
// }
