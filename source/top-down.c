/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top-down.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:34:59 by gnyssens          #+#    #+#             */
/*   Updated: 2025/02/24 19:57:56 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_square(t_mlx *data, int x_start, int y_start, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (j == 0 || j == size - 1 || i == 0 || i == size - 1)
				my_mlx_pixel_put(data, x_start + j, y_start + i, GRAY);
			else
				my_mlx_pixel_put(data, x_start + j, y_start + i, color);
			j++;
		}
		i++;
	}	
}

void	draw_grid(t_mlx *data, int num_rows)
{
	int	cell_size;
	int	x;
	int	y;

	cell_size = IMAGE_HEIGHT / num_rows;
	y = WINDOW_HEIGHT - (num_rows * cell_size);
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < IMAGE_LENGTH)
		{
			if (x == 0 || x == num_rows * cell_size
				|| y ==  WINDOW_HEIGHT - (num_rows * cell_size) || y == WINDOW_HEIGHT - cell_size
				|| data->map[(y - (WINDOW_HEIGHT - (num_rows * cell_size))) / cell_size][(x / cell_size)] == '1')
				draw_square(data, x, y, cell_size, 0xEE0000);
			else
				draw_square(data, x, y, cell_size, 0xFFFFFF);
			x += cell_size;
		}
		y += cell_size;
	}
}

void	draw_player(t_mlx *data)
{
	int i_start;
	int	j_start;
	int	i;
	int	j;
	int	cellsize;

	cellsize = IMAGE_HEIGHT / data->num_rows;
	i_start = (data->player->y_pos * cellsize + WINDOW_HEIGHT - (data->num_rows * cellsize)) - 3;
	i = i_start;
	while (i < i_start + 4)
	{
		j_start = (data->player->x_pos * cellsize) - 3;
		j = j_start;
		while (j < j_start + 4)
		{
			my_mlx_pixel_put(data, j, i, 0X0033FF);
			j++;
		}
		i++;
	}
}

int	render(t_mlx *data)
{
    draw_grid(data, 10);  // 10 = NUMBER_ROWS hardcodée
	draw_player(data);
	draw_rays(data, data->player);
    mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);

	return (0);
}
