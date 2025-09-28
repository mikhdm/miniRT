/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 01:19:40 by rmander           #+#    #+#             */
/*   Updated: 2021/05/21 23:39:49 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static char	*ft_read_rawline(t_vars *v, char **rawline)
{
	size_t	i;

	i = 0;
	while (TRUE)
	{
		v->length = read(v->fd, v->buff, BUFFER_SIZE);
		if (v->length <= 0)
			break ;
		i += v->length;
		v->buff[v->length] = '\0';
		ft_strchr(v->buff, '\n');
		if (v->endl)
			break ;
		v->tmp = *rawline;
		v->buff = malloc((i + BUFFER_SIZE + 1) * sizeof(char));
		if (v->buff)
			return (NULL);
		*rawline = v->buff;
		ft_strlcpy(v->buff, v->tmp, i + BUFFER_SIZE + 1);
		v->buff += i;
		free(v->tmp);
	}
	return (*rawline);
}

static char		*ft_get_partline(t_vars *v, t_data **data)
{
	char	*part;

	part = NULL;
	v->node = *data;
	while (v->node && (v->node->fd != v->fd))
		v->node = v->node->next;
	if (v->node)
		if ((v->endl = ft_strchr(v->node->part, '\n')))
		{
			if (!(part = ft_strdup_until(v->node->part, '\n')))
				return (NULL);
			v->tmp = v->node->part;
			if (!(v->node->part = ft_strdup_until(v->endl + 1, '\0')))
				return (NULL);
			free(v->tmp);
			v->tmp = NULL;
		}
	return (part);
}

static char		*ft_read(t_vars *v)
{
	char	*rawline;
	size_t	i;

	i = 0;
	if (!(v->buff = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (NULL);
	rawline = v->buff;
	*rawline = '\0';
	return (ft_read_rawline(v, &rawline));
}

static	int		post_read_handle(t_vars *v, t_data **data, char **line)
{
	if (v->endl)
	{
		v->part = ft_strdup_until(v->endl + 1, '\0'); 
		if (!v->part)
			return (ft_exit(data, v, *line, SIG_ERROR));
	}
	free(v->tmp);
	v->tmp = NULL;
	if (v->length == READ_ERROR)
		return (ft_exit(data, v, *line, SIG_ERROR));
	if (!(ft_setnode(v, data, *line)))
		return (ft_exit(data, v, *line, SIG_ERROR));
	if (v.length == READ_EOF)
		return (ft_exit(data, v, *line, SIG_EOF));
	return (SIG_OK);
}

int				get_next_line(int fd, char **line)
{
	static t_data	*data = NULL;
	t_vars			v;

	v = (t_vars) {.length=0, .fd=fd, .buff=NULL,
		.part=NULL, .endl=NULL, .tmp=NULL, .node=NULL};
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (ft_exit(&data, &v, line, SIG_ERROR));
	*line = ft_get_partline(&v, &data);
	if (*line)
		return (SIG_OK);
	*line = ft_read(&v);
	if (!*line)
		return (ft_exit(&data, &v, line, SIG_ERROR));
	v.tmp = *line;
	*line = ft_strdup_until(v.tmp, '\n');
	if (!*line)
		return (ft_exit(&data, &v, line, SIG_ERROR));
	return (ft_post_processing(&v, &data));
}
