/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 12:42:47 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/13 17:12:01 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"

# define WIDTH 800
# define HEIGHT 800
# define ESC_CODE 65307
# define WHITE 255255255
# define GREY 190190190

# define MVTOEND(list) while (list) list = list->next

# define ERROR(msg, nb, val) if (nb != ft_arrlen(val)) ft_error(msg);

t_pixel				*pixel_init(intmax_t x, intmax_t y, intmax_t value, int i);
int					ft_keypress_hook(int keycode, t_info *a);
int					ft_expose_hook(t_info *a);

typedef struct		s_pixel
{
	intmax_t		x;
	intmax_t		y;
	intmax_t		value;
	int				index;
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
