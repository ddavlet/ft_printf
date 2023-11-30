/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:25:39 by ddavlety          #+#    #+#             */
/*   Updated: 2023/11/30 19:21:59 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	ptr = ft_substr(txt, 0, i - 1);
	if (params_set == 0)
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

char	*return_add_toend(unsigned int *params, char *arg, char *temp)
{
	unsigned long	i;

	i = 0;
	ft_strlcat(temp, arg, (params[0] - ft_strlen(arg)));
	while (i < (params[0] - ft_strlen(arg)))
	{
		temp[i + params[0] - ft_strlen(arg)] = ' ';
		i++;
	}
	free(arg);
	return (temp);
}

char	*ft_print_void(unsigned long num, unsigned int *params)
{
	if (!num)
		return (ft_strdup("(nil)"));
	else
		return (int_prms_lgc(params,
				ft_itoa_hex(num, 'a'), 0));
}

char	*return_trsfm(int	*params, char *arg, char *temp)
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

char	*return_add_tobegin(int	*params, char *arg, char *temp)
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
		if ((params[3] == 1 || params[1] == 1) && format == 1)
			return (return_trsfm(params, arg, temp));
		else if (params[2] == 1)
			return (return_add_toend(params, arg, temp));
		else
			return (return_add_tobegin(params, arg, temp));
	}
	return (arg);
}

char *ft_print_param(char format, va_list argv, int *params)
{
	//test for NULLS arg
	if (format == 'i' || format == 'd')
		int_prms_lgc(params, ft_itoa(va_arg(argv, int)), 1);
	if (format == 's')
		int_prms_lgc(params, ft_strdup(va_arg(argv, char *)), 0);
	else if (format == 'u')
		int_prms_lgc(params, ft_itoa_ui(va_arg(argv, unsigned int)), 1);
	else if (format == '\%')
		int_prms_lgc(params, chr_to_str('\%'), 0);
	else if (format == 'c')
		int_prms_lgc(params, chr_to_str(va_arg(argv, int)), 0);
	else if (format == 'p')
		ft_print_void(va_arg(argv, unsigned long), params);
	else if (format == 'x')
		int_prms_lgc(params, ft_itoa_hex(va_arg(argv, unsigned int), 'a'), 1);
	else if (format == 'X')
		int_prms_lgc(params, ft_itoa_hex(va_arg(argv, unsigned int), 'A'), 1);
	return (0);
}

unsigned int	ft_join_arg(const char *txt, va_list argv, char **to_print)
{
	char			specif;
	unsigned int	*params;
	int				i;

	i = 0;
	params = (int *)malloc(sizeof(int) * 4);
	if (!params)
		return (0);
	ft_bzero(params, 4);
	specif = ft_params(txt, "cspdiuxX\%");
	while (txt[i] != specif)
	{
		if (ft_params(&txt[i], "123456789"))
			write_int_param(&txt[i], params);
		if (ft_params(&txt[i], "-0."))
			write_param(txt[i], params);
		i++;
	}
	*to_print = ft_strjoin(*to_print, ft_print_param(specif, argv, params));
	return (i + 1);
}

unsigned int	ft_join_txt(const char *txt, char **to_print)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	while (txt[i] != '%' || txt[i])
		i++;
	ptr = ft_substr(txt, 0, i);
	*to_print = ft_strjoin(*to_print, ptr);
	free(ptr);
	return (i);
}

int	ft_printf(const char *txt, ...)
{
	char			*to_print;
	unsigned int	count;
	unsigned int	i;
	va_list			argv;

	if (!txt)
		return (-1);
	va_start(argv, txt);
	count = 0;
	while (txt[i])
	{
		if (txt[i] == '%')
			i += ft_join_arg(&txt[i], argv, &to_print);
		else
			i += ft_join_txt(&txt[i], &to_print);
	}
	va_end(argv);
	ft_putstr_fd(to_print, 1);
	count = ft_strlen(to_print);
	free (to_print);
	return (count);
}

