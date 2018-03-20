/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:12:07 by vliubko           #+#    #+#             */
/*   Updated: 2017/11/13 15:19:29 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		cmp;

	i = -1;
	while (++i < n)
	{
		cmp = *(unsigned char *)s1++ - *(unsigned char *)s2++;
		if (cmp != 0)
			return (cmp);
	}
	return (cmp);
}
