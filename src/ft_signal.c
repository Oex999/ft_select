/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 14:18:11 by oexall            #+#    #+#             */
/*   Updated: 2016/07/14 12:19:21 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	ft_continue(void)
{
	t_main	*all;

	all = NULL;
	all = ft_new(all, 1);
	ft_init_term(all);
}

static void	ft_stop(void)
{
	t_main	*all;

	all = NULL;
	all = ft_new(all, 1);
	all->term.c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, &(all->term));
	tputs(tgetstr("te", NULL), 1, ft_myputchar);
	tputs(tgetstr("ve", NULL), 1, ft_myputchar);
}

void		ft_catch(int i)
{
	if (i == SIGCONT)
		ft_continue();
	else if (i == SIGSTOP)
		ft_stop();
	else
		ft_stop();
}

void		ft_signal(void)
{
	int	i;

	i = 1;
	while (i < 32)
	{
		signal(i, ft_catch);
		i++;
	}
}
