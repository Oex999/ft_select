/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 09:06:34 by oexall            #+#    #+#             */
/*   Updated: 2016/07/14 09:03:18 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

t_main	*ft_new(t_main *all, int i)
{
	static t_main	*tmp = NULL;

	if (i == 0)
		tmp = all;
	return (tmp);
}

int		ft_myputchar(int c)
{
	return (write(2, &c, 1));
}

void	ft_clear_screen(void)
{
	tputs(tgetstr("cl", NULL), 1, ft_myputchar);
}
