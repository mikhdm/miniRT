/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_A.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 03:58:59 by rmander           #+#    #+#             */
/*   Updated: 2021/05/28 03:09:56 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "utils.h"
#include "libft.h"
#include "parsing/errors.h"
#include "parsing/serialize.h"
#include <errno.h>

# define ST_EMPTY 0
# define ST_DOT 1
# define ST_DOTLEFT 2
# define ST_DOTRIGHT 4
# define ST_EXPSIGN 8
# define ST_EXPVAL 16

static short validinfn(const char **string)
{
	const char	*str;
	const char	*label;
	size_t		i;
	const char *labels[] = {"inf", "infinity", "-inf", "-infinity", "nan", "-nan"};

	label = NULL;
	str = *string;
	i = 0;
	while (i < sizeof(labels) / sizeof(*labels))
	{
		label = labels[i++];
		if (ft_strncmp(str, label,
				 imax((ssize_t)ft_strlen(label), (ssize_t)ft_strlen(str))) == 0)
			return (TRUE);
	}
	return (FALSE);
}

static short validot(const char **string, unsigned char *status)
{
	const char *str = *string;

	if (*str == '.')
	{
		*status |= ST_DOT;
		++str;
		if (*status == ST_DOT && !ft_isdigit(*str))
			return (FALSE);
		while (ft_isdigit(*str))
		{
			*status |= ST_DOTRIGHT;
			++str;
		}
	}
	if ((*status == ST_EMPTY) || (*status == ST_DOT))
		return (FALSE);
	*string = str;
	return (TRUE);
}

/*
*
* validexp called if and only if validot is TRUE.
*
*/
static short validexp(const char **string, unsigned char *status)
{
	const char *str = *string;

	if (*str && *str != 'e' && *str != 'E')
		return (FALSE);
	if (*str == 'e' || *str == 'E')
	{
		*status |= ST_EXPSIGN;
		++str;
		if (*str == '+' || *str == '-')
			++str;
		if (!ft_isdigit(*str))
			return (FALSE);
		while (ft_isdigit(*str))
		{
			*status |= ST_EXPVAL;
			++str;
		}
	}
	*string = str;
	return (TRUE);
}

/*
 * state:
 * 		0b00000001 - dot exists
 * 		0b00000010 - digits on the left of dot exists
 * 		0b00000100 - digits on the right exists
 * 		0b00001000 - exp sign exists
 * 		0b00010000 - exp value exists
 */
short	ft_isfloatable(const char *str)
{
	const char		*ptr;
	unsigned char	status;

	if (validinfn(&str))
		return (TRUE);
	status = 0;
	if (*str == '-' || *str == '+')
		++str;
	ptr = str;
	if (!ft_isdigit(*ptr) && *ptr != '.')
		return (FALSE);
	while (ft_isdigit(*ptr))
	{
		status |= ST_DOTLEFT;
		++ptr;
	}
	if (status != ST_DOTLEFT && *ptr != '.')
		return (FALSE);
	if (!validot(&ptr, &status))
		return (FALSE);
	if (!validexp(&ptr, &status))
		return (FALSE);
	return (TRUE);
}

t_data  *serialize_A(t_data *data, char const *line)
{
	char	**strs;
	char 	*str;
	size_t 	strslen;
	size_t 	i;

	strs = NULL;
	str = NULL;
	line += ft_strlen(LABEL_AMBIENCE);
	if (!ft_isspace(*line))
		serialize_exitfree(ERROR_SYNTAX_AMBIENCE, 255, data, NULL);
	strs = ft_splitf(line, &ft_isspace);
	if (!strs)
		serialize_exitfree(ERROR_ERRNO, errno, data, NULL);
	strslen = ft_strslen(strs);
	if (strslen != 2)
		serialize_exitfree(ERROR_SYNTAX_AMBIENCE, 255, data, strs);
	i = 0;
	while (i < strslen)
	{
		str = strs[i++];
	}
	return (data);
}
