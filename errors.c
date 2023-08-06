/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:46:04 by jmiranda          #+#    #+#             */
/*   Updated: 2023/01/29 21:12:51 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_error(t_data *data)
{
	perror("Error\nIt wasn't able to read!");
	clear_data(data);
	exit (EXIT_FAILURE);
}

void	extension_error(t_data *data)
{
	perror("Error\nWrong extension! Try: ./so_long [Name].ber\n");
	clear_data(data);
	exit (EXIT_FAILURE);
}

void	argc_count_error(t_data *data)
{
	perror("Error\nWrong number of argc! Try: ./so_long [Name].ber\n");
	clear_data(data);
	exit (EXIT_FAILURE);
}

void	rectangular_error(t_data *data)
{
	perror("Error\nMap is not rectangular!\n");
	clear_data(data);
	exit (EXIT_FAILURE);
}

void	calloc_map_error(t_data *data)
{
	perror("Error\nCalloc map failed!\n");
	clear_data(data);
	exit (EXIT_FAILURE);
}
