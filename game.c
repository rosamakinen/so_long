/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 08:47:06 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/29 13:55:04 by rmakinen         ###   ########.fr       */
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
	int i;
	int	x;
	int	y;

	i = 0;
	x = so_long->player_x;
	y = so_long->player_y;

	so_long->map[y - 1][x] = 'P';
	so_long->map[y][x] = '0';
		// 	while (so_long->map[i]) /// PRINTING THE MAP AGAIN!!!!!!
		// {
		// 	ft_printf("%s\n", so_long->map[i]);
		// 	i++;
		// }
	draw_map(so_long);
	ft_printf("testi");
}
void	down(t_parameters *so_long)
{
	int i;
	int	x;
	int	y;

	i = 0;
	x = so_long->player_x;
	y = so_long->player_y;
	so_long->map[y + 1][x] = 'P';
	so_long->map[y][x] = '0';
		// 	while (so_long->map[i]) /// PRINTING THE MAP AGAIN!!!!!!
		// {
		// 	ft_printf("%s\n", so_long->map[i]);
		// 	i++;
		// }
	draw_map(so_long);
	ft_printf("testi1");
}
void	left(t_parameters *so_long)
{
	int i;
	int	x;
	int	y;

	i = 0;
	x = so_long->player_x;
	y = so_long->player_y;
	so_long->map[y][x - 1] = 'P';
	so_long->map[y][x] = '0';
		// 	while (so_long->map[i]) /// PRINTING THE MAP AGAIN!!!!!!
		// {
		// 	ft_printf("%s\n", so_long->map[i]);
		// 	i++;
		// }
	draw_map(so_long);
	ft_printf("testi2");
}

void	right(t_parameters *so_long)
{
	int i;
	int	x;
	int	y;

	i = 0;
	x = so_long->player_x;
	y = so_long->player_y;
	so_long->map[y][x + 1] = 'P';
	so_long->map[y][x] = '0';
		// 	while (so_long->map[i]) /// PRINTING THE MAP AGAIN!!!!!!
		// {
		// 	ft_printf("%s\n", so_long->map[i]);
		// 	i++;
		// }
	draw_map(so_long);
	ft_printf("testi3");
}

