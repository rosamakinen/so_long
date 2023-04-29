/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:17:12 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/28 08:02:34 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	check_other_result(t_parameters *so_long, int error)
{
	if (so_long->collect < 1)
		return (-1);
	if (so_long->player != 1)
		return (-1);
	if (so_long->exit != 1)
		return (-1);
	return (error);
}

int	check_other(t_parameters *so_long, int error)
{
	int	i;
	int	j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while(so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'C')
				so_long->collect = so_long->collect +1;
			if (so_long->map[i][j] == 'P')
				so_long->player = so_long->player +1;
			if (so_long->map[i][j] == 'E')
				so_long->exit = (so_long->exit +1);
			if (so_long->map[i][j] == '0')
				so_long->empty = so_long->empty +1;
			j++;
		}
		i++;
	}
	error = check_other_result(so_long, error);
	return (error);
}

int	check_edges(t_parameters *so_long, int error)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(so_long->map[i]) - 1;
	while (so_long->map[i] != NULL)
	{
		if (so_long->map[i][0] != '1')
			return (-1);
		if (so_long->map[i][len] != '1')
			return (-2);
		if (so_long->map[0][i] != '1' && so_long->map[len][i] != '1')
			return (-3);
		i++;
	}
	return (error);
}

int	check_size(t_parameters *so_long, int error)
{
	int		i;
	size_t	ref;

	i = 0;
	ref = ft_strlen(so_long->map[i]);
	while (so_long->map[i])
	{
		if (ft_strlen(so_long->map[i]) != ref)
			return (-1);
		i++;
	}
	return (error);
}

int	map_check(t_parameters *so_long)
{
	int error;

	error = 0;
	error = check_size(so_long, error);
	ft_printf("map check 1 %i\n", error);
	error = check_edges(so_long, error);
	ft_printf("map check 2 %i\n", error);
	error = check_other(so_long, error);
	ft_printf("map check 3 %i\n", error);
	error = check_filename(so_long);
	//error = check_path(so_long);
	if (error != 0)
		send_error();
	return (0);
}
