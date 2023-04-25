/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 07:38:13 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/25 14:28:16 by rmakinen         ###   ########.fr       */
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

# define EMPTY "./tiles/floors.xpm"
# define WALL "./tiles/wall.xpm"
# define PLAYER "./tiles/player.xpm"
# define COLLECT "./tiles/collectible.xpm"
# define EXIT "./tiles/exit.xpm"
# define S_WIDTH 47
# define S_HEIGHT 47

typedef struct s_parameters
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		w_width; //DO I NEED THIS??
	int		w_height; //DO I NEED THIS??
	int		player;
	int		collect;
	int		exit;
	int		empty; //DO I NEED THIS??
	char	**map;
	char	*map_str;
}		t_parameters;

typedef struct s_sprite
{
	void	*player;
	void	*player_r; //DO I NEED THIS??
	void	*player_l; //DO I NEED THIS??
	void	*collect;
	void	*exit;
	void	*empty;
	void	*wall;
	int		s_width;
	int		s_height;
}		t_sprite;

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

//window
void	window_handle(t_parameters *so_long);
void	draw_map(t_parameters *so_long, t_sprite *sprite);

#endif
