cmake_minimum_required(VERSION 3.17)
project(my____ C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(mlx_linux)

add_executable(my____
        mlx_linux/test/main.c
        mlx_linux/test/new_win.c
        mlx_linux/mlx.h
        mlx_linux/mlx_clear_window.c
        mlx_linux/mlx_destroy_image.c
        mlx_linux/mlx_destroy_window.c
        mlx_linux/mlx_expose_hook.c
        mlx_linux/mlx_ext_randr.c
        mlx_linux/mlx_flush_event.c
        mlx_linux/mlx_get_color_value.c
        mlx_linux/mlx_get_data_addr.c
        mlx_linux/mlx_hook.c
        mlx_linux/mlx_init.c
        mlx_linux/mlx_int.h
        mlx_linux/mlx_int_anti_resize_win.c
        mlx_linux/mlx_int_do_nothing.c
        mlx_linux/mlx_int_get_visual.c
        mlx_linux/mlx_int_param_event.c
        mlx_linux/mlx_int_set_win_event_mask.c
        mlx_linux/mlx_int_str_to_wordtab.c
        mlx_linux/mlx_int_wait_first_expose.c
        mlx_linux/mlx_key_hook.c
        mlx_linux/mlx_lib_xpm.c
        mlx_linux/mlx_loop.c
        mlx_linux/mlx_loop_hook.c
        mlx_linux/mlx_mouse.c
        mlx_linux/mlx_mouse_hook.c
        mlx_linux/mlx_new_image.c
        mlx_linux/mlx_new_window.c
        mlx_linux/mlx_pixel_put.c
        mlx_linux/mlx_put_image_to_window.c
        mlx_linux/mlx_rgb.c
        mlx_linux/mlx_screen_size.c
        mlx_linux/mlx_string_put.c
        mlx_linux/mlx_xpm.c
        cub3d.h
        main.c)
