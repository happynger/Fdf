/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:00:59 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/13 17:15:04 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	file_read(t_info *a)
{
	char	*line;

	while (get_next_line(a->fd, &line) == 1)
		line_read(line, &a->pix);
	close(a->fd);
}

void	line_read(char *line, t_pixel **head)
{
	static size_t	nbvalues;
	static int		i[2];
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
		ERROR("Found wrong line length. Exiting", nbvalues, values);
	while (values[x] != NULL)
	{
		if (pix)
			pix->next = pixel_init(x, i[0], ft_atol(values[x]), i[1]++);
		else
			pix = pixel_init(x, i[0], ft_atol(values[x]), i[1]++);
		pix = pix->next;
		x++;
	}
	i[0]++;
}
