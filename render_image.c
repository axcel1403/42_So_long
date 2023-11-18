/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:24:55 by jmiranda          #+#    #+#             */
/*   Updated: 2023/02/18 21:00:24 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_img(t_data *data)
{
	int		w;
	int		h;
	char	*path;

	path = "./img/wall.xpm";
	data->wall = mlx_xpm_file_to_image (data->mlx, path, &w, &h);
	path = "./img/wall1.xpm";
	data->wall1 = mlx_xpm_file_to_image (data->mlx, path, &w, &h);
	path = "./img/floor.xpm";
	data->floor = mlx_xpm_file_to_image (data->mlx, path, &w, &h);
	path = "./img/coin.xpm";
	data->collectable = mlx_xpm_file_to_image (data->mlx, path, &w, &h);
	path = "./img/player.xpm";
	data->player = mlx_xpm_file_to_image (data->mlx, path, &w, &h);
	path = "./img/exit.xpm";
	data->exit = mlx_xpm_file_to_image (data->mlx, path, &w, &h);
}

static	void	move_on_screen(t_data *data)
{
	char	*nb_mv;

	nb_mv = ft_itoa(data->mv_cnt);
	mlx_string_put(data->mlx, data->win, 0, 0, 0x00FFFFFF, nb_mv);
	free(nb_mv);
}

void	render_images(t_data *data, char elem, int x, int y)
{
	if (elem == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, x, y);
	if (elem == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
	if (elem == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
		mlx_put_image_to_window(data->mlx, data->win, data->collectable, x, y);
	}
	if (elem == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
		mlx_put_image_to_window(data->mlx, data->win, data->player, x, y);
	}
	if (elem == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
		mlx_put_image_to_window(data->mlx, data->win, data->exit, x, y);
	}
	move_on_screen(data);
}

void	render_frame(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->h)
	{
		x = -1;
		while (++x < data->w)
			render_images(data, data->map[y][x],
				x * PX_SIZE, y * PX_SIZE);
	}
}
