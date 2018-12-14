/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 12:42:33 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/13 16:09:38 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel			*pixel_init(intmax_t x, intmax_t y, intmax_t value)
{
	t_pixel	*new;

	new = (t_pixel *)malloc(sizeof(*new));
	new->x = x;
	new->y = y;
	new->value = value;
	new->next = NULL;
	return (new);
}

t_info			*info_init(char	*path)
{
	t_info	*a;

	a = NULL;
	a = (t_info *)malloc(sizeof(t_info));
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, WIDTH, HEIGHT, "FdF");
	a->pix = NULL;
	a->fd = open(path, O_RDONLY);
	if (a->fd <= 2)
		ft_error(ft_strjoin("No file ", path));
	return (a);
}

int				main(int ac, char **av)
{
	t_info	*a;

	if (ac != 2)
		ft_error("Invalid amount of arguments");
	// * Initiate the t_pixel struct!
	a = info_init(av[1]);
	// ? Read The Instructions from .fdf file
	// ? Create a window based on the instructions from the file
	// ? Listen to the key even to check if the person wants to (esc) or (v) change the view
	mlx_loop(a->mlx);
}
