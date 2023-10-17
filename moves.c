/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:17:08 by jmiranda          #+#    #+#             */
/*   Updated: 2023/02/18 23:44:31 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	animation(int keycode, t_data *data)
{
	void	*tmp;

	if (keycode == 12)
	{
		tmp = data->wall;
		data->wall = data->wall1;
		data->wall1 = tmp;
		render_frame(data);
	}
}

void	player_move(int tmp_x, int tmp_y, t_data *data)
{
	if (data->map[data->p_y + tmp_y][data->p_x + tmp_x] != '1')
	{
		if (data->map[data->p_y + tmp_y][data->p_x + tmp_x] == 'E' &&
			data->c_count == 0)
			win_game_clear(data);
		if (data->map[data->p_y + tmp_y][data->p_x + tmp_x] == 'E' &&
			data->c_count != 0)
			data->exit_walked = 1;
		if (data->map[data->p_y + tmp_y][data->p_x + tmp_x] == 'C')
			data->c_count--;
		data->map[data->p_y][data->p_x] = '0';
		if ((data->exit_walked == 1) && (data->map[data->p_y + tmp_y]
				[data->p_x + tmp_x] != 'E'))
		{
			data->map[data->p_y][data->p_x] = 'E';
			data->exit_walked = 0;
		}
		data->map[data->p_y + tmp_y][data->p_x + tmp_x] = 'P';
		data->p_x += tmp_x;
		data->p_y += tmp_y;
		data->mv_cnt++;
		printf("Nb of moves: %d\n", data->mv_cnt);
	}
}

int	key_move(int keycode, t_data *data)
{
	if (keycode == 53)
		esc_key_clear(data);
	else if (keycode == 13)
	{
		player_move(0, -1, data);
		render_frame(data);
	}
	else if (keycode == 2)
	{
		player_move(1, 0, data);
		render_frame(data);
	}
	else if (keycode == 1)
	{
		player_move(0, 1, data);
		render_frame(data);
	}
	else if (keycode == 0)
	{
		player_move(-1, 0, data);
		render_frame(data);
	}
	animation(keycode, data);
	return (0);
}
