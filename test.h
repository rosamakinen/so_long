/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 07:38:13 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/24 13:51:23 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "./libft/includes/libft.h"
# include "./libft/includes/ft_printf.h"
# include "./libft/includes/get_next_line.h"
# include "./libft/includes/get_next_line_bonus.h"

typedef struct s_parameters
{
	void	*mlx_ptr;
	void	*img_ptr;
	int		map_width;
	int		map_height;
	int		player;
	int		collect;
	int		exit;
	int		empty; //DO I NEED THIS??
	char	**map;
	char	*map_str;
}		t_parameters;

//map parsing
int	open_file(char *str, t_parameters *so_long);
void	parse_map(int fd, t_parameters *so_long);

//map checking
int	map_check(t_parameters *so_long);
int	check_size(t_parameters *so_long, int error);
int	check_edges(t_parameters *so_long, int error);
int	check_other(t_parameters *so_long, int error);
int	check_other_result(t_parameters *so_long, int error);

//errors
void	send_error();

#endif
