/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:19:19 by rmakinen          #+#    #+#             */
/*   Updated: 2023/05/03 11:19:52 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	check_chars(t_parameters *so_long, int error)
{
	int	y;
	int	x;

	y = 0;
	while (so_long->map[y])
	{
		x = 0;
		while(so_long->map[y][x])
		{
			if (so_long->map[y][x] != 'C' && so_long->map[y][x] != '0'
			&& so_long->map[y][x] != 'P' && so_long->map[y][x] != 'E'
			&& so_long->map[y][x] != '1')
				return (-1);
			x++;
		}
		y++;
	}
	return (error);
}

int	check_filename(t_parameters *so_long, int error)
{
	size_t	len;
	char	*temp;
	int		f_len;

	len = ft_strlen(so_long->filename);
	f_len = (len - 4);
	temp = ft_substr(so_long->filename, f_len, 4);
	if (ft_strcmp(temp, ".ber") != 0)
		return (-1);
	free (temp);
	return (error);
}
