/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:27:22 by ddavlety          #+#    #+#             */
/*   Updated: 2023/12/01 18:17:07 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*chr_to_str(int c)
{
	char	*ptr;

	if (c == 0)
	{
		ptr = (char *)malloc(sizeof(char) * 3);
		ptr[0] = '^';
		ptr[1] = '@';
		ptr[2] = '\0';
	}
	else
	{
		ptr = (char *)malloc(sizeof(char) * 2);
		if (!ptr)
			return (0);
		ptr[0] = (char)c;
		ptr [1] = '\0';
	}
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

int	ft_putstr(char *s)
{
	size_t	i;
	char	c;

	c = 0;
	i = 0;
	while (s[i] != '^' && s[i])
		i++;
	if (s[i])
	{
		if (s[i + 1] == '@')
		{
			write(1, s, i);
			write(1, &c, 1);
			write(1, &(s[i + 2]), ft_strlen(&(s[i + 2])));
			return (ft_strlen(s) - 1);
		}
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
