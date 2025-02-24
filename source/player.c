/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:07:54 by gnyssens          #+#    #+#             */
/*   Updated: 2025/02/24 20:04:38 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//in which row is 'N' (player)
int	which_row(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if ('N' == map[i][j])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	which_col(char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if ('N' == row[i])
			return (i);
		i++;
	}
	return (-1);
}

//incomplet, pr l'instant juste pos pr top-down
t_player	*init_player(t_mlx *data)
{
	t_player	*player;
	int			coord_player[2]; //[y][x]

	player = (t_player *)safe_malloc(sizeof(t_player));
	coord_player[0] = which_row(data->map);
	coord_player[1] = which_col(data->map[coord_player[0]]);
	player->x_pos = coord_player[1] + 0.5;
	player->y_pos = coord_player[0] + 0.5;
	player->dir_x = 0; //vers le Nord pr commencer
	player->dir_y = -1;
	return (player);
}

int	check_wall(t_mlx *data, float x, float y)
{
	int		cellsize = IMAGE_LENGTH / data->num_rows;
	int		round_x;
	int		round_y;
	int		xx;
	int		yy;
	int		num_rows = data->num_rows;

	round_x = (int) (x);
	round_y = (int) (y);
	if (round_x < 0 || round_x > num_rows * cellsize || round_y < WINDOW_HEIGHT - (data->num_rows * cellsize) || round_y > WINDOW_HEIGHT)
		return (0);

	xx = round_x / cellsize;
	yy = round_y / cellsize;
	if (xx < 0 || xx >= num_rows || yy < 0 || yy >= num_rows)
		return (0);
	if (data->map[yy][xx] != '0' && data->map[yy][xx] != 'N')
		return (0);
	return (1);
}
