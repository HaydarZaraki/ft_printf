/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helgayli <helgayli@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:00:38 by helgayli          #+#    #+#             */
/*   Updated: 2023/08/19 21:34:03 by helgayli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	check_operator_c_s_o(va_list args, char *str)
{
	int		len;

	len = 0;
	if (*str == 'c')
		len += ft_putchar_fd(va_arg(args, int), 1);
	else if (*str == 's')
		len += ft_putstr_fd(va_arg(args, char *), 1);
	else if (*str == '%')
		len += ft_putchar_fd('%', 1);
	return (len);
}

int	check_operator_x_p(va_list args, char *str)
{
	int		len;

	len = 0;
	if (*str == 'x')
		len += ft_print_hex(va_arg(args, long), 'a');
	else if (*str == 'X')
		len += ft_print_hex(va_arg(args, long), 'A');
	else if (*str == 'p')
	{
		len += ft_putstr_fd("0x", 1);
		len += ft_print_ptr(va_arg(args, long), 'a');
	}
	return (len);
}

int	check_operator_d_i_u(va_list args, char *str)
{
	int		len;
	char	*tmp;

	len = 0;
	if (*str == 'd' || *str == 'i' || *str == 'u')
	{
		if (*str == 'd' || *str == 'i')
			tmp = ft_itoa(va_arg(args, int));
		else
			tmp = ft_itoa_unsigned(va_arg(args, int));
		len += ft_putstr_fd(tmp, 1);
		free(tmp);
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			len += check_operator_d_i_u(args, (char *)str);
			len += check_operator_x_p(args, (char *)str);
			len += check_operator_c_s_o(args, (char *)str);
		}
		else
			len += ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(args);
	return (len);
}
