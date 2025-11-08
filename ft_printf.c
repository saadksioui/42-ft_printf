/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:44:30 by sksioui           #+#    #+#             */
/*   Updated: 2025/11/08 14:59:41 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mandatory_specifier(char spec)
{
	if (spec == 'c' || spec == 's' || spec == '%' || spec == 'd' || spec == 'i' || spec == 'u' || spec == 'x' || spec == 'X' || spec == 'p')
		return (1);
	return (0);
}

int	ft_find_specifier(va_list args, const char format)
{
	if (format == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (format == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (format == '%')
		return (ft_print_char('%'));
	else if (format == 'd' || format == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), format));
	else
		return (ft_print_ptr(va_arg(args, void *)));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		cc;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	cc = 0;
	while (format[i]) 
	{
		if (format[i] == '%' && mandatory_specifier(format[i + 1]))
		{
			cc += ft_find_specifier(args, format[i + 1]);
			i++;
		}
		else
			cc += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (cc);
}
