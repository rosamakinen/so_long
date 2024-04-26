/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 07:26:18 by rmakinen          #+#    #+#             */
/*   Updated: 2023/05/10 12:45:24 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(int fd, t_parameters *so)
{
	char	*str;
	char	*temp;
	int		count;

	count = 0;
	temp = NULL;
	so->map_str = ft_strdup("");
	if (so->map_str == NULL)
		send_error();
	str = "";
	while (str)
	{
		str = get_next_line(fd);
		if (count == 0 && str == NULL)
			send_error();
		if (str == NULL)
			break ;
		if (ft_strncmp(str, "\n", ft_strlen(str)) == 0)
			send_error();
		if (str != NULL)
			append(so, str, temp);
		free(str);
		count++;
	}
}

void	append(t_parameters *so, char *str, char *temp)
{
	temp = ft_strdup(so->map_str);
	free_and_check(so->map_str, temp);
	so->map_str = ft_strjoin(temp, str);
	free_and_check(temp, so->map_str);
}

int	open_file(char *str, t_parameters *so)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("ERROR! failed to open map");
		exit (1);
	}
	parse_map(fd, so);
	so->map = ft_split(so->map_str, '\n');
	so->m_check = ft_split(so->map_str, '\n');
	if (so->map == NULL || so->map_str == NULL)
		send_error();
	get_width(so);
	close(fd);
	return (0);
}

void	initialize_struct(t_parameters *so)
{
	so->mlx = NULL;
	so->win = NULL;
	so->player_x = 0;
	so->player_y = 0;
	so->pos_x = 0;
	so->pos_y = 0;
	so->player = 0;
	so->collect = 0;
	so->exit = 0;
	so->empty = 0;
	so->was_exit = 1;
	so->c_check = 0;
	so->reach = 0;
	so->width = 0;
	so->height = 0;
	so->count = 0;
	so->map = NULL;
	so->map_str = NULL;
	so->filename = NULL;
}

int	main(int argc, char **argv)
{
	t_parameters	so;

	initialize_struct(&so);
	if (argc != 2)
	{
		ft_printf("ERROR! invalid number of arguments");
		exit (1);
	}
	if (argc == 2)
	{
		so.filename = argv[1];
		open_file(argv[1], &so);
		map_check(&so);
	}
	window_handle(&so);
	return (0);
}
