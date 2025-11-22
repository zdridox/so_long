#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "str_arr_utils.h"

typedef struct s_map
{
    char **map;
    int size_x;
    int size_y;
} t_map;

typedef struct s_cords
{
    int x;
    int y;
} t_cords;

typedef struct s_data
{
    void *mlx;
    void *win;
    int texture_size;
    int collectibles;
    int collectible_count;
    void *wall_texture;
    void *floor_texture;
    void *collectible_texture;
    void *player_texture;
    void *exit_texture;
} t_data;

typedef struct s_combo
{
    t_data *data;
    t_map *map;
} t_combo;

t_map *parse_map(char *file_name);
t_cords *get_player_cords(t_map *map);
void put_error(char *err_message);
void *load_texture(t_data *data, char *path);
void render_map(t_map *map, t_data *data);
int render_loop(t_combo *combo);
void close_game(t_data *data);
void move_player(t_map *map, t_data *data, int x, int y);
int input_hook(int keycode, t_combo *combo);
void count_collectibles(t_combo *combo);
int validate_map(t_map *map);