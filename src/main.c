#include "../headers/so_long.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    t_data *data;
    t_map *map;
    t_combo *combo;

    map = parse_map(argv[1]);
    data = malloc(sizeof(t_data));
    combo = malloc(sizeof(t_combo));
    combo->data = data;
    combo->map = map;
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, 64 * map->size_x, 64 * map->size_y, "dlugo");
    data->texture_size = 64;

    data->wall_texture = load_texture(data, "./textures/wall.xpm");
    data->floor_texture = load_texture(data, "./textures/floor.xpm");
    data->collectible_texture = load_texture(data, "./textures/collectible.xpm");
    data->player_texture = load_texture(data, "./textures/player.xpm");
    data->exit_texture = load_texture(data, "./textures/exit.xpm");
    
    mlx_loop_hook(data->mlx, render_loop, combo);
    mlx_key_hook(data->win, input_hook, combo);
    mlx_loop(data->mlx);
    return (0);
}