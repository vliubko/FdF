/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 22:55:23 by vliubko           #+#    #+#             */
/*   Updated: 2017/11/13 15:29:09 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	char	*help;

	i = 0;
	help = (char *)str;
	if (!*to_find)
		return ((char*)str);
	if (!*str)
		return (NULL);
	while (help[i] != '\0')
	{
		j = 0;
		while (help[i + j] == to_find[j])
		{
			j++;
			if (!to_find[j])
				return (help + i);
		}
		i++;
	}
	return (NULL);
}
