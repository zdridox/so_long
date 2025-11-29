/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:00:28 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/29 01:00:08 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

t_cords	*get_player_cords(t_map *map)
{
	t_cords	*player_pos;
	int		i;
	int		j;

	i = 0;
	player_pos = malloc(sizeof(t_cords));
	if (!player_pos)
		return (NULL);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				player_pos->x = j;
				player_pos->y = i;
			}
			j++;
		}
		i++;
	}
	return (player_pos);
}

void	count_collectibles(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->collectible_count = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == 'C')
				data->collectible_count++;
			j++;
		}
		i++;
	}
}

int	close_game(t_data *data)
{
	if (data->wall_texture != NULL)
	{
		mlx_destroy_image(data->mlx, data->wall_texture);
		mlx_destroy_image(data->mlx, data->floor_texture);
		mlx_destroy_image(data->mlx, data->collectible_texture);
		mlx_destroy_image(data->mlx, data->player_texture);
		mlx_destroy_image(data->mlx, data->exit_texture);
	}
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	if (data->map)
	{
		str_arr_free(data->map->map);
		free(data->map);
	}
	free(data->mlx);
	free(data);
	exit(0);
	return (0);
}

void	throw_error(char *err, t_data *data)
{
	ft_printf("Error\n%s", err);
	close_game(data);
}
