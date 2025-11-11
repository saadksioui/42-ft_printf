/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:27:34 by sksioui           #+#    #+#             */
/*   Updated: 2025/11/11 10:18:04 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char b)
{
	int		count;
	char	*base16;

	if (b == 'x')
		base16 = "0123456789abcdef";
	else
		base16 = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_print_hex(n / 16, b);
	count += ft_print_char(base16[n % 16]);
	return (count);
}