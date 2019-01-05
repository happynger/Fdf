/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 15:42:48 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/05 15:15:54 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(t_info *drawl, int *tab, int x, int y)
{
	int		tabx[2];
	int		taby[2];
	int		b[2];
	int		x0;
	int		y0;

	x0 = tab[0];
	y0 = tab[1];
	tabx[0] = abs(x - x0);
	tabx[1] = (x0 < x) ? 1 : -1;
	taby[0] = abs(y - y0);
	taby[1] = (y0 < y) ? 1 : -1;
	b[0] = (tabx[0] > taby[0] ? tabx[0] : -taby[0]) / 2;
	while (x0 != x || y0 != y)
	{
		mlx_pixel_put(drawl->mlx, drawl->win, x0, y0, drawl->color);
		b[1] = b[0];
		b[1] > -tabx[0] ? b[0] -= taby[0] : 1 == 1;
		b[1] > -tabx[0] ? x0 += tabx[1] : 1 == 1;
		b[1] < taby[0] ? b[0] += tabx[0] : 1 == 1;
		b[1] < taby[0] ? y0 += taby[1] : 1 == 1;
	}
}

static void	draw_lines(t_info *drawl, int x, int y)
{
	int		tab[2];

	tab[0] = drawl->dx + (x - y);
	tab[1] = drawl->dy + drawl->map[y / drawl->sy][x / drawl->sx] *
			 drawl->z + x + y;
	if (x / drawl->sx < drawl->rows - 1 && y / drawl->sy < drawl->lines)
		draw_line(drawl, tab, drawl->dx + ((x + drawl->sx) - y),
		drawl->dy + drawl->map[y / drawl->sy][x / drawl->sx + 1] *
		drawl->z + (x + drawl->sx) + y);
	if (y / drawl->sy < drawl->lines - 1 && x / drawl->sx < drawl->rows)
		draw_line(drawl, tab, drawl->dx + (x - (y + drawl->sy)),
		drawl->dy + drawl->map[y / drawl->sy + 1][x / drawl->sx] *
		drawl->z + x + (y + drawl->sy));
}

static void	check_drawing(t_info *drawl)
{
	if (drawl->frame == 0)
	{
		drawl->z = -5;
		drawl->dx = WIDTH * 0.4;
		drawl->dy = 20;
		drawl->sx = (WIDTH * 0.7) / (drawl->rows - 1);
		drawl->sy = (HEIGHT * 0.5) / (drawl->lines - 1);
		drawl->color = WHITE;
	}
	drawl->frame++;
}

void		draw(t_info *drawl)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	check_drawing(drawl);
	while (x / drawl->sx < drawl->rows || y / drawl->sy < drawl->lines - 1)
	{
		if (x / drawl->sx == drawl->rows)
		{
			x = 0;
			y += drawl->sy;
		}
		draw_lines(drawl, x, y);
		x += drawl->sx;
	}
}