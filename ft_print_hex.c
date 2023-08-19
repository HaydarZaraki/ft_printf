/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helgayli <helgayli@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:35:30 by helgayli          #+#    #+#             */
/*   Updated: 2023/08/19 02:13:45 by helgayli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

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

int	ft_print_hex(unsigned int decimalNumber, char c)
{
	int		len;
	int		index;
	int		remainder;
	char	*hex;

	index = 0;
	len = 0;
	hex = malloc(sizeof(char) * 32);
	if (decimalNumber == 0)
		hex[index++] = '0';
	while (decimalNumber > 0)
	{
		remainder = decimalNumber % 16;
		if (remainder < 10)
			hex[index++] = 48 + remainder;
		else
			hex[index++] = c + (remainder - 10);
		decimalNumber /= 16;
	}
	hex[index] = '\0';
	len += ft_putstr_fd(ft_strrev(hex), 1);
	free(hex);
	return (len);
}

int	ft_print_ptr(unsigned long decimalNumber, char c)
{
	int		len;
	int		index;
	int		remainder;
	char	*hex;

	index = 0;
	len = 0;
	hex = malloc(sizeof(char) * 32);
	if (decimalNumber == 0)
		hex[index++] = '0';
	while (decimalNumber > 0)
	{
		remainder = decimalNumber % 16;
		if (remainder < 10)
			hex[index++] = 48 + remainder;
		else
			hex[index++] = c + (remainder - 10);
		decimalNumber /= 16;
	}
	hex[index] = '\0';
	len += ft_putstr_fd(ft_strrev(hex), 1);
	free(hex);
	return (len);
}
