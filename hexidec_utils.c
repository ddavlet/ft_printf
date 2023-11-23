/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexidec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:05:37 by ddavlety          #+#    #+#             */
/*   Updated: 2023/11/23 11:25:05 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_fd(unsigned int num, int fd)
{
	int	remainder;
	int	i;

	remainder = 0;
	i = 1;
	if (num >= 16)
	{
		i += ft_putnbr_hex_fd(num / 16, fd);
	}
	remainder = num % 16;
	if (remainder < 10)
	{
		ft_putchar_fd('0' + remainder, fd);
	}
	else
	{
		ft_putchar_fd('a' + remainder - 10, fd);
	}
	return (i);
}

int	ft_putnbr_hexcap_fd(unsigned int num, int fd)
{
	int	remainder;
	int	i;

	remainder = 0;
	i = 1;
	if (num >= 16)
	{
		ft_putnbr_hex_fd(num / 16, fd);
		i++;
	}
	remainder = num % 16;
	if (remainder < 10)
	{
		ft_putchar_fd('0' + remainder, fd);
	}
	else
	{
		ft_putchar_fd('A' + remainder - 10, fd);
	}
	return (i);
}
