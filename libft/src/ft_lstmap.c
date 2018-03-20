/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:25:35 by vliubko           #+#    #+#             */
/*   Updated: 2017/11/15 14:59:17 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;

	if (!lst || !f)
		return (NULL);
	newlist = (t_list*)malloc(sizeof(t_list));
	if (!newlist)
	{
		free(newlist);
		return (NULL);
	}
	newlist = f(lst);
	newlist->next = ft_lstmap(lst->next, f);
	return (newlist);
}
