/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 08:16:42 by oexall            #+#    #+#             */
/*   Updated: 2016/07/14 09:23:55 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int		ft_size(t_main *all)
{
	ft_count_cols(all);
	if (all->nb_lines - 2 < all->cnt_lines || all->nb_cols - 2 < all->cnt_cols)
	{
		ft_clear_screen();
		ft_putendl_fd("Window size to small", 2);
		return (0);
	}
	else
	{
		ft_clear_screen();
		ft_print_select(all);
	}
	return (1);
}

void	ft_count_cols(t_main *all)
{
	t_list	*tmp;

	tmp = all->lst;
	all->cnt_cols = tmp->len;
	while (tmp)
	{
		if (tmp->len > all->cnt_cols)
			all->cnt_cols = tmp->len;
		tmp = tmp->next;
	}
}

void	ft_resize(void)
{
	t_main			*all;
	struct winsize	win;

	all = NULL;
	all = ft_new(all, 1);
	ioctl(0, TIOCGWINSZ, &win);
	all->nb_lines = win.ws_row;
	all->nb_cols = win.ws_col;
	ft_size(all);
}
