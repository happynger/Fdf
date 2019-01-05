/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 12:42:33 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/04 20:11:17 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_info			*info_init(char	*path)
{
	t_info	*a;

	a = NULL;
	a = (t_info *)malloc(sizeof(t_info));
	a->name = path;
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, WIDTH, HEIGHT, "FdF");
	a->fd = open(path, O_RDONLY);
	if (a->fd <= 2)
		ft_error(ft_strjoin("No file ", path));
	return (a);
}

int				main(int ac, char **av)
{
	t_info	*a;

	if (ac != 2)
		ft_error("Usage: ./fdf filename");
	a = info_init(av[1]);
	parser(a);
	a->frame = 0;
	draw(a);
	mlx_key_hook(a->win, &ft_keypress_hook, a);
	mlx_loop(a->mlx);
}
