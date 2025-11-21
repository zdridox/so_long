#include "../headers/so_long.h"

int input_hook(int keycode, t_combo *combo)
{
    if (keycode == 65307) // ESCAPE
    {
        close_game(combo->data);
    }
    if (keycode == 119) // W
    {
        move_player(combo->map, combo->data, 0, -1);
    }
    if (keycode == 97) // A
    {
        move_player(combo->map, combo->data, -1, 0);
    }
    if (keycode == 115) // S
    {
        move_player(combo->map, combo->data, 0, 1);
    }
    if (keycode == 100) // D
    {
        move_player(combo->map, combo->data, 1, 0);
    }
    return (0);
}