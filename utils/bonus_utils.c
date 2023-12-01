/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:27:22 by ddavlety          #+#    #+#             */
/*   Updated: 2023/12/01 13:58:06 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

unsigned int	*initialize_int(unsigned int *ptr, int i)
{
	while (i != 0)
	{
		i--;
		ptr[i] = 0;
	}
	return (ptr);
}
