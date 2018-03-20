/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbinarytodecimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:49:28 by vliubko           #+#    #+#             */
/*   Updated: 2017/11/28 13:54:37 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_convertbinarytodecimal(long long n)
{
	int		decimal;
	int		i;
	int		remainder;

	decimal = 0;
	i = 0;
	while (n != 0)
	{
		remainder = n % 10;
		n /= 10;
		decimal += remainder * ft_power(2, i);
		++i;
	}
	return (decimal);
}
