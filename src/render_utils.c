/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:00:47 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/29 01:18:13 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	*load_texture(t_data *data, char *path)
{
	void	*image;

	image = mlx_xpm_file_to_image(data->mlx, path, &(data->texture_size),
			&(data->texture_size));
	if (!image)
		return (NULL);
	return (image);
}

void	render_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			put_chunk(data, i, j, data->map->map[i][j]);
			j++;
		}
		i++;
	}
}

void	put_chunk(t_data *data, int i, int j, char type)
{
	if (type == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->floor_texture, 64
			* j, 64 * i);
	if (type == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall_texture, 64
			* j, 64 * i);
	if (type == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player_texture, 64
			* j, 64 * i);
	if (type == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->collectible_texture,
			64 * j, 64 * i);
	if (type == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit_texture, 64
			* j, 64 * i);
}
