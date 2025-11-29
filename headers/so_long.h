/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:59:44 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/29 01:17:27 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "str_arr_utils.h"

typedef struct s_map
{
	char	**map;
	int		size_x;
	int		size_y;
}			t_map;

typedef struct s_cords
{
	int		x;
	int		y;
}			t_cords;

typedef struct s_data
{
	t_map	*map;
	void	*mlx;
	void	*win;
	int		texture_size;
	int		collectibles;
	int		collectible_count;
	int		moves_count;
	void	*wall_texture;
	void	*floor_texture;
	void	*collectible_texture;
	void	*player_texture;
	void	*exit_texture;
}			t_data;

t_map		*parse_map(char *file_name);
t_cords		*get_player_cords(t_map *map);
void		*load_texture(t_data *data, char *path);
void		render_map(t_data *data);
int			close_game(t_data *data);
void		move_player(t_data *data, int x, int y);
int			input_hook(int keycode, t_data *data);
void		count_collectibles(t_data *data);
void		validate_map(t_data *data);
void		throw_error(char *err, t_data *data);
void		put_chunk(t_data *data, int i, int j, char type);
void		player_exit(t_data *data, t_cords *player_pos);
#endif