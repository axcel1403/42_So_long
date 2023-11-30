/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:22:01 by jmiranda          #+#    #+#             */
/*   Updated: 2022/05/12 20:50:16 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*(haystack + i) != '\0' && (i < len))
	{
		j = 0;
		while ((*(haystack + i + j) == *(needle + j)) && *(needle + j) != '\0'
			&& *(haystack + i + j) != '\0' && (i + j < len))
		{
			j++;
			if (*(needle + j) == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
