/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:12:43 by vliubko           #+#    #+#             */
/*   Updated: 2017/11/15 12:19:43 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int		ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
	c == '\v' || c == '\f' || c == '\r');
}

int				ft_atoi(const char *str)
{
	unsigned long long int		res;
	int							i;
	int							znak;

	res = 0;
	i = 0;
	znak = 1;
	while (ft_is_whitespace(str[i]))
		i++;
	if (str[i] == '-')
		znak = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		if ((res > 922337203685477580 || (res == 922337203685477580
		&& (str[i] - '0') > 7)) && znak == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
		&& (str[i] - '0') > 8)) && znak == -1)
			return (0);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * znak);
}
