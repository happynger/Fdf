/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:00:59 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/13 14:15:46 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	file_read(char *path)
{
	int		fd;
	char	*line;

	if ((fd = open(path, O_RDONLY)) <= 2)
		ft_error(ft_strjoin("No file ", path));

	while (get_next_line(fd, &line) != 0)
	{
		line_read(line);
	}

}

void	line_read(char *line)
{
	static size_t	nbvalues;
	char			**values;

	values = ft_strsplit(line, ' ');
	if (nbvalues == 0)
		nbvalues = ft_arrlen(values);
	else
		if (nbvalues != ft_arrlen(values))
			ft_error("Found wrong line length. Exiting");
}
