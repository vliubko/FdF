/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:14:04 by vliubko           #+#    #+#             */
/*   Updated: 2017/11/13 15:29:45 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int		j;
	int		size;
	char	*ret;

	if (!s)
		return (NULL);
	j = 0;
	ret = (char*)s;
	while ((*ret == ' ' || *ret == '\n' || *ret == '\t') && *ret)
		ret++;
	j = ft_strlen(ret) - 1;
	size = ft_strlen(ret);
	if (size == 0)
		return (ft_strnew(size));
	while ((ret[j] == ' ' || ret[j] == '\n' || ret[j] == '\t'))
		j--;
	ret = ft_strsub(ret, 0, size - (size - j) + 1);
	return (ret);
}
