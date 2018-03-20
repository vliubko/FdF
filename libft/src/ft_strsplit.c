/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:39:42 by vliubko           #+#    #+#             */
/*   Updated: 2017/11/15 14:16:15 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_nword(char *str, char c)
{
	int space_count;
	int i;

	space_count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			if (str[i + 1] == c || str[i + 1] == '\0')
				space_count++;
		}
		i++;
	}
	return (space_count);
}

static int		ft_charcheck(char x, char c)
{
	if (x == c)
	{
		return (1);
	}
	else
		return (0);
}

static int		ft_wlen(char *str, int i, char c)
{
	int	char_count;

	char_count = 0;
	while (str[i])
	{
		if ((str[i + 1] != c) || (str[i + 1] != 0))
			char_count++;
		else
			break ;
		i++;
	}
	return (char_count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**hand;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s || !(hand = (char**)malloc(sizeof(s) * (ft_nword((char*)s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (ft_charcheck(s[i], c) == 1)
			i++;
		else
		{
			if (!(hand[j] = ft_strnew(ft_wlen((char*)s, i, c) + 1)))
				return (NULL);
			k = 0;
			while (ft_charcheck(s[i], c) == 0 && s[i] != '\0')
				hand[j][k++] = s[i++];
			hand[j++][k] = '\0';
		}
	}
	hand[j] = NULL;
	return (hand);
}
