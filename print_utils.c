/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:23:32 by ddavlety          #+#    #+#             */
/*   Updated: 2023/11/22 15:24:23 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsnbr_fd(unsigned int n, int fd)
{
	int	i;

	i = 1;
	if (n >= 10)
		i += ft_putunsnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
	return (i);
}
