/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:00:59 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/29 01:18:34 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include <stdlib.h>

void	load_textures_to_struct(t_data *data)
{
	data->wall_texture = load_texture(data, "./textures/wall.xpm");
	data->floor_texture = load_texture(data, "./textures/floor.xpm");
	data->collectible_texture = load_texture(data,
			"./textures/collectible.xpm");
	data->player_texture = load_texture(data, "./textures/player.xpm");
	data->exit_texture = load_texture(data, "./textures/exit.xpm");
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (ft_printf("you need to provide a map file."), 0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_printf("memory allocation failed"), 1);
	data->map = parse_map(argv[1]);
	data->collectibles = 0;
	data->moves_count = 0;
	data->texture_size = 64;
	data->win = NULL;
	data->mlx = mlx_init();
	load_textures_to_struct(data);
	if (data->map == NULL)
		throw_error("invalid file.", data);
	validate_map(data);
	count_collectibles(data);
	data->win = mlx_new_window(data->mlx, 64 * data->map->size_x,
			64 * data->map->size_y, "dlugo");
	render_map(data);
	mlx_key_hook(data->win, input_hook, data);
	mlx_hook(data->win, 17, 0, close_game, data);
	mlx_loop(data->mlx);
	return (0);
}
