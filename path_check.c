/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:27:03 by rmakinen          #+#    #+#             */
/*   Updated: 2023/05/02 11:51:25 by rmakinen         ###   ########.fr       */
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
				so_long->player_x = j;
				so_long->player_x = i;
		}
		i++;
	}
}

// int	check_path(t_parameters *so_long)
// {
// 	int x;
// 	int y;

// 	x = so_long->player_x;
// 	y = so_long->player_y;
// 	so_long->c_check = so_long->collect;
// 	so_long->m_check = so_long->map;
// 	//WE NEED A COPY OF THE MAP TO NOT TO DESTROY THE ORIGINAL;
// 	//should we have a
// 	while(so_long->m_check[y])
// 	{
// 		while()
// 		{
// 			if(so_long->m_check[y][x] == '0' || so_long->m_check[y][x] == 'C')
// 				// make it P -- check stuff around it -- make all of that P
// 				// too, if possible. At the end check if E & P are
// 				//next to each other & if all the coins are collected.
// 		}
// 		y++;
// 	}
// }
