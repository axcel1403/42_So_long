/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:47:15 by jmiranda          #+#    #+#             */
/*   Updated: 2023/07/18 12:06:05 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_game_clear(t_data *data)
{
	clear_map(&data->map);
	clear_data(data);
	printf("You Made It!\n");
	exit (EXIT_SUCCESS);
}

int	manual_close_clear(t_data *data)
{
	clear_map(&data->map);
	clear_data(data);
	printf("Window Closed!\n");
	exit (EXIT_SUCCESS);
}

void	esc_key_clear(t_data *data)
{
	clear_map(&data->map);
	clear_data(data);
	printf("Window Closed With Esc!\n");
	exit (EXIT_SUCCESS);
}

void	clear_data(t_data *data)
{
	if (!data)
		return ;
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->wall1)
		mlx_destroy_image(data->mlx, data->wall1);
	if (data->floor)
		mlx_destroy_image(data->mlx, data->floor);
	if (data->collectable)
		mlx_destroy_image(data->mlx, data->collectable);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	free(data);
	data = NULL;
}

void	clear_map(char	***map_p)
{
	char	**map;
	int		i;

	if (!map_p || !*map_p)
		return ;
	map = *map_p;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(*map_p);
	*map_p = NULL;
}
