/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 15:50:18 by oexall            #+#    #+#             */
/*   Updated: 2016/07/14 08:26:23 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	ft_common_keys(unsigned int keycode, t_main *all)
{
	if (keycode == KEY_DOWN)
		ft_move_down(all);
	if (keycode == KEY_UP)
		ft_move_up(all);
	if (keycode == KEY_SPACE)
		ft_select_item(all);
}

int			ft_keyhook(t_main *all)
{
	char	*keycode[5];

	ft_bzero(keycode, 5);
	read(0, keycode, 4);
	if (*(unsigned int *)keycode == KEY_ESCAPE)
		return (-1);
	if (all)
	{
		ft_common_keys(*(unsigned int *)keycode, all);
		if (*(unsigned char *)keycode == KEY_DEL)
			all->cnt_lines -= ft_del_line(all);
		if (*(unsigned char *)keycode == KEY_ENTER)
			return (ft_ret_tab(all));
		ft_clear_screen();
		ft_print_select(all);
	}
	return (1);
}
