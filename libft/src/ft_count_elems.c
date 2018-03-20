/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:47:45 by vliubko           #+#    #+#             */
/*   Updated: 2018/03/07 13:56:49 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** switch 1 for lists, switch 2 for 2d array
*/

int		ft_count_elems(t_list *list, char **av, int switcher)
{
	int count;
	int i;

	i = 0;
	count = 0;
	if (switcher == 1)
	{
		while (list)
		{
			count++;
			list = list->next;
		}
	}
	else if (switcher == 2)
	{
		while (av[i])
		{
			i++;
			count++;
		}
	}
	return (count);
}
