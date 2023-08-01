/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:02:21 by jmiranda          #+#    #+#             */
/*   Updated: 2023/02/17 21:29:05 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_b4_init(t_data *data, int argc, char *argv)
{
	int	fd;
	int	i;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		read_error(data);
	close(fd);
	if (argc == 2 && argv != NULL)
	{
		i = ft_strlen(argv) - 4;
		if (ft_strncmp(&argv[i], ".ber", 4) != 0)
			extension_error(data);
		else
			return (0);
	}
	else
		argc_count_error(data);
	return (1);
}

void	check_valid_char_count(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->h)
	{
		x = -1;
		while (++x < data->w)
		{
			if (data->map[y][x] == 'C' || data->map[y][x] == 'P'
				|| data->map[y][x] == 'E' || data->map[y][x] == '1'
				|| data->map[y][x] == '0' || data->map[y][x] == '\n')
				continue ;
			else
				invalid_char_error(data);
		}
	}
	if ((data->c_count < 1) || (data->p_count != 1)
		|| (data->e_count != 1))
		invalid_count_error(data);
}

void	check_walls(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->h)
	{
		x = -1;
		while (++x < data->w)
		{
			if (data->map[0][x] != '1' || data->map[data->h - 1][x] != '1')
				walls_error(data);
		}
		if (data->map[y][0] != '1' || data->map[y][data->w - 1] != '1')
			walls_error(data);
	}
}

void	check_flood_fill(t_data *data, int x, int y)
{
	if (data->tmp_map[y][x] == '0' || data->tmp_map[y][x] == 'C'
		|| data->tmp_map[y][x] == 'P' || data->tmp_map[y][x] == 'E')
	{
		if (data->tmp_map[y][x] == 'C')
			data->c_copy++;
		if (data->tmp_map[y][x] == 'E')
			data->exit_flag = 1;
		data->tmp_map[y][x] = 'A';
		check_flood_fill(data, x + 1, y);
		check_flood_fill(data, x - 1, y);
		check_flood_fill(data, x, y + 1);
		check_flood_fill(data, x, y - 1);
	}
}

void	check_parsing(t_data *data)
{
	check_valid_char_count(data);
	check_walls(data);
	data->tmp_map = get_dup_map(data->map);
	if (data->tmp_map == NULL)
		tmp_map_malloc_error(data);
	check_flood_fill(data, data->p_x, data->p_y);
	if (data->c_copy != data->c_count || data->exit_flag != 1)
		invalid_path_error(data);
	clear_map(&data->tmp_map);
}
