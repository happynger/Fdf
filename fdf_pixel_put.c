/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:09:42 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/13 17:07:19 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	putlinelow(long x0, long y0, long x1, long y1, t_info *a)
{
	long	d[2];
	int		dir[2];
	long	c[2];

	d[0] = x1 - x0;
	d[1] = y1 - y0;
	dir[1] = 1;
	if (d[1] < 0)
	{
		dir[1] = -1;
		d[1] = -d[1];
	}
	dir[0] = 2 * d[1] - d[0];
	c[1] = y0;
	c[0] = x0;
	while (c[0] < x1)
	{
		mlx_pixel_put(a->mlx, a->win, c[0], c[1], WHITE);
		if (dir > 0)
		{
			c[1] = c[1] + dir[1];
			dir[0] = dir[0] - 2 * d[0];
		}
		dir[0] = dir[0] + 2 * d[1];
	}
}

static void	putlinehigh(long x0, long y0, long x1, long y1, t_info *a)
{
	long	d[2];
	int		dir[2];
	long	c[2];

	d[0] = x1 - x0;
	d[1] = y1 - y0;
	dir[1] = 1;
	if (d[0] < 0)
	{
		dir[1] = -1;
		d[0] = -d[0];
	}
	dir[0] = 2 * d[0] - d[1];
	c[1] = y0;
	c[0] = x0;
	while (c[1] < y1)
	{
		mlx_pixel_put(a->mlx, a->win, c[0], c[1], WHITE);
		if (dir > 0)
		{
			c[0] = c[0] + dir[1];
			dir[0] = dir[0] - 2 * d[1];
		}
		dir[0] = dir[0] + 2 * d[0];
	}
}

void	fdf_putline(long x0, long y0, long x1, long y1, t_info *a)
{
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			putlinelow(x1, y1, x0, y0, a);
		else
			putlinelow(x0, y0, x1, y1, a);
	}
	else
	{
		if (y0 > y1)
			putlinehigh(x1, y1, x0, y0, a);
		else
			putlinehigh(x0, y0, x1, y1, a);
	}
}

void	fdf_pixel_put(t_info *a)
{

}
