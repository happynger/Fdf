/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:16:34 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/05 13:48:05 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void zchange(int keycode, t_info *key)
{
	if (keycode == ZOOM_IN && key->sx * 2 <= 500 && key->sy * 2 <= 500)
	{
		mlx_clear_window(key->mlx, key->win);
		key->sx *= 2;
		key->sy *= 2;
		key->z *= 2;
		draw(key);
	}
	if (keycode == ZOOM_OUT && key->sx / 2 >= 1 && key->sy / 2 >= 1
		&& (-key->z / 2 >= 1 || key->z / 2 >= 1))
	{
		mlx_clear_window(key->mlx, key->win);
		key->sx /= 2;
		key->sy /= 2;
		key->z /= 2;
		draw(key);
	}
}

static void move(int keycode, t_info *key)
{
	if (ARROWS(keycode) || keycode == RESTART)
	{
		mlx_clear_window(key->mlx, key->win);
		if (keycode == 124)
			key->dx -= 10;
		if (keycode == 125)
			key->dy -= 10;
		if (keycode == 123)
			key->dx += 10;
		if (keycode == 126)
			key->dy += 10;
		if (keycode == RESTART)
			key->frame = 0;
		draw(key);
	}
}

int			ft_keypress_hook(int keycode, t_info *key)
{
	if (keycode == ESC_CODE || keycode == 53)
		exit(0);
	if (keycode == RELIEF_IN)
	{
		mlx_clear_window(key->mlx, key->win);
		key->z++;
		draw(key);
	}
	if (keycode == RELIEF_OUT)
	{
		mlx_clear_window(key->mlx, key->win);
		key->z--;
		draw(key);
	}
	if (keycode == COLOR)
	{
		mlx_clear_window(key->mlx, key->win);
		if (key->frame % 11 == 0)
			key->color = 0xFF000000;
		key->color = key->color >> 2;
		draw(key);
	}
	zchange(keycode, key);
	move(keycode, key);
	return (0);
}
