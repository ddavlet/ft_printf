/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:23:32 by ddavlety          #+#    #+#             */
/*   Updated: 2023/11/30 19:10:19 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// size_t	ft_strlen(const char *s)
// {
// 	int	count;

// 	count = 0;
// 	if (!s)
// 		return (0);
// 	while (s[count])
// 		count++;
// 	return (count);
// }

// int	ft_putunsnbr_fd(unsigned int n, int fd) // ITOA
// {
// 	int	i;

// 	i = 1;
// 	if (n >= 10)
// 		i += ft_putunsnbr_fd(n / 10, fd);
// 	// ft_putchar_fd(n % 10 + 48, fd);
// 	return (i);
// }

// int	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// 	return (1);
// }

// int	ft_putnbr_fd(int n, int fd) //ITOA
// {
// 	int	i;

// 	i = 1;
// 	if (n == INT_MIN)
// 	{
// 		ft_putstr_fd("-2147483648", fd);
// 		return (11);
// 	}
// 	if (n == 0)
// 	{
// 		ft_putchar_fd('0', fd);
// 		return (1);
// 	}
// 	if (n < 0)
// 	{
// 		ft_putchar_fd('-', fd);
// 		n *= -1;
// 		i++;
// 	}
// 	if (n >= 10)
// 	{
// 		i += ft_putnbr_fd(n / 10, fd);
// 	}
// 	ft_putchar_fd(n % 10 + 48, fd);
// 	return (i);
// }

// int	ft_putstr_fd(char *s, int fd)
// {
// 	if (!s)
// 	{
// 		write(fd, "(null)", 6);
// 		return (6);
// 	}
// 	write(fd, s, ft_strlen(s));
// 	return (ft_strlen(s));
// }
