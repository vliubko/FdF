/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 11:32:50 by vliubko           #+#    #+#             */
/*   Updated: 2017/11/15 14:45:08 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		*ft_int_sort(int *tab, int length)
{
	int i;
	int j;

	i = 0;
	if (!tab)
		return (NULL);
	if (length == 0)
		return (0);
	while (i < length)
	{
		j = 0;
		while (j < length)
		{
			if (tab[i] < tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	return (tab);
}
