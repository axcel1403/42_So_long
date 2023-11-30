/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:28:14 by jmiranda          #+#    #+#             */
/*   Updated: 2023/07/18 12:06:33 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_intlen(long n)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		n = n * -1;
		counter ++;
	}
	if (n == 0)
		return (counter + 1);
	while (n > 0)
	{
		n = n / 10;
		counter ++;
	}
	return (counter);
}

static	void	ft_neg(char *str, long *nbr)
{
	if (*nbr < 0)
	{
		*nbr = *nbr * -1;
		*(str + 0) = '-';
	}
}

char	*ft_itoa(int n)
{
	int		len;
	long	nbr;
	char	*str;

	nbr = n;
	len = ft_intlen(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nbr == 0)
	{
		*(str + 0) = '0';
		return (str);
	}
	if (nbr < 0)
	{
		ft_neg(str, &nbr);
	}
	while (nbr)
	{
		str[len--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}
