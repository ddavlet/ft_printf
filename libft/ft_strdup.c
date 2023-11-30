/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:31:10 by ddavlety          #+#    #+#             */
/*   Updated: 2023/11/30 18:19:02 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s)
		return (0);
	i = ft_strlen(s);
	j = 0;
	ptr = (char *)malloc((i +1) * sizeof(char));
	if (!ptr)
		return (0);
	while (j <= i)
	{
		ptr[j] = s[j];
		j++;
	}
	return (ptr);
}
