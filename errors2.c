/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:07:41 by jmiranda          #+#    #+#             */
/*   Updated: 2023/02/16 13:21:53 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_char_error(t_data *data)
{
	perror("Error\nInvalid char in the map!\n");
	clear_map(&data->map);
	clear_data(data);
	exit (EXIT_FAILURE);
}

void	invalid_count_error(t_data *data)
{
	perror("Error\nCollectable, Player or Exit count invalid!\n");
	clear_map(&data->map);
	clear_data(data);
	exit (EXIT_FAILURE);
}

void	walls_error(t_data *data)
{
	perror("Error\nWalls are not closed!");
	clear_map(&data->map);
	clear_data(data);
	exit (EXIT_FAILURE);
}

void	tmp_map_malloc_error(t_data *data)
{
	perror("Error\nMalloc tmp_map failed!\n");
	clear_map(&data->tmp_map);
	clear_map(&data->map);
	clear_data(data);
	exit (EXIT_FAILURE);
}

void	invalid_path_error(t_data *data)
{
	perror("Error\nInvalid Path! Collectibles and Exit need clear path\n");
	clear_map(&data->tmp_map);
	clear_map(&data->map);
	clear_data(data);
	exit (EXIT_FAILURE);
}
