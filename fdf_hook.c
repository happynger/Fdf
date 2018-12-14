/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:16:34 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/13 16:42:16 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_expose_hook(t_info *a)
{
	return (0);
}

int		ft_keypress_hook(int keycode, t_info *a)
{
	a = a;
	if (keycode == ESC_CODE)
		exit(0);
	return (0);
}
