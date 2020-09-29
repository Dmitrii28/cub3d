#include <string.h>
#include <errno.h>

# include "../cub3d.h"
int		ft_check_file(char *argv)
{
	int i;

	if ((i = ft_strlen(argv)) < 5)
		return (0); //////wrong name file

	while (i >= 0 && argv[i] != '.')
		i--;
	if (ft_strncmp((const char *)(&argv[i + 1]), "cub", 4) != 0)
		return (0);
	else
		return (1);
}

int	ft_check_args(int argc, char **argv)
{
	int		fd;

	if (argc < 2 || argc > 3)
		return (100); ///// не верное количество аргументов
	if (!(ft_check_file(argv[1])) ) // уточнить, может больше или равно
	{
		return (88); //////wrong name file
	}



	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putstr_fd(strerror(errno), 2); //////// удалить перенести в ошибки
		return (fd);
	}
	close(fd);




	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 6))
		{
			return (10); //// неверный 3 аргумент
		}

	}


	return 0;


}