/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:19:19 by rmakinen          #+#    #+#             */
/*   Updated: 2023/05/10 12:48:38 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_end(t_parameters *so, int x, int y)
{
	if (so->collect == 0)
	{
		so->map[y][x] = 'P';
		exit_win(so);
	}
}

void	move_ontop(t_parameters *so, int x, int y, char *dir)
{
	so->was_exit = 0;
	so->map[y][x] = 'P';
	if (ft_strcmp(dir, "up") == 0)
		so->map[y + 1][x] = '0';
	if (ft_strcmp(dir, "down") == 0)
		so->map[y - 1][x] = '0';
	if (ft_strcmp(dir, "left") == 0)
		so->map[y][x + 1] = '0';
	if (ft_strcmp(dir, "right") == 0)
		so->map[y][x - 1] = '0';
	so->count++;
	ft_printf("%i\n", so->count);
}

int	check_chars(t_parameters *so, int error)
{
	int	y;
	int	x;

	y = 0;
	while (so->map[y])
	{
		x = 0;
		while (so->map[y][x])
		{
			if (so->map[y][x] != 'C' && so->map[y][x] != '0'
			&& so->map[y][x] != 'P' && so->map[y][x] != 'E'
			&& so->map[y][x] != '1')
				return (-1);
			x++;
		}
		y++;
	}
	return (error);
}

int	check_filename(t_parameters *so, int error)
{
	size_t	len;
	char	*temp;
	int		f_len;

	len = ft_strlen(so->filename);
	f_len = (len - 4);
	temp = ft_substr(so->filename, f_len, 4);
	if (ft_strcmp(temp, ".ber") != 0)
		return (-1);
	free (temp);
	return (error);
}

int	key_event(int keycode, t_parameters *so)
{
	int	x;
	int	y;

	x = so->player_x;
	y = so->player_y;
	if (keycode == 53)
		free_and_exit(so);
	else if (keycode == 13 || keycode == 126)
		up(so);
	else if (keycode == 1 || keycode == 125)
		down(so);
	else if (keycode == 0 || keycode == 123)
		left(so);
	else if (keycode == 2 || keycode == 124)
		right(so);
	return (0);
}
