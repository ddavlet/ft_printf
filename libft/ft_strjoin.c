/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:30:18 by ddavlety          #+#    #+#             */
/*   Updated: 2023/12/01 13:04:02 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	i = 0;
	j = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc((j + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	free(s1);
	while (*s2)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}
