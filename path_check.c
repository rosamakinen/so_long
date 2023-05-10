/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:27:03 by rmakinen          #+#    #+#             */
/*   Updated: 2023/05/10 12:45:38 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_width(t_parameters *so)
{
	int	i;

	i = 0;
	so->width = ft_strlen(so->map[0]);
	while (so->map[i])
	{
		i++;
	}
	so->height = i;
}

void	start_position(t_parameters *so)
{
	int	i;
	int	j;

	i = 0;
	while (so->map[i])
	{
		j = 0;
		while (so->map[i][j])
		{
			if (so->map[i][j] == 'P')
			{
				so->player_x = j;
				so->player_y = i;
			}
			j++;
		}
		i++;
	}
}

int	check_path(t_parameters *so, int error, int x, int y)
{
	if (so->reach == 1 && so->c_check == so->collect)
		return (error);
	if (so->m_check[y][x] == 'E')
		so->reach = 1;
	if (so->m_check[y][x] == 'E' || so->m_check[y][x] == 'P'
	|| so->m_check[y][x] == 'C' || so->m_check[y][x] == '0')
	{
		if (so->m_check[y][x] == 'C')
			so->c_check = so->c_check + 1;
		so->m_check[y][x] = 'x';
		if (y > 0)
			if (so->m_check[y - 1][x] != '1')
				check_path(so, 0, x, y - 1);
		if (x < so->width - 1)
			if (so->m_check[y][x + 1] != '1')
				check_path(so, 0, x + 1, y);
		if (y < so->height - 1)
			if (so->m_check[y + 1][x] != '1')
				check_path(so, 0, x, y + 1);
		if (x > 0)
			if (so->m_check[y][x - 1] != '1')
				check_path(so, 0, x - 1, y);
	}
	return (error);
}
