cmake_minimum_required(VERSION 3.17)
project(my)

set(CMAKE_C_STANDARD 99)

include_directories(.)
include_directories(libft)
include_directories(mlx_linux)
include_directories(/usr/lib/x86_64-linux-gnu)
include_directories(/usr/include/X11)
include_directories(/usr/include)
include_directories(/usr/include/X11/extensions)
include_directories(/usr/lib)

link_directories(/usr/include/X11/extensions)
link_directories(/usr/lib/x86_64-linux-gnu)
link_directories(/usr/include/X11)
link_directories(/usr/include)
link_directories(mlx_linux)
link_directories(/usr/lib)


# specify the dependency on an extra library
#target_link_libraries(libmlx.a)

#set(CMAKE_EXE_LINKER_FLAGS "-Lmlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz")
set (CMAKE_C_FLAGS "-lmlx -lXext -lX11 -lm -lz")



add_executable(my
        base/ft_base.c
        base/ft_key_press.c
        base/ft_key_scan.c
        base/ft_game_first_param.c
        base/ft_full_window.c
        base/ft_xmp_to_img.c
        base/ft_dist_and_dot_wall.c
        error/error_1.c
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_calloc.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_itoa.c
        libft/ft_lstadd_back.c
        libft/ft_lstadd_front.c
        libft/ft_lstclear.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstlast.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_lstsize.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_putchar_fd.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr_fd.c
        libft/ft_split.c
        libft/ft_strchr.c
        libft/ft_strdup.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlcpy.c
        libft/ft_strlen.c
        libft/ft_strmapi.c
        libft/ft_strncmp.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strtrim.c
        libft/ft_substr.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/get_next_line.c
        libft/get_next_line.h
        libft/get_next_line_utils.c
        libft/libft.h
        mlx_linux/mlx.h
        mlx_linux/mlx_int.h
        parser/ft_check_args.c
        parser/ft_chek_map.c
        parser/ft_make_array.c
        parser/ft_take_param.c
        parser/ft_take_param_2.c
        parser/parser.c
        cub3d.h
        main.c)



find_library(MLX mlx mlx_linux)
#target_link_libraries(my  ${X11} ${XEXT} ${M} ${Z} ${MLX})

target_link_libraries(my ${MLX} Xext X11 m z )
#target_link_libraries(my -lXext -lX11 -lm -lz -lbsd ${MLX})
