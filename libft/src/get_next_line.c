/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:33:03 by vliubko           #+#    #+#             */
/*   Updated: 2018/03/20 15:44:36 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_list_gnl	*get_current_fd(int fd, t_list_gnl **list)
{
	t_list_gnl *new_list;

	new_list = *list;
	while (new_list)
	{
		if (new_list->fd == fd)
			return (new_list);
		new_list = new_list->next;
	}
	if (!(new_list = (t_list_gnl*)malloc(sizeof(t_list_gnl))))
		return (NULL);
	new_list->fd = fd;
	new_list->remain_line = NULL;
	new_list->next = *list;
	*list = new_list;
	return (new_list);
}

static char			*remain_line_check(t_list_gnl *list)
{
	char	*tmp;
	char	*buf;
	char	*leak_clean;

	tmp = NULL;
	buf = ft_strnew(BUFF_SIZE);
	if (list->remain_line == NULL)
		tmp = ft_strnew(0);
	else if (list->remain_line != NULL)
		tmp = ft_strdup(list->remain_line);
	if (ft_strchr(tmp, '\n') == NULL)
	{
		while ((read(list->fd, buf, BUFF_SIZE)) > 0)
		{
			leak_clean = tmp;
			tmp = ft_strjoin(tmp, buf);
			ft_strdel(&leak_clean);
			if (ft_strchr(buf, '\n') != NULL)
				break ;
			ft_bzero(buf, BUFF_SIZE);
		}
	}
	ft_strdel(&buf);
	return (tmp);
}

static char			*write_line(t_list_gnl *list, char *tmp, char **line)
{
	int		i;
	char	*to_line;

	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	to_line = ft_strnew(i);
	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
	{
		to_line[i] = tmp[i];
		i++;
	}
	*line = to_line;
	if (list->remain_line)
		ft_strdel(&list->remain_line);
	if (tmp[i] == '\0')
		list->remain_line = ft_strdup(&tmp[i]);
	else
		list->remain_line = ft_strdup(&tmp[++i]);
	ft_strdel(&tmp);
	return (list->remain_line);
}

int					get_next_line(const int fd, char **line)
{
	char				*tmp;
	static t_list_gnl	*list;
	t_list_gnl			*current;

	if (!line || BUFF_SIZE < 1 || read(fd, "", 0) < 0)
		return (-1);
	current = get_current_fd(fd, &list);
	tmp = remain_line_check(current);
	if (tmp[0] == '\0')
	{
		ft_strdel(&tmp);
		return (0);
	}
	current->remain_line = write_line(current, tmp, line);
	return (1);
}
