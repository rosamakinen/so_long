/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handle->c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 07:52:28 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/25 14:41:50 by rmakinen         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */


#include "test.h"

// void	window_size(t_parameters *so_long)
// {
// 	size_t len;

// 	len = ft_strlen(so_long->map[0]);
// 	so_long->w_width = ft_strlen(so_long->map[0][0] * S_WIDTH);
// 	so_long->w_width = ft_strlen(len * S_HEIGHT);

// }

void	place_tile(t_sprite *sprite, t_parameters *so_long, int x, int y)
{
	if (so_long->map[y][x] == '0')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, sprite->empty, (x * 46), (y * 46));
	if (so_long->map[y][x] == 'P')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, sprite->player, (x * 46), (y * 46));
	if (so_long->map[y][x] == 'C')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, sprite->collect, (x * 46), (y * 46));
	if (so_long->map[y][x] == '1')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, sprite->wall, (x * 46), (y * 46));
	if (so_long->map[y][x] == 'E')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, sprite->exit, (x * 46), (y * 46));
}

void	init_tiles(t_sprite *sprite, t_parameters *so_long)
{
	sprite->s_width = S_WIDTH;
	sprite->s_height = S_HEIGHT;
	sprite->empty = mlx_xpm_file_to_image(so_long->mlx_ptr, EMPTY, &sprite->s_width, &sprite->s_height);
	sprite->player = mlx_xpm_file_to_image(so_long->mlx_ptr, PLAYER, &sprite->s_width, &sprite->s_height);
	sprite->collect = mlx_xpm_file_to_image(so_long->mlx_ptr, COLLECT, &sprite->s_width, &sprite->s_height);
	sprite->wall = mlx_xpm_file_to_image(so_long->mlx_ptr, WALL, &sprite->s_width, &sprite->s_height);
	sprite->exit = mlx_xpm_file_to_image(so_long->mlx_ptr, EXIT, &sprite->s_width, &sprite->s_height);
}

void	draw_map(t_parameters *so_long, t_sprite *sprite)
{
	int x;
	int y;

	y = 0;
	init_tiles(sprite, so_long);
	while (so_long->map[y])
	{
		x = 0;
		while (so_long->map[x])
		{
			place_tile(sprite, so_long, x, y);
			x++;
		}
	y++;
	}
}

void	window_handle(t_parameters *so_long)
{
	t_sprite sprite;

	//window_size(so_long);
	so_long->mlx_ptr = mlx_init();
	so_long->win_ptr = mlx_new_window(so_long->mlx_ptr, 700, 700, "test_window");

	ft_printf("jaahas");
	draw_map(so_long, &sprite);
	mlx_loop(so_long->mlx_ptr);
	ft_printf("if you can see this you probably have a window, yay!");
}
