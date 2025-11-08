/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:27:49 by sksioui           #+#    #+#             */
/*   Updated: 2025/11/06 16:00:44 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int				count;
	unsigned long	adr;

	if (!ptr)
		return (ft_print_str("(nil)"));
	adr = (unsigned long)ptr;
	count = 0;
	count += ft_print_str("0x");
	count += ft_print_hex(adr, 'x');
	return (count);
}
