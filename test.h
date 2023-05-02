/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 07:38:13 by rmakinen          #+#    #+#             */
/*   Updated: 2023/05/02 12:56:21 by rmakinen         ###   ########.fr       */
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

typedef struct s_parameters
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		player_x; //DO I NEED THIS??
	int		player_y; //DO I NEED THIS??
	int		player;
	int		collect;
	int		exit;
	int		empty; //DO I NEED THIS??
	int		c_check;
	int		width;
	int		height;
	int		count;
	char	**map;
	char	**m_check; //DO I NEED THIS??
	char	*map_str;
	char	*filename;

}		t_parameters;


//map parsing
int	open_file(char *str, t_parameters *so_long);
void	parse_map(int fd, t_parameters *so_long);
void	initialize_struct(t_parameters *so_long);

//map checking
int	map_check(t_parameters *so_long);
int	check_size(t_parameters *so_long, int error);
int	check_edges(t_parameters *so_long, int error);
int	check_other(t_parameters *so_long, int error);
int	check_other_result(t_parameters *so_long, int error);
int	check_filename(t_parameters *so_long, int error);
int	check_chars(t_parameters *so_long, int error);

//errors
void	send_error();
void	free_and_exit(t_parameters *so_long);

//window
void	get_width(t_parameters *so_long);
void	window_handle(t_parameters *so_long);
void	draw_map(t_parameters *so_long);
int		key_event(int keycode, t_parameters *so_long);

//game
void	up(t_parameters *so_long);
void	down(t_parameters *so_long);
void	left(t_parameters *so_long);
void	right(t_parameters *so_long);

#endif
