/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:28:37 by rmakinen          #+#    #+#             */
/*   Updated: 2023/05/09 14:52:47 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_tile2(t_parameters *so, int x, int y, char c)
{
	if (c == 'C')
	{
		mlx_put_image_to_window(so->mlx, so->win, so->p_em, \
		(x * S_W), (y * S_H));
		mlx_put_image_to_window(so->mlx, so->win, so->p_co, \
		(x * S_W), (y * S_H));
	}
	if (c == 'E')
	{
		mlx_put_image_to_window(so->mlx, so->win, so->p_em, \
		(x * S_W), (y * S_H));
		mlx_put_image_to_window(so->mlx, so->win, so->p_exit, \
		(x * S_W), (y * S_H));
	}
}

void	place_tile(t_parameters *so, int x, int y)
{
	if (so->map[y][x] == '0')
		mlx_put_image_to_window(so->mlx, so->win, so->p_em, \
		(x * S_W), (y * S_H));
	if (so->map[y][x] == '1')
		mlx_put_image_to_window(so->mlx, so->win, so->p_wall, \
		(x * S_W), (y * S_H));
	if (so->map[y][x] == 'P')
	{
		so->player_x = x;
		so->player_y = y;
		mlx_put_image_to_window(so->mlx, so->win, so->p_em, \
		(x * S_W), (y * S_H));
		mlx_put_image_to_window(so->mlx, so->win, so->p_pl, \
		(x * S_W), (y * S_H));
	}
	if (so->map[y][x] == 'C')
		place_tile2(so, x, y, 'C');
	if (so->map[y][x] == 'E')
		place_tile2(so, x, y, 'E');
}

void	init_tiles(t_parameters *so)
{
	so->s_w = S_W;
	so->s_w = S_H;
	so->p_em = mlx_xpm_file_to_image(so->mlx, EMPTY, &so->s_w, &so->s_h);
	so->p_pl = mlx_xpm_file_to_image(so->mlx, PLAYER, &so->s_w, &so->s_h);
	so->p_co = mlx_xpm_file_to_image(so->mlx, COLLECT, &so->s_w, &so->s_h);
	so->p_wall = mlx_xpm_file_to_image(so->mlx, WALL, &so->s_w, &so->s_h);
	so->p_exit = mlx_xpm_file_to_image(so->mlx, EXIT, &so->s_w, &so->s_h);
}

void	draw_map(t_parameters *so)
{
	int	x;
	int	y;

	y = 0;
	init_tiles(so);
	while (so->map[y])
	{
		x = 0;
		while (so->map[y][x])
		{
			place_tile(so, x, y);
			x++;
		}
	y++;
	}
}

void	window_handle(t_parameters *so)
{
	so->mlx = mlx_init();
	so->win = mlx_new_window(so->mlx, so->width * 47, so->height * 47, \
	"test_window");
	so->count = 0;
	draw_map(so);
	mlx_hook(so->win, 2, 1L << 0, &key_event, so);
	mlx_hook(so->win, 17, 1L << 17, &exit_button, so);
	mlx_loop(so->mlx);
}
