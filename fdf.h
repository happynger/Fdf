/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 12:42:47 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/13 15:16:40 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"

# define WIDTH 800
# define HEIGHT 800

# define MVTOEND(list) while (list) list = list->next

t_pixel				*pixel_init(intmax_t x, intmax_t y, intmax_t value);

typedef struct		s_pixel
{
	intmax_t		x;
	intmax_t		y;
	intmax_t		value;
	struct s_pixel	*next;
}					t_pixel;

typedef struct		s_info
{
	void			*mlx;
	void			*win;
	int				fd;
	t_pixel			*pix;
}					t_info;

#endif
