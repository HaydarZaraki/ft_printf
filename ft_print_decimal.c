/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helgayli <helgayli@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 09:33:57 by helgayli          #+#    #+#             */
/*   Updated: 2023/08/17 12:27:08 by helgayli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd,int is_unsigned)
{
	long	num;
	int 	len;
	
	len = 0;
	num = n;
	if (num < 0)
	{
		if (is_unsigned != 1)
			len += ft_putchar_fd('-', fd);
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
		len += ft_putchar_fd(num, fd);
	}
	return (len);
}
