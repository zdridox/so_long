#include "../headers/so_long.h"

t_cords *get_player_cords(t_map *map)
{
    t_cords *player_pos;
    int i;
    int j;

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

void close_game(t_data *data)
{
    mlx_destroy_image(data->mlx, data->wall_texture);
    mlx_destroy_image(data->mlx, data->floor_texture);
    mlx_destroy_image(data->mlx, data->collectible_texture);
    mlx_destroy_image(data->mlx, data->player_texture);
    mlx_destroy_image(data->mlx, data->floor_texture);
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
}