/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:25:39 by ddavlety          #+#    #+#             */
/*   Updated: 2023/12/04 13:31:02 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_print_param(char format, va_list argv, unsigned int *params)
{
	if (format == 'i' || format == 'd')
		return (int_prms_lgc(params, ft_itoa(va_arg(argv, int)), 1));
	if (format == 's')
		return (str_prms_lgc(params, ft_strdup(va_arg(argv, char *)), 0));
	else if (format == 'u')
		return (int_prms_lgc(params,
				ft_itoa_ui(va_arg(argv, unsigned int)), 1));
	else if (format == '\%')
		return (int_prms_lgc(params, chr_to_str('\%'), 2));
	else if (format == 'c')
		return (int_prms_lgc(params, chr_to_str(va_arg(argv, int)), 0));
	else if (format == 'p')
		return (ft_print_void(va_arg(argv, size_t), params));
	else if (format == 'x')
		return (int_prms_lgc(params,
				ft_itoa_hex(va_arg(argv, unsigned int), 'a'), 1));
	else if (format == 'X')
		return (int_prms_lgc(params,
				ft_itoa_hex(va_arg(argv, unsigned int), 'A'), 1));
	else
		return (0);
}

unsigned int	ft_join_arg(const char *txt, va_list argv, char **to_print)
{
	char			specif;
	unsigned int	*params;
	char			*tmp;
	int				i;

	i = 0;
	params = (unsigned int *)malloc(sizeof(int) * 5);
	if (!params)
		return (0);
	params = initialize_int (params, 5);
	specif = *ft_params(++txt, "cspdiuxX\%", '\0');
	while (txt[i] != specif)
		i++;
	if (ft_params(txt, "123456789", specif) < ft_params(txt, ".", specif)
		|| ft_params(txt, ".", specif) == 0)
		write_int_param(txt, params, 0, specif);
	if (ft_params(txt, "-0.", specif))
		write_param(ft_params(txt, "-0.", specif), params, specif);
	tmp = ft_print_param(specif, argv, params);
	*to_print = ft_strjoin(*to_print, tmp);
	free(params);
	free(tmp);
	return (i + 1);
}

unsigned int	ft_join_txt(const char *txt, char **to_print)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	while (txt[i] != '%' && txt[i])
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
	i = 0;
	to_print = (char *)malloc(2);
	ft_bzero(to_print, 2);
	while (txt[i])
	{
		if (txt[i] == '%')
			i += ft_join_arg(&txt[i], argv, &to_print) + 1;
		else
			i += ft_join_txt(&txt[i], &to_print);
	}
	va_end(argv);
	count = ft_putstr(to_print);
	free (to_print);
	return (count);
}
