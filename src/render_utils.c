#include "../headers/so_long.h"

void *load_texture(t_data *data, char *path)
{
    void *image;

    image = mlx_xpm_file_to_image(data->mlx, path, &(data->texture_size), &(data->texture_size));
    if (!image)
        return (NULL);
    return (image);
}

void render_map(t_map *map, t_data *data)
{
    int i;
    int j;

    i = 0;
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j])
        {
            if (map->map[i][j] == '0')
                mlx_put_image_to_window(data->mlx, data->win, data->floor_texture, 64 * j, 64 * i);
            if (map->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->wall_texture, 64 * j, 64 * i);
            if (map->map[i][j] == 'P')
                mlx_put_image_to_window(data->mlx, data->win, data->player_texture, 64 * j, 64 * i);
            if (map->map[i][j] == 'C')
                mlx_put_image_to_window(data->mlx, data->win, data->collectible_texture, 64 * j, 64 * i);
            if (map->map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx, data->win, data->exit_texture, 64 * j, 64 * i);
            j++;
        }

        i++;
    }
}

int render_loop(t_combo *combo)
{
    render_map(combo->map, combo->data);
    return (0);
}