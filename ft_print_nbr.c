/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:09:01 by sksioui           #+#    #+#             */
/*   Updated: 2025/11/06 15:56:04 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int		count;
	long	nb;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_print_char('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		count += ft_print_nbr(nb / 10);
		count += ft_print_char((nb % 10) + '0');
	}
	else
		count += ft_print_char(nb + '0');
	return (count);
}