/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:29:45 by jmiranda          #+#    #+#             */
/*   Updated: 2023/07/18 12:22:59 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	char	**no_memory_leaks(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	return (NULL);
}

static	int	ft_n_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] && (s[i] == c))
			i++;
		while (s[i] && (s[i] != c))
			i++;
		if (s[i - 1] != c)
			words++;
	}
	return (words);
}

static	char	**ft_words_spliter(char **tab, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			while (s[i + j] && s[i + j] != c)
				j++;
			tab[k] = ft_substr(s, i, j);
			if (!tab[k])
				return (no_memory_leaks(tab));
			k++;
		}
		i += j;
	}
	tab[k] = NULL;
	return (tab);
}

char	**ft_split(char	const *s, char c)
{
	char	**tab;
	int		n_words;

	if (!s)
		return (NULL);
	n_words = ft_n_words(s, c);
	tab = malloc(sizeof(char *) * (n_words + 1));
	if (!tab)
		return (NULL);
	tab = ft_words_spliter(tab, s, c);
	return (tab);
}
