/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:48:44 by vliubko           #+#    #+#             */
/*   Updated: 2017/11/13 15:18:13 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_decimals(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*str;

	sign = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_decimals(n);
	sign = (n < 0) ? -1 : 1;
	len = (n < 0) ? len + 1 : len;
	n = (n < 0) ? -n : n;
	str = (char*)malloc(sizeof(char) * (len) + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len)
	{
		len--;
		str[len] = n % 10 + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
