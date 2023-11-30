/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:27:22 by ddavlety          #+#    #+#             */
/*   Updated: 2023/11/30 19:14:21 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_counter_hex(unsigned int n)
{
	int	i;

	i = 1;
	if (n >= 16)
		i += ft_counter_hex(n / 16);
	return (i);
}

char	*ft_itoa_hex(unsigned long i, char ulc)
{
	char			*ptr;
	int				bytes;
	unsigned long	remainder;


	bytes = ft_counter_hex(i);
	ptr = (char *)malloc((bytes + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ptr[bytes--] = '\0';
	if (i == 0)
		ptr[bytes] = '0';
	while (i != 0 && bytes > -1)
	{
		remainder = i % 16;
		if (remainder < 10)
			ptr[bytes] = i % 16 + '0';
		else
			ptr[bytes] = i % 16 + ulc;
		bytes--;
		i /= 16;
	}
	return (ptr);
}

static int	ft_counter_ui(unsigned int n)
{
	unsigned int	i;

	i = 1;
	if (n >= 10)
		i += ft_counter_ui(n / 10);
	return (i);
}

char	*ft_itoa_ui(unsigned int i)
{
	char	*ptr;
	int		bytes;

	bytes = ft_counter_ui(i);
	ptr = (char *)malloc((bytes + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ptr[bytes--] = '\0';
	if (i == 0)
		ptr[bytes] = '0';
	while (i != 0 && bytes > -1)
	{
		ptr[bytes] = i % 10 + 48;
		bytes--;
		i /= 10;
	}
	return (ptr);
}

char	*chr_to_str(int c)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * 2);
	if (!ptr)
		return (0);
	ptr[0] = (char)c;
	ptr [1] = '\0';
	return (ptr);
}

void	ft_charzero(void *s, unsigned long n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n != 0)
	{
		n--;
		ptr[n] = '0';
	}
}
