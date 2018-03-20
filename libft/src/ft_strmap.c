/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:11:08 by vliubko           #+#    #+#             */
/*   Updated: 2017/11/13 15:24:32 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	size;
	size_t	i;
	char	*new;

	if (!s)
		return (NULL);
	if (!f)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	new = (char*)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	while (i < size)
	{
		new[i] = (*f)(s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
