/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 07:26:18 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/27 10:07:03 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	parse_map(int fd, t_parameters *so_long)
{
	int			i;
	char		*str;
	static char		*map_str;
	i = 0;

	map_str = ft_strdup("");
	str = "";
	while (str)
	{
		str = get_next_line(fd);
		if (str != NULL)
			map_str = ft_strjoin(map_str, str);
		free(str);
	}
	free(str);
	// ft_printf("%s\n", map_str); //PRINTING THE MAPPPPPP!!!!!
	so_long->map = ft_split(map_str, '\n');
	if (so_long->map == NULL)
		exit (1);
	while (so_long->map[i]) /// PRINTING THE MAP AGAIN!!!!!!
	{
		ft_printf("%s\n", so_long->map[i]);
		i++;
	}
	so_long->i = i;
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

int	main(int argc, char **argv)
{
	t_parameters	so_long;
	int				i;

	i = 0;
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

