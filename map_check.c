/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:17:12 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/24 11:46:43 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	send_error()
{
	ft_printf("ERROR!\n");
	exit (1);
}

int	check_edges(t_parameters *so_long, int error)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(so_long->map[i]) - 1;
	//ft_printf("len : %i", len);
	while (so_long->map[i] != NULL)
	{
		if (so_long->map[i][0] != '1')
			return (-1);
		//ft_printf("1st %c\n", so_long->map[i][0]);
		if (so_long->map[i][len] != '1')
			return (-2);
		//ft_printf("2nd %c\n", so_long->map[i][len]);
		if (so_long->map[0][i] != '1' && so_long->map[len][i] != '1')
			return (-3);
		//ft_printf("3rd %c\n", so_long->map[i][len]);
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
	ft_printf("map check %i\n", error);
	error = check_edges(so_long, error);
	ft_printf("map check %i\n", error);
	//check_map_validity();
	if (error != 0)
		send_error();
	return (0);
}
