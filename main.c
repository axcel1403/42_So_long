/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:57:51 by jmiranda          #+#    #+#             */
/*   Updated: 2023/02/17 22:05:20 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (data == NULL)
		data = ft_calloc(1, sizeof(t_data));
	if (!data)
	{
		perror("Error\nCalloc data failed!\n");
		exit (EXIT_FAILURE);
	}
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = get_data();
	if (parse_b4_init(data, argc, argv[1]) == 0)
	{
		get(data, argv[1]);
		check_parsing(data);
		data->mlx = mlx_init();
		data->win = mlx_new_window(data->mlx, data->width, data->height,
				"so_long");
		xpm_to_img(data);
		render_frame(data);
		mlx_hook(data->win, 2, 0, key_move, data);
		mlx_hook(data->win, 17, 0, manual_close_clear, data);
		mlx_loop(data->mlx);
	}
	perror("Error\nMlx_loop failed!\n");
	exit (EXIT_FAILURE);
}
