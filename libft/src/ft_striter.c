/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:06:37 by vliubko           #+#    #+#             */
/*   Updated: 2017/11/13 15:22:55 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_striter(char *s, void (*f)(char*))
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
		(*f)(s + i);
		i++;
	}
}
