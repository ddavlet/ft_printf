/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:22:47 by ddavlety          #+#    #+#             */
/*   Updated: 2023/12/04 13:31:04 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	ft_counter_hex(size_t n)
{
	size_t	i;

	i = 1;
	if (n >= 16)
		i += ft_counter_hex(n / 16);
	return (i);
}

char	*ft_itoa_hex(size_t i, char ulc)
{
	char			*ptr;
	int				bytes;
	size_t			remainder;

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
			ptr[bytes] = remainder + '0';
		else
			ptr[bytes] = remainder - 10 + ulc;
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
