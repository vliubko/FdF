/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:58:14 by vliubko           #+#    #+#             */
/*   Updated: 2018/03/07 13:58:25 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_free_2d_array(char **av)
{
	int		i;
	char	**new_av;

	i = 0;
	new_av = av;
	while (new_av[i])
	{
		ft_strdel(&new_av[i]);
		i++;
	}
	free(new_av);
}
