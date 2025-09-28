/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 04:03:34 by rmander           #+#    #+#             */
/*   Updated: 2021/05/21 23:15:58 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static t_data	*ft_newnode(t_vars *v, t_data **data)
{
	v->node = *data;
	*data = malloc(sizeof(t_data));
	if (!*data)
		return (NULL);
	(*data)->part = v->part;
	(*data)->fd = v->fd;
	(*data)->next = v->node;
	v->node = *data;
	return (v->node);
}

size_t	ft_strlen_until(const char *s, const char sym)
{
	size_t	i;

	i = 0;
	while (*s && (*s != sym))
	{
		++i;
		++s;
	}
	return (i);
}

char	*ft_strdup_until(const char *s1, const char sym)
{
	char	*dup;
	char	*d;

	dup = malloc((ft_strlen_until(s1, sym) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	d = dup;
	while (*s1 && *s1 != sym)
		*dup++ = *s1++;
	*dup = '\0';
	return (d);
}

int	ft_exit(t_data **data, t_vars *v, char **line, int signal)
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

t_data	*ft_setnode(t_vars *v, t_data **data, char **line)
{
	v->node = *data;
	while (v->node && (v->node->fd != v->fd))
		v->node = v->node->next;
	if (!v->node)
		return (ft_newnode(v, data));
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
