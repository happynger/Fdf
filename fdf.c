/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 12:42:33 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/13 14:16:34 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main (int ac, char **av)
{
	void	*init;
	void	*win;
	char	*path;

	if (ac != 2)
		ft_error("Invalid amount of arguments");
	path = av[1];
	// ? Read The Instructions from .fdf file
	init = mlx_init();
	// ? Create a window based on the instructions from the file
	win = mlx_new_window(init, 1000, 1000, "FdF");
	// ? Listen to the key even to check if the person wants to (esc) or (v) change the view
	mlx_loop(init);
}
