/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:58:33 by vliubko           #+#    #+#             */
/*   Updated: 2017/11/15 14:30:38 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ret;
	int		size2;
	int		i;
	int		j;

	if (!size)
		return (ft_strlen(src) + size);
	ret = ft_strlen(src) + ft_strlen(dst);
	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	size2 = (int)size - i - 1;
	while (src[j] != '\0' && (int)size2 > 0)
	{
		dst[i] = src[j];
		i++;
		j++;
		size2--;
	}
	dst[i] = '\0';
	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	else
		return (ret);
}
