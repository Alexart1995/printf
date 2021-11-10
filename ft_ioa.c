/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ioa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snuts <snuts@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:06:53 by snuts             #+#    #+#             */
/*   Updated: 2021/11/09 22:28:44 by snuts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_10(long long x)
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

char	*f_ioa(int min, int count, int n, char *str)
{
	if (min == -1)
	{
		while (count >= 1)
		{
			str[count] = ((-1) * (long long)n % 10) + '0';
			count --;
			n /= 10;
		}
		str[count] = '-';
		return (str);
	}
	else if (min == 1)
	{
		while (count >= 0)
		{
			str[count] = ((long long)n % 10) + 48;
			count --;
			n /= 10;
		}
		return (str);
	}
	return (NULL);
}

int	ft_itoa(int n)
{
	int			min;
	long long	x;
	int			count;
	char		*str;
	int			l;

	min = 1;
	x = (long long) n;
	count = ft_len_10 (x);
	if (n < 0)
	{
		count++;
		min = -1;
	}
	str = (char *) malloc (sizeof(char) * (count + 1));
	str[count] = '\0';
	count --;
	l = ft_putstr(f_ioa(min, count, n, str));
	free (str);
	return (l);
}

char	*f_uioa(int min, int count, unsigned int n, char *str)
{
	if (min == -1)
	{
		while (count >= 1)
		{
			str[count] = ((-1) * (unsigned int)n % 10) + '0';
			count --;
			n /= 10;
		}
		str[count] = '-';
		return (str);
	}
	if (min == 1)
	{
		while (count >= 0)
		{
			str[count] = ((unsigned int)n % 10) + 48;
			count --;
			n /= 10;
		}
		return (str);
	}
	return (NULL);
}

int	ft_uitoa(unsigned int n)
{
	int				min;
	unsigned int	x;
	int				count;
	char			*str;
	int				l;

	min = 1;
	x = n;
	count = ft_lenu_10 (x);
	if (n < 0)
	{
		count++;
		min = -1;
	}
	str = (char *) malloc (sizeof(char) * (count + 1));
	str[count] = '\0';
	count --;
	l = ft_putstr(f_uioa(min, count, n, str));
	free (str);
	return (l);
}
