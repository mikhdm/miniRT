#include "parsing/errors.h"
#include "libft.h"
#include <stdio.h>

void    ft_perror(unsigned code)
{
	const char *errors[] = {"Empty path",
						    "Scene is not provided",
						    "Screenshot param is incorrect",
						    "Incorrect number of arguments",
						    "Incorrect resolution",
						    "Incorrect ambient light"};

	if ((code != ERROR_ERRNO) && (code < 0 || code >= sizeof(errors) / sizeof(*errors)))
		return ;
	ft_putstr_fd(ERROR_HEADER, STDERR);
	if (code == ERROR_ERRNO)
	{
		perror(NULL);
		return ;
	}
	ft_putstr_fd((char *)errors[code], STDERR);
}