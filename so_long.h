/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:59:32 by jmiranda          #+#    #+#             */
/*   Updated: 2023/02/18 20:56:53 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define PX_SIZE 32
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_data {
	int		w;
	int		h;
	int		width;
	int		height;
	char	**map;

	int		c_count;
	int		p_count;
	int		e_count;
	int		p_x;
	int		p_y;
	char	**tmp_map;
	int		c_copy;
	int		exit_flag;

	void	*mlx;
	void	*win;
	void	*wall;
	void	*wall1;
	void	*floor;
	void	*collectable;
	void	*player;
	void	*exit;
	int		exit_walked;
	int		mv_cnt;
}			t_data;

t_data	*get_data(void);
void	clear_data(t_data *data);
int		parse_b4_init(t_data *data, int argc, char *argv);
void	read_error(t_data *data);
void	extension_error(t_data *data);
void	argc_count_error(t_data *data);
void	rectangular_error(t_data *data);
void	calloc_map_error(t_data *data);
void	invalid_char_error(t_data *data);
void	invalid_count_error(t_data *data);
void	walls_error(t_data *data);
void	tmp_map_malloc_error(t_data *data);
void	invalid_path_error(t_data *data);
void	get(t_data *data, char *argv);
void	get_map_size(t_data *data, char *argv);
void	get_map(t_data *data, char *argv);
void	get_all_count(t_data *data);
void	check_parsing(t_data *data);
void	check_valid_char_count(t_data *data);
void	check_walls(t_data *data);
char	**get_dup_map(char **map);
void	clear_map(char	***map);
void	check_flood_fill(t_data *data, int x, int y);
void	xpm_to_img(t_data *data);
void	render_frame(t_data *data);
void	render_images(t_data *data, char elem, int x, int y);
int		key_move(int keycode, t_data *data);
void	esc_key_clear(t_data *data);
void	player_move(int tmp_x, int tmp_y, t_data *data);
void	win_game_clear(t_data *data);
int		manual_close_clear(t_data *data);

#endif
