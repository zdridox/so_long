#include "../headers/so_long.h"
#include <stdlib.h>

void load_textures_to_struct(t_data *data) {
    data->wall_texture = load_texture(data, "./textures/wall.xpm");
    data->floor_texture = load_texture(data, "./textures/floor.xpm");
    data->collectible_texture = load_texture(data, "./textures/collectible.xpm");
    data->player_texture = load_texture(data, "./textures/player.xpm");
    data->exit_texture = load_texture(data, "./textures/exit.xpm");
}

int main(int argc, char **argv)
{
    t_combo *combo;

    if(argc != 2)
        return(ft_printf("you need to provide a map file."), 0);
    combo = malloc(sizeof(t_combo));
    combo->map = parse_map(argv[1]);
    combo->data = malloc(sizeof(t_data));
    combo->data->collectibles = 0;
    combo->data->moves_count = 0;
    combo->data->texture_size = 64;
    combo->data->win = NULL;
    count_collectibles(combo);
    combo->data->mlx = mlx_init();
    validate_map(combo);
    load_textures_to_struct(combo->data);
    combo->data->win = mlx_new_window(combo->data->mlx, 64 * combo->map->size_x, 64 * combo->map->size_y, "dlugo");
    mlx_loop_hook(combo->data->mlx, render_loop, combo);
    mlx_key_hook(combo->data->win, input_hook, combo);
    mlx_hook(combo->data->win, 17, 0, close_game, combo);
    mlx_loop(combo->data->mlx);
    return (0);
}

// TODO
//  NORMINETTE ( NA LIBFT KURWA TEZ )