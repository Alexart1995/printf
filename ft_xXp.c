/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xXp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snuts <snuts@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:10:00 by snuts             #+#    #+#             */
/*   Updated: 2021/11/09 22:30:55 by snuts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long n)
{
	char			*base;
	unsigned long	nb;
	int				i;

	nb = n;
	i = 0;
	base = "0123456789abcdef";
	if (nb < 0)
	{
		nb = nb * (-1);
		write(1, "-", 1);
		ft_pointer(nb);
	}
	else
	{
		if (nb >= 16)
			i = i + ft_pointer(nb / 16);
		i = i + ft_putchar(base[nb % 16]);
	}
	return (i);
}

int	ft_putnbr_base_upper(int nb)
{
	char				*base;
	int					i;
	unsigned int		n;

	n = nb;
	i = 0;
	base = "0123456789ABCDEF";
	if (n < 0)
	{
		n = n * (-1);
		write(1, "-", 1);
		ft_putnbr_base_upper(n);
	}
	else
	{
		if (n >= 16)
			i = i + ft_putnbr_base_upper(n / 16);
		i = i + ft_putchar(base[n % 16]);
	}
	return (i);
}

int	ft_putnbr_base_lower(int n)
{
	char			*base;
	unsigned int	nb;
	int				i;

	nb = n;
	i = 0;
	base = "0123456789abcdef";
	if (nb < 0)
	{
		nb = nb * (-1);
		write(1, "-", 1);
		ft_putnbr_base_lower(nb);
	}
	else
	{
		if (nb >= 16)
			i = i + ft_putnbr_base_lower(nb / 16);
		i = i + ft_putchar(base[nb % 16]);
	}
	return (i);
}

int	ft_lenu_10(long long int x)
{
	int	count;

	count = 1;
	while ((x / 10) != 0)
	{
		count++;
		x /= 10;
	}
	return (count);
}
