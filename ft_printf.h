/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snuts <snuts@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:31:41 by marvin            #+#    #+#             */
/*   Updated: 2021/11/09 22:29:34 by snuts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
int		ft_printf(char const *s, ...);
int		ft_putchar(char c);
int		ft_lennum(int nb);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putnbr_plus(unsigned int nb);
int		ft_len_10(long long x);
char	*f_ioa(int min, int count, int n, char *str);
int		ft_itoa(int n);
int		ft_lenu_10(long long int x);
char	*f_uioa(int min, int count, unsigned int n, char *str);
int		ft_uitoa(unsigned int n);
int		ft_pointer(unsigned long n);
int		ft_putnbr_base_upper(int nb);
int		ft_putnbr_base_lower(int n);
#endif