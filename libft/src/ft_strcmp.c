/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 23:27:51 by vliubko           #+#    #+#             */
/*   Updated: 2017/11/13 15:21:39 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	str1;
	unsigned char	str2;

	i = 0;
	str1 = s1[i];
	str2 = s2[i];
	while (str1 == str2)
	{
		i++;
		str1 = s1[i];
		str2 = s2[i];
		if (str1 == '\0' && str2 == '\0')
			return (0);
	}
	return (str1 - str2);
}
