#include "../headers/so_long.h"

void str_arr_print(char **arr) {
    int i;

    i = 0;
    while (arr[i])
    {
        ft_printf("%s\n", arr[i]);
        i++;
    }
}

void str_arr_free(char **arr) {
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void str_arr_copy(char **dest, char **src) {
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = ft_strdup(src[i]);
        i++;
    } 
}

// dziala tylko jak chcesz zwiekszysc array nie zmniejszyc
char **str_arr_resize(char **arr, int new_size) {
    char **new_arr;

    new_arr = malloc(new_size * sizeof(char *));
    if(!new_arr)
        return (NULL);
    str_arr_copy(new_arr, arr);
    str_arr_free(arr);
    return (new_arr);
}

int str_arr_length(char **arr) {
    int i;

    i = 0;
    while (arr[i])
        i++;
    return (i);
}

// int main() {
//     char **arr = malloc(4 * sizeof(char *));
//     arr[0] = ft_strdup("marek");
//     arr[1] = ft_strdup("sral do");
//     arr[2] = ft_strdup("wiertarek");
//     arr[3] = NULL;

//     str_arr_print(arr);
//     ft_printf("array length: %d\n\n", str_arr_length(arr));
//     arr = str_arr_resize(arr, 5);
//     arr[3] = ft_strdup("tescior");
//     arr[4] = NULL;
//     str_arr_print(arr);
//     ft_printf("array length: %d\n\n", str_arr_length(arr));
//     str_arr_free(arr);
//     return 0;
// }