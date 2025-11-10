/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 22:35:36 by alerradi          #+#    #+#             */
/*   Updated: 2025/11/10 14:02:13 by alerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_print_hex(unsigned long x, char format);
int		ft_print_format(char format, va_list args);
int		ft_printf(const char *s, ...);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(long n, char format);
int		ft_print_ptr(void *s);

#endif