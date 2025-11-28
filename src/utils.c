/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:00:28 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:00:29 by mzdrodow         ###   ########.fr       */
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

void	count_collectibles(t_combo *combo)
{
	int	i;
	int	j;

	i = 0;
	combo->data->collectible_count = 0;
	while (combo->map->map[i])
	{
		j = 0;
		while (combo->map->map[i][j])
		{
			if (combo->map->map[i][j] == 'C')
				combo->data->collectible_count++;
			j++;
		}
		i++;
	}
}

int	close_game(t_combo *combo)
{
	if (combo->data->win != NULL)
	{
		mlx_destroy_image(combo->data->mlx, combo->data->wall_texture);
		mlx_destroy_image(combo->data->mlx, combo->data->floor_texture);
		mlx_destroy_image(combo->data->mlx, combo->data->collectible_texture);
		mlx_destroy_image(combo->data->mlx, combo->data->player_texture);
		mlx_destroy_image(combo->data->mlx, combo->data->exit_texture);
		mlx_destroy_window(combo->data->mlx, combo->data->win);
	}
	mlx_destroy_display(combo->data->mlx);
	str_arr_free(combo->map->map);
	free(combo->map);
	free(combo->data->mlx);
	free(combo->data);
	free(combo);
	exit(0);
	return (0);
}

void	throw_error(char *err, t_combo *combo)
{
	ft_printf("Error\n%s", err);
	close_game(combo);
}
