/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:23:36 by ddavlety          #+#    #+#             */
/*   Updated: 2023/11/22 15:58:26 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *txt, ...);

int		ft_putstr_fd(char *s, int fd);

int		ft_putnbr_fd(int n, int fd);

int		ft_putchar_fd(char c, int fd);

int		ft_putunsnbr_fd(unsigned int n, int fd);

size_t	ft_strlen(const char *s);

int		ft_isdigit(int c);

int		ft_putnbr_hex_fd(unsigned int data, int fd);

int		ft_putnbr_hexcap_fd(unsigned int data, int fd);

char	*ft_strdup(const char *s);

#endif
