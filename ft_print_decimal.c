/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helgayli <helgayli@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 09:33:57 by helgayli          #+#    #+#             */
/*   Updated: 2023/08/16 14:37:39 by helgayli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
