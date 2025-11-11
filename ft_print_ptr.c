/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:27:49 by sksioui           #+#    #+#             */
/*   Updated: 2025/11/11 10:17:43 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_hex(unsigned long n)
{
	int		count;
	char	*base16;

	base16 = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += convert_hex(n / 16);
	count += ft_print_char(base16[n % 16]);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	int				count;

	if (!ptr)
		return (ft_print_str("(nil)"));
	count = 0;
	count += ft_print_str("0x");
	count += convert_hex((unsigned long)ptr);
	return (count);
}