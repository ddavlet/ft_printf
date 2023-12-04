/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:23:36 by ddavlety          #+#    #+#             */
/*   Updated: 2023/12/04 13:31:03 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int				ft_printf(const char *txt, ...);

size_t			ft_strlen(const char *s);

int				ft_isdigit(int c);

char			*chr_to_str(int c);

void			ft_charzero(void *s, unsigned long n);

char			*ft_print_void(unsigned long num, unsigned int *params);

char			*ft_itoa_hex(unsigned long i, char ulc);

char			*ft_itoa_ui(unsigned int i);

char			*int_prms_lgc(unsigned int	*params, char *arg, int format);

char			*str_prms_lgc(unsigned int	*params, char *arg, int format);

void			write_param(const char *param,
					unsigned int *params_set, char specifier);

void			write_int_param(const char *txt,
					unsigned int *params_set, int index, char specifier);

const char		*ft_params(const char *txt, char *set, char specifier);

unsigned int	*initialize_int(unsigned int *ptr, int i);

int				ft_putstr(char *s);

#endif
