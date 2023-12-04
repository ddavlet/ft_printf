/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_utilsbonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:28:25 by ddavlety          #+#    #+#             */
/*   Updated: 2023/12/04 13:30:58 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

const char	*ft_params(const char *txt, char *set, char specifier)
{
	int	i;
	int	j;

	j = 0;
	while (txt[j] != specifier)
	{
		i = 0;
		while (set[i])
		{
			if (set[i] == txt[j])
				return (&txt[j]);
			i++;
		}
		j++;
	}
	return (0);
}

void	write_int_param(const char *txt,
			unsigned int *params_set, int index, char specifier)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	while (txt[i] && txt[i] != specifier)
	{
		if (ft_isdigit(txt[i]))
		{
			j = i;
			while (ft_isdigit(txt[i]) && txt[i] != specifier)
				i++;
			break ;
		}
		i++;
	}
	ptr = ft_substr(&txt[j], 0, i - j);
	if (params_set[index] == 0)
		params_set[index] = ft_atoi(ptr);
	free (ptr);
}

void	write_param(const char *param, unsigned int *params_set, char specifier)
{
	const char	*temp;

	if (*param == '0')
		params_set[1] = 1;
	else if (*param == '-')
		params_set[2] = 1;
	else if (*param == '.')
		params_set[3] = 1;
	temp = ft_params(param, "123456789", specifier);
	if (temp)
		write_int_param(temp, params_set, 4, specifier);
}
