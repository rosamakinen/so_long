/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:51:44 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/29 08:40:13 by rmakinen         ###   ########.fr       */
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
	ft_printf("%i\n", i); ////printing!
	while (i > 0)
	{
		free (so_long->map[i]);
		i--;
	}
	free(so_long->map);
	free(so_long->map_str);
	exit (0);
}
