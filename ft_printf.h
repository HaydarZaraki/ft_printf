/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helgayli <helgayli@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:04:30 by helgayli          #+#    #+#             */
/*   Updated: 2023/08/12 10:05:42 by helgayli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# define FT_PRINTF_H

int		ft_printf(const	char *c, ...);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*check_operator(va_list args, char *str);

#endif