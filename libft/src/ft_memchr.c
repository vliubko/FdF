/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:57:34 by vliubko           #+#    #+#             */
/*   Updated: 2017/11/13 15:19:27 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*a;
	size_t	i;

	i = -1;
	a = (unsigned char *)s;
	while (++i < n)
	{
		if (*(unsigned char *)a == (unsigned char)c)
			return (a);
		a++;
	}
	return (NULL);
}
