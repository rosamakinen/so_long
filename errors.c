/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:51:44 by rmakinen          #+#    #+#             */
/*   Updated: 2023/05/02 12:40:03 by rmakinen         ###   ########.fr       */
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
