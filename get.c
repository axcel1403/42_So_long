/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:51:28 by jmiranda          #+#    #+#             */
/*   Updated: 2023/03/11 18:05:02 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_size(t_data *data, char *argv)
{
	int		fd;
	char	*row;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		read_error(data);
	row = get_next_line(fd);
	if (!row || !row[0] || row[0] == '\n')
		read_error(data);
	data->h = 0;
	data->w = (int)(ft_strlen(row) - (row[ft_strlen(row) - 1] == '\n'));
	while (row != NULL)
	{
		if (data->w != (int)(ft_strlen(row)
			- (row[ft_strlen(row) - 1] == '\n')))
			rectangular_error(data);
		data->h++;
		free(row);
		row = get_next_line(fd);
	}
	data->height = data->h * PX_SIZE;
	data->width = data->w * PX_SIZE;
	free(row);
	close(fd);
}

void	get_map(t_data *data, char *argv)
{
	int		i;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		read_error(data);
	data->map = ft_calloc(data->h + 1, sizeof(char *));
	if (!data->map)
		calloc_map_error(data);
	i = 0;
	while (i < data->h)
	{
		data->map[i++] = get_next_line(fd);
	}
	data->map[i] = NULL;
	close (fd);
}

void	get_all_count(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->h)
	{
		x = -1;
		while (++x < data->w)
		{
			data->c_count += (data->map[y][x] == 'C');
			data->e_count += (data->map[y][x] == 'E');
			if (data->map[y][x] == 'P')
			{
				data->p_count++;
				data->p_x = x;
				data->p_y = y;
			}
		}
	}
}

char	**get_dup_map(char **map)
{
	char	**tmp_map;
	int		i;

	if (!map || !map[0])
		return (NULL);
	i = 0;
	while (map[i])
		i++;
	tmp_map = malloc(sizeof(char *) * (i + 1));
	if (!tmp_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		tmp_map[i] = ft_strdup(map[i]);
		if (!tmp_map[i])
			return (NULL);
		i++;
	}
	tmp_map[i] = NULL;
	return (tmp_map);
}

void	get(t_data *data, char *argv)
{
	get_map_size(data, argv);
	get_map(data, argv);
	get_all_count(data);
}
