/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:55:09 by vliubko           #+#    #+#             */
/*   Updated: 2017/11/13 15:23:08 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	size;
	size_t	i;

	if (!s)
		return ;
	if (!f)
		return ;
	size = ft_strlen(s);
	i = 0;
	while (i < size)
	{
		(*f)(i, s + i);
		i++;
	}
}
