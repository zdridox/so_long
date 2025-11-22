#include "../headers/so_long.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    t_data *data;
    t_map *map;
    t_combo *combo;

    map = parse_map(argv[1]);
    if (validate_map(map) != 0)
    {
        ft_printf("invalid map.");
        close_game(data);
    }
    data = malloc(sizeof(t_data));
    combo = malloc(sizeof(t_combo));
    data->collectibles = 0;
    combo->data = data;
    combo->map = map;
    count_collectibles(combo);
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

// TODO
//  make each validator function call another one and on error just print it and exit() no need for main validator function then
//  shitload of leaks and suppressed errors
//  make close widnow button close game
//  Makefile