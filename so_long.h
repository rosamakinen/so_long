/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 07:38:13 by rmakinen          #+#    #+#             */
/*   Updated: 2023/05/10 12:54:22 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define EMPTY "./textures/floors.xpm"
# define WALL "./textures/wall.xpm"
# define PLAYER "./textures/player.xpm"
# define COLLECT "./textures/collectible.xpm"
# define EXIT "./textures/exit.xpm"
# define S_W 47
# define S_H 47


# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "./libft/includes/libft.h"
# include "./libft/includes/ft_printf.h"
# include "./libft/includes/get_next_line.h"
# include "./libft/includes/get_next_line_bonus.h"
# include "./mlx/mlx.h"

typedef struct s_parameters
{
	void	*mlx;
	void	*win;
	int		player_x;
	int		player_y;
	int		pos_x;
	int		pos_y;
	int		player;
	int		collect;
	int		exit;
	int		empty;
	void	*p_pl;
	void	*p_co;
	void	*p_exit;
	void	*p_em;
	void	*p_wall;
	int		was_exit;
	int		c_check;
	int		reach;
	int		count;
	int		width;
	int		height;
	int		s_w;
	int		s_h;
	char	**map;
	char	**m_check;
	char	*map_str;
	char	*filename;

}			t_parameters;

//map parsing
int		open_file(char *str, t_parameters *so);
void	parse_map(int fd, t_parameters *so);
void	append(t_parameters *so, char *str, char *temp);
void	initialize_struct(t_parameters *so);

//map checking
int		map_check(t_parameters *so);
int		check_size(t_parameters *so, int error);
int		check_edges(t_parameters *so, int error);
int		check_other(t_parameters *so, int error);
int		check_other_result(t_parameters *so, int error);
int		check_filename(t_parameters *so, int error);
int		check_chars(t_parameters *so, int error);
int		check_path(t_parameters *so, int error, int x, int y);
void	start_position(t_parameters *so);
void	put_exit(t_parameters *so, int x, int y);

//errors
void	send_error(void);
void	free_and_exit(t_parameters *so);
void	free_and_check(char *to_free, char *check);
int		exit_button(t_parameters *so);

//window
void	get_width(t_parameters *so);
void	window_handle(t_parameters *so);
void	draw_map(t_parameters *so);
int		key_event(int keycode, t_parameters *so);

//game
void	up(t_parameters *so);
void	down(t_parameters *so);
void	left(t_parameters *so);
void	right(t_parameters *so);
void	move_ontop(t_parameters *so, int x, int y, char *dir);
void	check_end(t_parameters *so, int x, int y);
void	exit_win(t_parameters *so);
void	check_end(t_parameters *so, int x, int y);

#endif
