/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 08:47:06 by rmakinen          #+#    #+#             */
/*   Updated: 2023/05/10 12:44:31 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_exit(t_parameters *so, int x, int y)
{
	so->map[y][x] = 'E';
	so->was_exit = 1;
}

void	up(t_parameters *so)
{
	int		x;
	int		y;
	char	*str;

	x = so->player_x;
	y = so->player_y;
	str = NULL;
	if (so->map[y - 1][x] == 'C' || so->map[y - 1][x] == '0' )
	{
		if (so->map[y - 1][x] == 'C')
			so->collect--;
		so->map[y - 1][x] = 'P';
		so->map[y][x] = '0';
		if (so->was_exit == 0)
			put_exit(so, x, y);
		so->count++;
		ft_printf("%i\n", so->count);
	}
	if (so->map[y - 1][x] == 'E')
	{
		move_ontop(so, x, y - 1, "up");
		check_end(so, x, y - 1);
	}
	draw_map(so);
}

void	down(t_parameters *so)
{
	int	x;
	int	y;

	x = so->player_x;
	y = so->player_y;
	if (so->map[y + 1][x] == 'C' || so->map[y + 1][x] == '0' )
	{
		if (so->map[y + 1][x] == 'C')
			so->collect--;
		so->map[y + 1][x] = 'P';
		so->map[y][x] = '0';
		if (so->was_exit == 0)
			put_exit(so, x, y);
		so->count++;
		ft_printf("%i\n", so->count);
	}
	if (so->map[y + 1][x] == 'E')
	{
		move_ontop(so, x, y + 1, "down");
		check_end(so, x, y + 1);
	}
	draw_map(so);
}

void	left(t_parameters *so)
{
	int	x;
	int	y;

	x = so->player_x;
	y = so->player_y;
	if (so->map[y][x - 1] == 'C' || so->map[y][x - 1] == '0' )
	{
		if (so->map[y][x - 1] == 'C')
			so->collect--;
		so->map[y][x - 1] = 'P';
		so->map[y][x] = '0';
		if (so->was_exit == 0)
			put_exit(so, x, y);
		so->count++;
		ft_printf("%i\n", so->count);
	}
	if (so->map[y][x - 1] == 'E')
	{
		move_ontop(so, x - 1, y, "left");
		check_end(so, x - 1, y);
	}
	draw_map(so);
}

void	right(t_parameters *so)
{
	int	x;
	int	y;

	x = so->player_x;
	y = so->player_y;
	if (so->map[y][x + 1] == 'C' || so->map[y][x + 1] == '0' )
	{
		if (so->map[y][x + 1] == 'C')
			so->collect--;
		so->map[y][x + 1] = 'P';
		so->map[y][x] = '0';
		if (so->was_exit == 0)
			put_exit(so, x, y);
		so->count++;
		ft_printf("%i\n", so->count);
	}
	if (so->map[y][x + 1] == 'E')
	{
		move_ontop(so, x + 1, y, "right");
		check_end(so, x + 1, y);
	}
	draw_map(so);
}
