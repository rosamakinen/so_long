/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 08:47:06 by rmakinen          #+#    #+#             */
/*   Updated: 2023/05/03 11:18:49 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

//function to recieve the new coordinates
//check if there is something at the new spot for the player
//if there is C minus the collect from struct. -> move player there
//if there is 0 -> move player there
//if there is 1 -> player does not move, keep at previous coordinates
void	up(t_parameters *so_long)
{
	int	x;
	int	y;
	char *str;

	x = so_long->player_x;
	y = so_long->player_y;
	str = NULL;
	if (so_long->map[y - 1][x] == 'C' || so_long->map[y - 1][x] == '0' )
	{
		if (so_long->map[y - 1][x] == 'C')
			so_long->collect--;
		so_long->map[y - 1][x] = 'P';
		so_long->map[y][x] = '0';
		so_long->count++;
		ft_printf("%i\n", so_long->count);
	}
	if (so_long->map[y - 1][x] == 'E')
		check_end(so_long);
	draw_map(so_long);
}
void	down(t_parameters *so_long)
{
	int	x;
	int	y;

	x = so_long->player_x;
	y = so_long->player_y;
	if (so_long->map[y + 1][x] == 'C' || so_long->map[y + 1][x] == '0' )
	{
		if (so_long->map[y + 1][x] == 'C')
			so_long->collect--;
		so_long->map[y + 1][x] = 'P';
		so_long->map[y][x] = '0';
		so_long->count++;
		ft_printf("%i\n", so_long->count);
	}
	if (so_long->map[y + 1][x] == 'E')
		check_end(so_long);
	draw_map(so_long);

}
void	left(t_parameters *so_long)
{
	int	x;
	int	y;


	x = so_long->player_x;
	y = so_long->player_y;
	if (so_long->map[y][x - 1] == 'C' || so_long->map[y][x - 1] == '0' )
	{
		if (so_long->map[y][x - 1] == 'C')
			so_long->collect--;
		so_long->map[y][x - 1] = 'P';
		so_long->map[y][x] = '0';
		so_long->count++;
		ft_printf("%i\n", so_long->count);
		ft_printf("c: %i\n", so_long->collect);
	}
	if (so_long->map[y][x - 1] == 'E')
		check_end(so_long);
	draw_map(so_long);
}

void	right(t_parameters *so_long)
{
	int	x;
	int	y;

	x = so_long->player_x;
	y = so_long->player_y;
	if (so_long->map[y][x + 1] == 'C' || so_long->map[y][x + 1] == '0' )
	{
		if (so_long->map[y][x + 1] == 'C')
			so_long->collect--;
		so_long->map[y][x + 1] = 'P';
		so_long->map[y][x] = '0';
		so_long->count++;
		ft_printf("%i\n", so_long->count);
		ft_printf("c: %i\n", so_long->collect);
	}
	if (so_long->map[y][x + 1] == 'E')
		check_end(so_long);
	draw_map(so_long);
}

void	check_end(t_parameters *so_long)
{
	 if (so_long->collect == 0)
		exit_win(so_long);
}
