/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:51:44 by rmakinen          #+#    #+#             */
/*   Updated: 2023/05/03 11:21:14 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	send_error()
{
	ft_printf("ERROR!\n");
	exit (1);
}

void	free_and_exit(t_parameters *so_long)
{
	int i;

	i = ft_strlen(*so_long->map);
	while (i > 0)
	{
		free (so_long->map[i]);
		i--;
	}
	free(so_long->map);
	free(so_long->map_str);
	exit (0);
}



void	exit_win(t_parameters *so_long)
{
	ft_printf("YAY! YAY! YAY! YOU W0N!");
	mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
	free_and_exit(so_long);
}
