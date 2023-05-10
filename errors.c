/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:51:44 by rmakinen          #+#    #+#             */
/*   Updated: 2023/05/10 12:00:47 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	send_error(void)
{
	ft_printf("ERROR!\n");
	exit (1);
}

void	free_and_check(char *to_free, char *check)
{
	free(to_free);
	if (!check)
		exit (1);
}

int	exit_button(t_parameters *so)
{
	free_and_exit(so);
	return (0);
}

void	free_and_exit(t_parameters *so)
{
	mlx_destroy_window(so->mlx, so->win);
	exit (0);
}

void	exit_win(t_parameters *so)
{
	ft_printf("final steps: %i\n", so->count);
	ft_printf("YAY! YAY! YAY! YOU W0N!\n");
	free_and_exit(so);
}
