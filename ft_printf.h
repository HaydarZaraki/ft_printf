/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helgayli <helgayli@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:04:30 by helgayli          #+#    #+#             */
/*   Updated: 2023/08/17 14:15:30 by helgayli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define FT_PRINTF_H

int		ft_printf(const	char *c, ...);
int     ft_putnbr_fd(int n, int fd, int is_unsigned);
int     ft_putstr_fd(char *s, int fd);
int	    ft_putchar_fd(char c, int fd);
int     check_operator(va_list args, char *str);

#endif