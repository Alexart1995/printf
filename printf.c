/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snuts <snuts@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:23:47 by marvin            #+#    #+#             */
/*   Updated: 2021/11/09 22:52:56 by snuts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put(char const *s, int i, va_list param)
{
	int	num;

	if (s[i + 1] == 'c')
		num = ft_putchar(va_arg(param, int));
	else if (s[i + 1] == 's')
		num = ft_putstr(va_arg(param, char *));
	else if (s[i + 1] == 'd')
		num = ft_itoa(va_arg(param, int));
	else if (s[i + 1] == 'i')
		num = ft_itoa(va_arg(param, int));
	else if (s[i + 1] == 'u')
		num = ft_uitoa(va_arg(param, unsigned int));
	else if (s[i + 1] == 'X')
		num = ft_putnbr_base_upper(va_arg(param, int));
	else if (s[i + 1] == 'x')
		num = ft_putnbr_base_lower(va_arg(param, int));
	else if (s[i + 1] == 'p')
	{
		write(1, "0x", 2);
		num = ft_pointer(va_arg(param, unsigned long)) + 2;
	}
	else if (s[i + 1] == '%')
		num = ft_putchar('%');
	return (num);
}

int	ft_printf(char const *s, ...)
{
	va_list	param;
	int		i;
	int		num;

	i = 0;
	num = 0;
	va_start(param, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			num = num + ft_put(s, i, param);
			i++;
		}
		else
			num = num + ft_putchar(s[i]);
		i++;
	}
	va_end(param);
	return (num);
}
