/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:17:12 by rmakinen          #+#    #+#             */
/*   Updated: 2023/05/10 11:52:09 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_other_result(t_parameters *so, int error)
{
	if (so->collect < 1)
		return (-1);
	if (so->player != 1)
		return (-1);
	if (so->exit != 1)
		return (-1);
	return (error);
}

int	check_other(t_parameters *so, int error)
{
	int	i;
	int	j;

	i = 0;
	while (so->map[i])
	{
		j = 0;
		while (so->map[i][j])
		{
			if (so->map[i][j] == 'C')
				so->collect = so->collect +1;
			if (so->map[i][j] == 'P')
				so->player = so->player +1;
			if (so->map[i][j] == 'E')
				so->exit = so->exit +1;
			if (so->map[i][j] == '0')
				so->empty = so->empty +1;
			j++;
		}
		i++;
	}
	error = check_other_result(so, error);
	return (error);
}

int	check_edges(t_parameters *so, int error)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(so->map[i]) - 1;
	while (so->map[i] != NULL)
	{
		if (so->map[i][0] != '1')
			return (-1);
		if (so->map[i][len] != '1')
			return (-2);
		if (so->map[0][i] != '1' && so->map[len][i] != '1')
			return (-3);
		i++;
	}
	return (error);
}

int	check_size(t_parameters *so, int error)
{
	int		i;
	size_t	ref;

	i = 0;
	ref = ft_strlen(so->map[i]);
	while (so->map[i])
	{
		if (ft_strlen(so->map[i]) != ref)
			return (-1);
		i++;
	}
	return (error);
}

int	map_check(t_parameters *so)
{
	int	error;

	error = 0;
	error = check_size(so, error);
	error = check_chars(so, error);
	error = check_edges(so, error);
	error = check_other(so, error);
	error = check_filename(so, error);
	start_position(so);
	error = check_path(so, error, so->player_x, so->player_y);
	if (so->c_check == so->collect && so->reach == 1 && error == 0)
		return (0);
	else
		send_error();
	return (0);
}
