/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:00:59 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/05 17:10:35 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	init_tab(t_info *info, char *line)
{
	int		x;
	char	**tab;

	x = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	if (info->lines == 0)
		info->rows = x;
	else
	{
		if (x != info->rows)
			return (-1);
	}
	free(line);
	free(tab);
	info->lines++;
	return (0);
}

static void	init_info(t_info *info)
{
	char	*line;
	int		ret;

	line = NULL;
	info->lines = 0;
	info->rows = 0;
	while ((ret = get_next_line(info->fd, &line)) > 0)
	{
		if (init_tab(info, line) == -1)
			ft_error("ERR: The number of elements per line aren't consistent");
	}
	info->map = ft_memalloc(sizeof(int*) * info->lines);
	close(info->fd);
	info->fd = open(info->name, O_RDONLY);
}

void		parser(t_info *info)
{
	char	*line;
	char	**tab;
	int		x[3];

	x[0] = 0;
	init_info(info);
	while ((x[2] = get_next_line(info->fd, &line)) > 0)
	{
		x[1] = 0;
		tab = ft_strsplit(line, ' ');
		info->map[x[0]] = ft_memalloc(sizeof(int) * info->rows);
		while (tab[x[1]] != NULL)
		{
			info->map[x[0]][x[1]] = ft_atoi(tab[x[1]]);
			free(tab[x[1]]);
			x[1]++;
		}
		free(tab);
		x[0]++;
	}
	if (x[2] == -1)
		ft_error("ERROR: get_next_line returned <:-1:>");
}