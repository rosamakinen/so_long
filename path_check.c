/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:27:03 by rmakinen          #+#    #+#             */
/*   Updated: 2023/05/08 15:44:07 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	start_position(t_parameters *so_long)
{
	int i;
	int j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while(so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'P')
			{
				so_long->player_x = j;
				so_long->player_y = i;
			}
			j++;
		}
		i++;
	}
}

// int	check_exit(t_parameters *so_long)
// {
// 	int x;
// 	int y;

// 	y = 0;
// 	while(so_long->m_check[y])
// 	{
// 		while (so_long->m_check[y][x])
// 		{
// 			if (so_long->m_check[y][x] == 'E')
// 				if (so_long->m_check[y + 1][x] == 'P')
// 			x++;
// 		}
// 		y++;
// 	}
// }

int	check_path(t_parameters *so_long)
{
	int y;
	int x;
	y = 0;
	ft_printf("map check 9\n");
	start_position(so_long);
	check_path2(so_long);
	ft_printf("map check 10\n");
	while(so_long->m_check[y])
	{
		x = 0;
		ft_printf("%c", so_long->m_check[y][x]);
		while(so_long->m_check[y][x] != 'C')
		{
			if (so_long->m_check[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	//check_exit(so_long);
	return (0);
}

void	check_path2(t_parameters *so_long)
{
	int x;
	int y;
	int i;

	ft_printf("player x %i\n", so_long->player_x);
	ft_printf("player y %i\n", so_long->player_y);
	x = so_long->player_x;
	y = so_long->player_y;
	i = 0;
	while (so_long->m_check[i])
	{
		ft_printf("%s\n", so_long->m_check[i]);
		i++;
	}
	if (so_long->m_check[y + 1][x] == '0' || so_long->m_check[y + 1][x] == 'C')
	{
		so_long->m_check[y + 1][x] = 'P';
		so_long->player_x = x;
		so_long->player_y = y + 1;
		check_path2(so_long);
	}
	if (so_long->m_check[y][x + 1] == '0' || so_long->m_check[y][x + 1] == 'C')
	{
		so_long->m_check[y][x + 1] = 'P';
		so_long->player_x = x + 1;
		so_long->player_y = y;
		check_path2(so_long);
	}
	if (so_long->m_check[y - 1][x] == '0' || so_long->m_check[y - 1][x] == 'C')
	{
		so_long->m_check[y - 1][x] = 'P';
		so_long->player_x = x;
		so_long->player_y = y - 1;
		check_path2(so_long);
	}
	if (so_long->m_check[y][x - 1] == '0' || so_long->m_check[y][x - 1] == 'C')
	{
		so_long->m_check[y][x - 1] = 'P';
		so_long->player_x = x - 1;
		so_long->player_y = y;
		check_path2(so_long);
	}
}

// int	check_path_x(t_parameters *so_long)
// {
// 	int x;
// 	int y;

// 	x = so_long->player_x;
// 	y = so_long->player_y;
// 	so_long->c_check = so_long->collect;
// 	so_long->m_check = so_long->map;
// 	if (so_long->m_check[y][x + 1] == '0' || so_long->m_check[y][x + 1] == 'C')
// 	{
// 		if (so_long->m_check[y][x + 1] == 'C')
// 			so_long->c_check--;
// 		so_long->m_check[y + 1][x] == 'P';
// 		check_path(so_long);
// 		check_path_x(so_long);
// 	}
// 	if (so_long->m_check[y - 1][x] == '0' || so_long->m_check[y - 1][x] == 'C')
// 	{
// 		if (so_long->m_check[y - 1][x] == 'C')
// 			so_long->c_check--;
// 		so_long->m_check[y - 1][x] == 'P';
// 		check_path(so_long);
// 		check_path_x(so_long);
// 	}
// }

// int	check_path(t_parameters *so_long)
// {
// 	int x;
// 	int y;


// 	y = 0;
// 	c = 1;
// 	so_long->c_check = so_long->collect;
// 	so_long->m_check = so_long->map;
// 	while(so_long->m_check[y])
// 	{
// 		x = 0;
// 		ft_printf("\n"); //PRINTING SOMETHING
// 		while(so_long->m_check[y][x])
// 		{
// 			ft_printf("%c", so_long->m_check[y][x]); //PRINTING SOMETHING
// 			if(so_long->m_check[y][x] == 'P')
// 				c = path_checktrough(so_long, x, y);
// 			x++;
// 		}
// 		y++;
// 	}
// 	if (c == 0)
// 		return (0);
// 	return (1);
// }

// int	path_checktrough(t_parameters *so_long, int x, int y)
// {
// 	int c;

// 	check_surroundings_y(so_long, x, y);
// 	check_surroundings_x(so_long, x, y);
// 	c = check_exit(so_long, x, y);
// 	if (c == 0 && so_long->c_check == 0)
// 		return (0);
// 	return (1);
// }

// int check_exit(t_parameters *so_long, int x, int y)
// {
// 	if (so_long->m_check[x][y] == 'E')
// 	{
// 		if (so_long->m_check[y + 1][x] == 'P'
// 		|| so_long->m_check[y - 1][x] == 'P'
// 		|| so_long->m_check[y][x + 1] == 'P'
// 		|| so_long->m_check[y][x - 1] == 'P')
// 			return (0);
// 	}
// 	return (1);
// }

// void	check_surroundings_y(t_parameters *so_long, int x, int y)
// {
// 	if (so_long->m_check[y + 1][x] == '0' || so_long->m_check[y + 1][x] == 'C')
// 	{
// 		if (so_long->m_check[y + 1][x] == 'C')
// 			so_long->c_check--;
// 		so_long->m_check[y + 1][x] = 'P';
// 	}
// 	if (so_long->m_check[y - 1][x] == '0' || so_long->m_check[y - 1][x] == 'C')
// 	{
// 		if (so_long->m_check[y - 1][x] == 'C')
// 			so_long->c_check--;
// 		so_long->m_check[y - 1][x] = 'P';
// 	}
// }

// void	check_surroundings_x(t_parameters *so_long, int x, int y)
// {
// 		if (so_long->m_check[y][x + 1] == '0' || so_long->m_check[y][x + 1] == 'C')
// 	{
// 		if (so_long->m_check[y][x + 1] == 'C')
// 			so_long->c_check--;
// 		so_long->m_check[y][x + 1] = 'P';
// 	}
// 	if (so_long->m_check[y][x - 1] == '0' || so_long->m_check[y][x - 1] == 'C')
// 	{
// 		if (so_long->m_check[y][x - 1] == 'C')
// 			so_long->c_check--;
// 		so_long->m_check[y][x - 1] = 'P';
// 	}

// }
