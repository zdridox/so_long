#include "../headers/so_long.h"

void move_player(t_combo *combo, int x, int y)
{
    t_cords *player_pos;

    player_pos = get_player_cords(combo->map);
    if ((player_pos->x + x > combo->map->size_x || player_pos->x + x < 0) || (player_pos->y + y > combo->map->size_y || player_pos->y + y < 0))
        return (free(player_pos));
    if (combo->map->map[player_pos->y + y][player_pos->x + x] != '1' && combo->map->map[player_pos->y + y][player_pos->x + x] != 'E')
    {
        if (combo->map->map[player_pos->y + y][player_pos->x + x] == 'C')
        {
            combo->data->collectibles++;
            ft_printf("\rcollected %d/%d\n", combo->data->collectibles, combo->data->collectible_count);
        }
        combo->map->map[player_pos->y + y][player_pos->x + x] = 'P';
        combo->map->map[player_pos->y][player_pos->x] = '0';
        render_map(combo->map, combo->data);
        ft_printf("\rmoves: %d", ++combo->data->moves_count);
    }
    if (combo->map->map[player_pos->y + y][player_pos->x + x] == 'E' && combo->data->collectible_count == combo->data->collectibles)
    {
        ft_printf("\rmoves: %d", ++combo->data->moves_count);
        ft_printf("\ngg");
        free(player_pos);
        close_game(combo);
    }
    free(player_pos);
}