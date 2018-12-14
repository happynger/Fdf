/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:00:59 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/13 16:12:15 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	file_read(t_info *a)
{
	char	*line;

	while (get_next_line(a->fd, &line) != 0)
		line_read(line, &a->pix);
	
}

void	line_read(char *line, t_pixel **head)
{
	static size_t	nbvalues;
	static int		y;
	int				x;
	char			**values;
	t_pixel			*pix;

	x = 0;
	pix = *head;
	MVTOEND(pix);
	values = ft_strsplit(line, ' ');
	if (nbvalues == 0)
		nbvalues = ft_arrlen(values);
	else
		if (nbvalues != ft_arrlen(values))
			ft_error("Found wrong line length. Exiting");
	while (values[x] != NULL)
	{
		if (pix)
			pix->next = pixel_init(x, y, ft_atol(values[x]));
		else
			pix = pixel_init(x, y, ft_atol(values[x]));
		pix = pix->next;
		x++;
	}
	y++;
}
