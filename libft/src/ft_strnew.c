/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:21:16 by vliubko           #+#    #+#             */
/*   Updated: 2017/11/13 15:25:17 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	void	*ptr;

	ptr = malloc(size + 1);
	if (ptr)
		ft_bzero(ptr, size + 1);
	if (!ptr)
		return (NULL);
	return (ptr);
}
