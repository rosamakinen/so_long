/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 07:26:18 by rmakinen          #+#    #+#             */
/*   Updated: 2023/05/08 09:55:36 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	get_width(t_parameters *so_long)
{
	int	i;

	i = 0;
	so_long->width = ft_strlen(so_long->map[0]);
	while (so_long->map[i])
	{
		i++;
	}
	so_long->height = i;
}


void	parse_map(int fd, t_parameters *so_long)
{
	char		*str;
	static char	*map_str;
	char		*temp;

	map_str = ft_strdup("");

	str = "";
	while (str)
	{
		str = get_next_line(fd);
		if (str != NULL)
		{
			temp = ft_strdup(map_str);
			//free_and_check(map_str, temp);
			map_str = ft_strjoin(temp, str);
		}
		//free_and_check(temp, map_str);
		free(str);
	}
	so_long->map = ft_split(map_str, '\n');
	get_width(so_long);
	if (so_long->map == NULL)
		exit (1);
}


int	open_file(char *str, t_parameters *so_long)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("ERROR! failed to open map");
		exit (1);
	}
	parse_map(fd, so_long);
	//CLOSE FILE AFTER MAP IS READY
	return (0);
}

void	initialize_struct(t_parameters *so_long)
{
	so_long->mlx_ptr = NULL;
	so_long->win_ptr = NULL;
	so_long->player_x = 0;
	so_long->player_y = 0;
	so_long->player = 0;
	so_long->collect = 0;
	so_long->exit = 0;
	so_long->empty = 0;
	so_long->c_check = 0;
	so_long->width = 0;
	so_long->height = 0;
	so_long->count = 0;
	so_long->map = NULL;
	so_long->map_str = NULL;
	so_long->filename = NULL;
}

int	main(int argc, char **argv)
{
	t_parameters	so_long;
	int				i;

	i = 0;
	initialize_struct(&so_long);
	if (argc != 2)
	{
		ft_printf("ERROR! invalid number of arguments");
		exit (1);
	}
	if (argc == 2)
	{
		so_long.filename = argv[1];
		open_file(argv[1], &so_long);
		map_check(&so_long);
	}
	window_handle(&so_long);
	ft_printf("jaahas at the end");
	return (0);
}

