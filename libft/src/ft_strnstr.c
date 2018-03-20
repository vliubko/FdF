/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:52:36 by vliubko           #+#    #+#             */
/*   Updated: 2017/11/13 15:25:30 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	*help;

	i = 0;
	l = 0;
	help = (char *)str;
	if (!*to_find || to_find == str)
		return ((char*)str);
	if (!*str)
		return (NULL);
	while (help[i] != '\0' && l++ <= len)
	{
		j = 0;
		while (help[i + j] == to_find[j] && (i + j) < len)
		{
			j++;
			if (!to_find[j])
				return (help + i);
		}
		i++;
	}
	return (NULL);
}
