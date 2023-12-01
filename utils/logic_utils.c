/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:27:08 by ddavlety          #+#    #+#             */
/*   Updated: 2023/12/01 15:55:00 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_print_void(unsigned long num, unsigned int *params)
{
	if (!num)
		return (ft_strdup("(nil)"));
	else
		return (int_prms_lgc(params,
				ft_itoa_hex(num, 'a'), 0));
}

char	*return_add_toend(unsigned int *params, char *arg, char *temp)
{
	unsigned long	i;

	i = 0;
	ft_strlcat(temp, arg, params[0]);
	while (i < (params[0] - ft_strlen(arg)))
	{
		temp[i + ft_strlen(arg)] = ' ';
		i++;
	}
	free(arg);
	return (temp);
}

char	*return_trsfm(unsigned int	*params, char *arg, char *temp)
{
	unsigned long	i;

	i = 0;
	while (i < (params[0] - ft_strlen(arg)))
		temp[i++] = '0';
	temp[i] = '\0';
	ft_strlcat(temp, arg, (params[0] + 1));
	free(arg);
	return (temp);
}

char	*return_add_tobegin(unsigned int	*params, char *arg, char *temp)
{
	unsigned long	i;

	i = 0;
	while (i < (params[0] - ft_strlen(arg)))
		temp[i++] = ' ';
	temp[i] = '\0';
	ft_strlcat(temp, arg, (params[0] + 1));
	free(arg);
	return (temp);
}

char	*int_prms_lgc(unsigned int	*params, char *arg, int format)
{
	char	*temp;

	if (!arg)
		return (0);
	if (ft_strlen(arg) < params[0])
	{
		temp = (char *)malloc(sizeof(char) * (params[0] + 1));
		if (!temp)
			return (0);
		ft_bzero (temp, params[0]);
		if ((params[3] == 1 || params[1] == 1) && format == 1)
			return (return_trsfm(params, arg, temp));
		else if (params[2] == 1)
			return (return_add_toend(params, arg, temp));
		else
			return (return_add_tobegin(params, arg, temp));
	}
	return (arg);
}
