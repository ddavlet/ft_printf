/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:28:25 by ddavlety          #+#    #+#             */
/*   Updated: 2023/12/01 13:28:34 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	ft_params(const char *txt, char *set)
{
	int	i;
	int	j;

	j = 0;
	while (txt[j])
	{
		i = 0;
		while (set[i])
		{
			if (set[i] == txt[j])
				return (set[i]);
			i++;
		}
		j++;
	}
	return (0);
}

void	write_int_param(const char *txt, unsigned int *params_set)
{
	int		i;
	char	*ptr;

	i = 0;
	while (ft_isdigit(txt[i]))
		i++;
	ptr = ft_substr(txt, 0, i);
	if (params_set[0] == 0)
		params_set[0] = ft_atoi(ptr);
	free (ptr);
}

void	write_param(char param, unsigned int *params_set)
{
	if (param == '0')
		params_set[1] = 1;
	else if (param == '-')
		params_set[2] = 1;
	else if (param == '.')
		params_set[3] = 1;
}
