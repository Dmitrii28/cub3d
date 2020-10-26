#include "../cub3d.h"
#include "libft.h"
#include <string.h>
#include <errno.h>
void ft_err_check_cub(t_param *prm)
{

}


void ft_error_fd(t_param *prm)
{
	ft_putstr_fd("Error\n", prm->fd_err);
	if (prm->exit == 156)
		ft_putstr_fd("Can't open file .cub\n", prm->fd_err);
	if (prm->exit == 170)
		ft_putstr_fd("Can't create file for shot\n", prm->fd_err);
	if (prm->exit == 151)
		ft_putstr_fd("Can't open file texture NO\n", prm->fd_err);
	if (prm->exit == 152)
		ft_putstr_fd("Can't open file texture SO\n", prm->fd_err);
	if (prm->exit == 153)
		ft_putstr_fd("Can't open file texture WE\n", prm->fd_err);
	if (prm->exit == 154)
		ft_putstr_fd("Can't open file texture EA\n", prm->fd_err);
	if (prm->exit == 155)
		ft_putstr_fd("Can't open file texture S\n", prm->fd_err);
	ft_putstr_fd(strerror(errno), prm->fd_err);
}

void	ft_error(t_param *prm)
{
	if (prm->fd_err < 0)
		ft_error_fd(prm);
	else if (prm->exit < )


}
