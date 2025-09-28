/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 01:19:40 by rmander           #+#    #+#             */
/*   Updated: 2021/04/11 19:18:26 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

static int	ft_exit(t_data **data, t_vars *v, char **line, int signal)
{
	t_data	**curr;
	t_data	*tmp;

	curr = data;
	tmp = NULL;
	if (v->tmp)
		free(v->tmp);
	while ((*curr) && (*curr)->fd != v->fd)
		curr = &(*curr)->next;
	tmp = *curr;
	if (tmp)
	{
		*curr = (*curr)->next;
		free(tmp->part);
		free(tmp);
		tmp = NULL;
	}
	if (line && *line && (signal == SIG_ERROR))
	{
		free(*line);
		*line = NULL;
	}
	return (signal);
}

static char	*ft_read_raw_line(t_vars *v)
{
	char	*raw_line;
	size_t	i;

	i = 0;
	v->buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!v->buff)
		return (NULL);
	raw_line = v->buff;
	*raw_line = '\0';
	while (((v->length = read(v->fd, v->buff, BUFFER_SIZE)) > 0))
	{
		i += v->length;
		v->buff[v->length] = '\0';
		v->endl = ft_strchr(v->buff, '\n');
		if (v->endl)
			break ;
		v->tmp = raw_line;
		if (!(v->buff = malloc((i + BUFFER_SIZE + 1) * sizeof(char))))
			return (NULL);
		raw_line = v->buff;
		ft_strlcpy(v->buff, v->tmp, i + BUFFER_SIZE + 1);
		v->buff += i;
		free(v->tmp);
	}
	return (raw_line);
}

static t_data	*ft_set_node(t_vars *v, t_data **data, char **line)
{
	v->node = *data;
	while (v->node && (v->node->fd != v->fd))
		v->node = v->node->next;
	if (!v->node)
	{
		v->node = *data;
		if (!(*data = malloc(sizeof(t_data))))
			return (NULL);
		(*data)->part = v->part;
		(*data)->fd = v->fd;
		(*data)->next = v->node;
		v->node = *data;
		return (v->node);
	}
	v->tmp = *line;
	*line = ft_strjoin(v->node->part, *line);
	if (!*line)
		return (NULL);
	free(v->tmp);
	free(v->node->part);
	v->tmp = NULL;
	v->node->part = v->part;
	return (v->node);
}

static char	*ft_get_part_line(t_vars *v, t_data **data)
{
	char	*part;

	part = NULL;
	v->node = *data;
	while (v->node && (v->node->fd != v->fd))
		v->node = v->node->next;
	if (v->node)
	{
		v->endl = ft_strchr(v->node->part, '\n');
		if (v->endl)
		{
			part = ft_strdup_until(v->node->part, '\n');
			if (!part)
				return (NULL);
			v->tmp = v->node->part;
			v->node->part = ft_strdup_until(v->endl + 1, '\0');
			if (!v->node->part)
				return (NULL);
			free(v->tmp);
			v->tmp = NULL;
		}
	}
	return (part);
}

int	get_next_line(int fd, char **line)
{
	static t_data	*data = NULL;
	t_vars			v;

	v = (t_vars){.length = 0, .fd = fd, .buff = NULL,
		.part = NULL, .endl = NULL, .tmp = NULL, .node = NULL};
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (ft_exit(&data, &v, line, SIG_ERROR));
	*line = ft_get_part_line(&v, &data);
	if (*line)
		return (SIG_OK);
	*line = ft_read_raw_line(&v);
	if (!*line)
		return (ft_exit(&data, &v, line, SIG_ERROR));
	v.tmp = *line;
	*line = ft_strdup_until(v.tmp, '\n');
	if (!*line)
		return (ft_exit(&data, &v, line, SIG_ERROR));
	if (v.endl && !(v.part = ft_strdup_until(v.endl + 1, '\0')))
		return (ft_exit(&data, &v, line, SIG_ERROR));
	free(v.tmp);
	v.tmp = NULL;
	if (v.length == READ_ERROR || !(ft_set_node(&v, &data, line)))
		return (ft_exit(&data, &v, line, SIG_ERROR));
	if (v.length == READ_EOF)
		return (ft_exit(&data, &v, line, SIG_EOF));
	return (SIG_OK);
}
