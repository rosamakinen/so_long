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

int	key_event(int keycode, t_parameters *so_long)
{
	int i; ///REMOVE
	int	x;
	int	y;
	i = 0; ///REMOVE
	x = so_long->player_x;
	y = so_long->player_y;
	if (keycode == 53)
		free_and_exit(so_long);
	else if (keycode == 13 || keycode == 126) //GO_UP (y--) maybe instead of changing the position of the player change the map??
		up(so_long);
	else if (keycode == 1 || keycode == 125) //GO_DOWN (y++)
		down(so_long);
	else if (keycode == 0 || keycode == 123) //GO_LEFT (x--)ç
		left(so_long);
	else if (keycode == 2 || keycode == 124) //GO_RIGHT (x++)
		right(so_long);
	while (so_long->map[i]) /// PRINTING THE MAP AGAIN!!!!!!
	{
		ft_printf("%s\n", so_long->map[i]);
		i++;
	}
	ft_printf("jaahas_key3\n");
	return (0);
}

void	place_tile(t_sprite *sprite, t_parameters *so_long, int x, int y)
{
	if (so_long->map[y][x] == '0')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, sprite->empty, (x * S_WIDTH), (y * S_HEIGHT));
	if (so_long->map[y][x] == '1')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, sprite->wall, (x * S_WIDTH), (y * S_HEIGHT));
	if (so_long->map[y][x] == 'P')
	{
		so_long->player_x = x;
		so_long->player_y = y;
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, sprite->empty, (x * S_WIDTH), (y * S_HEIGHT));
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, sprite->player, (x * S_WIDTH), (y * S_HEIGHT));
	}
	if (so_long->map[y][x] == 'C')
	{
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, sprite->empty, (x * S_WIDTH), (y * S_HEIGHT));
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, sprite->collect, (x * S_WIDTH), (y * S_HEIGHT));
	}
	if (so_long->map[y][x] == 'E')
	{
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, sprite->empty, (x * S_WIDTH), (y * S_HEIGHT));
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, sprite->exit, (x * S_WIDTH), (y * S_HEIGHT));
	}
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

void	draw_map(t_parameters *so_long)
{
	int x;
	int y;
	t_sprite sprite;

	y = 0;
	init_tiles(&sprite, so_long);
	while (so_long->map[y])
	{
		x = 0;
		while (so_long->map[y][x])
		{
			place_tile(&sprite, so_long, x, y);
			x++;
		}
	y++;
	}
}

void	window_handle(t_parameters *so_long)
{
	ft_printf("w: %i, h: %i", so_long->width, so_long->height);
	so_long->mlx_ptr = mlx_init();
	so_long->win_ptr = mlx_new_window(so_long->mlx_ptr, so_long->width * 47, so_long->height * 47, "test_window");
	so_long->count = 0;

	draw_map(so_long);
	mlx_hook(so_long->win_ptr, 2, 1L<<0, key_event, so_long);
	mlx_loop(so_long->mlx_ptr);
}
