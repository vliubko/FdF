/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:04:57 by vliubko           #+#    #+#             */
/*   Updated: 2017/11/15 14:46:16 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrev(char *str)
{
	char	a;
	int		i;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i = -1;
	while (++i < len--)
	{
		a = str[i];
		str[i] = str[len];
		str[len] = a;
	}
	return (str);
}
