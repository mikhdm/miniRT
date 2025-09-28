/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 01:19:34 by rmander           #+#    #+#             */
/*   Updated: 2021/05/21 23:10:02 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define SIG_OK 1
# define SIG_EOF 0
# define SIG_ERROR -1

# define READ_EOF 0
# define READ_ERROR -1

typedef struct		s_data
{
	int				fd;
	char			*part;
	struct s_data	*next;
}					t_data;

typedef struct		s_vars
{
	ssize_t			length;
	int				fd;
	char			*buff;
	char			*part;
	char			*tmp;
	char			*endl;
	t_data			*node;
}					t_vars;

int					get_next_line(int fd, char **line);

char				*ft_strdup_until(const char *s1, const char sym);
size_t				ft_strlen_until(const char *s, const char sym);
int					ft_exit(t_data **data, t_vars *v, char **line, int signal);
t_data				*ft_setnode(t_vars *v, t_data **data, char **line);
#endif
