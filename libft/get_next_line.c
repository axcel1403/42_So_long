/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:40:10 by jmiranda          #+#    #+#             */
/*   Updated: 2023/02/15 22:41:08 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*if (*end == (sizeof(str) / BUFFER_SIZE) * BUFFER_SIZE)
{
	write(1, "Reached Static Buffer Limit", 27);
	break ;
}
*/

char	*ft_read_buff(int fd, char *line, int *nl, int *end)
{
	ssize_t		rd_ret;
	static char	str[100000000];

	while (str[*end] != '\0')
		(*end)++;
	while (ft_strchr_gnl(str, '\n', nl, end) == NULL)
	{
		rd_ret = read(fd, str + *end, BUFFER_SIZE);
		*end += rd_ret;
		if (rd_ret == -1)
		{
			str[0] = '\0';
			return (NULL);
		}
		if (rd_ret == 0)
			break ;
		str[*end] = '\0';
	}
	if (str[*nl] == '\n')
		(*nl)++;
	line = ft_strdup_gnl(str, nl);
	ft_memcpy_gnl(str, str + *nl, *end - *nl);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		end;
	int		nl;

	end = 0;
	nl = 0;
	line = NULL;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	line = ft_read_buff(fd, line, &nl, &end);
	if (!line)
		return (NULL);
	return (line);
}
