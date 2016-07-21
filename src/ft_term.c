/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 11:13:22 by oexall            #+#    #+#             */
/*   Updated: 2016/07/14 10:00:42 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int		ft_init_term(t_main *all)
{
	struct winsize	win;

	if (tgetent(NULL, getenv("TERM")) < 1)
		return (0);
	if (tcgetattr(0, &(all->term)) == -1)
		return (0);
	all->term.c_lflag &= ~(ICANON | ECHO);
	all->term.c_cc[VMIN] = 1;
	all->term.c_cc[VTIME] = 0;
	ioctl(0, TIOCGWINSZ, &win);
	all->nb_lines = win.ws_row;
	all->nb_cols = win.ws_col;
	if (tcsetattr(0, 0, &(all->term)) == -1)
		return (0);
	tputs(tgetstr("ti", NULL), 1, ft_myputchar);
	tputs(tgetstr("vi", NULL), 1, ft_myputchar);
	return (1);
}

int		ft_end_term(t_main *all)
{
	all->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &(all->term)) == -1)
		return (0);
	tputs(tgetstr("te", NULL), 1, ft_myputchar);
	tputs(tgetstr("ve", NULL), 1, ft_myputchar);
	return (1);
}
