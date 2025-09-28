#include "parsing/errors.h"
#include "parsing/parse.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void    ft_perror(int code)
{
	const char *errors[] = {"Empty path",
						    "Scene is not provided",
						    "Screenshot param is incorrect",
						    "Incorrect number of arguments",
						    "Incorrect scene extension",
						    "Incorrect resolution line syntax",
						    "Incorrect ambience line syntax",
						    "Incorrect camera line syntax",
						    "Incorrect light line syntax",
						    "Incorrect sphere line syntax",
						    "Incorrect cylinder line syntax",
						    "Incorrect plane line syntax",
						    "Incorrect triangle line syntax",
						    "Incorrect square line syntax",
						    "Invalid resolution values",
						    "Duplicate resolution",
						    "Invalid ambience values",
						    "Duplicate ambience",
						    "Invalid camera values",
						    };
	int	size;

	size = sizeof(errors) / sizeof(*errors);
	if ((code != ERROR_ERRNO) && (code < 0 || code >= size))
		return ;
	ft_putstr_fd(ERROR_HEADER, STDERR);
	if (code == ERROR_ERRNO)
	{
		perror(NULL);
		return ;
	}
	ft_putstr_fd((char *)errors[code], STDERR);
	ft_putchar_fd('\n', STDERR);
}

void ft_pexit(int code, int status)
{
	ft_perror(code);
	exit(status);
}

void ft_pexitfree(int code, int status, t_data *data)
{
	if (data)
		cleanup(data);
	ft_pexit(code, status);
}