/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 08:57:17 by oexall            #+#    #+#             */
/*   Updated: 2016/07/14 07:49:37 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

t_list	*ft_new_elem(char *value)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->value = ft_strdup(value);
	tmp->len = ft_strlen(value);
	tmp->select = 0;
	tmp->line = 0;
	tmp->next = NULL;
	return (tmp);
}

void	ft_push_elem_back(t_list **begin_list, char *value)
{
	t_list	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_new_elem(value);
	}
	else
		*begin_list = ft_new_elem(value);
}

void	ft_args_to_list(char **args, t_main *all)
{
	int		i;

	i = 1;
	while (args[i])
	{
		ft_push_elem_back(&all->lst, args[i]);
		if (i == 1)
			all->lst->line = 1;
		i++;
	}
}
