/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:25:39 by ddavlety          #+#    #+#             */
/*   Updated: 2023/11/23 12:56:53 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_void(size_t num)
{
	if (!num)
		return (ft_putstr_fd("(nil)", 1));
	return (ft_putstr_fd("0x", 1) + ft_putvoid(num, 1));
}

int	ft_print_param(char format, va_list argv)
{
	if (format == 'i' || format == 'd')
		return (ft_putnbr_fd(va_arg(argv, int), 1));
	if (format == 's')
		return (ft_putstr_fd(va_arg(argv, char *), 1));
	else if (format == 'u')
		return (ft_putunsnbr_fd(va_arg(argv, unsigned int), 1));
	else if (format == '\%')
		return (ft_putchar_fd('\%', 1));
	else if (format == 'c')
		return (ft_putchar_fd(va_arg(argv, int), 1));
	else if (format == 'p')
		return (ft_print_void(va_arg(argv, size_t)));
	else if (format == 'x')
		return (ft_putnbr_hex_fd(va_arg(argv, unsigned int), 1));
	else if (format == 'X')
		return (ft_putnbr_hexcap_fd(va_arg(argv, unsigned int), 1));
	return (0);
}

char	ft_params(const char *txt, char *set)
{
	int		i;

	while (*txt)
	{
		i = 0;
		while (set[i])
		{
			if (set[i] == *txt)
				return (set[i]);
			i++;
		}
		txt++;
	}
	return (0);
}

unsigned int	ft_aplflg(const char *txt, va_list argv)
{
	char	specif;

	specif = ft_params(txt, "cspdiuxX\%");
	return (ft_print_param(specif, argv));
}

int	ft_printf(const char *txt, ...)
{
	unsigned int	count;
	unsigned int	temp;
	va_list			argv;

	if (!txt)
		return (0);
	va_start(argv, txt);
	count = 0;
	while (*txt)
	{
		if (*txt == '%')
		{
			temp = ft_aplflg((txt + 1), argv);
			txt += 2;
			count += temp;
		}
		else
		{
			ft_putchar_fd(*txt, 1);
			txt++;
			count++;
		}
	}
	va_end(argv);
	return (count);
}

// #include <stdio.h>
// int main() {
//     // Test each format specifier
//     char c = 'A';
//     char *str = "Hello, World!";
//     int num = 42;
//     unsigned int uNum = 123;
//     // void *ptr = (void *)0x56b;

//     // Test %c
//     printf("Test %%c: %c\n%5c\n%-5c\n", c, c, c);
//     ft_printf("Test %%c: %c\n%c\n%c\n", c, c, c);

//     // Test %s
//     printf("Test %%s: %s\n", str);
//     ft_printf("Test %%s: %s\n", NULL);

//     // Test %p
//     printf("Test %%p: %p\n", NULL);
//     ft_printf("Test %%p: %p\n", NULL);

//     // Test %d and %i
//     printf("Test %%d and %%i: %d, %i\n", num, num);
//     ft_printf("Test %%d and %%i: %d, %i\n", num, num);

//     // Test %u
//     printf("Test %%u: %u\n", uNum);
//     ft_printf("Test %%u: %u\n", uNum);

//     // Test %x
//     printf("Test %%x: %x\n", uNum);
//     ft_printf("Test %%x: %x\n", uNum);

//     // Test %X
//     printf(" %X %X %lX %lX %lX %X %X\n", INT_MAX, INT_MIN, 9223372036854775807L, LONG_MIN, ULONG_MAX, 0, -42);
//     ft_printf(" %X %X %X %X %X %X %X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

//     // Test %%
//     printf("Test %%%%: %%\n");
//     ft_printf("Test %%%%: %%\n");

//     return 0;
// }
