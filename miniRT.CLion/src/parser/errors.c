#include "errors.h"
#include "libft.h"
#include <stdio.h>

void ft_perror(char const *message)
{
	ft_putstr_fd(ERROR_HEADER, STDOUT);
	if (message)
		ft_putstr_fd((char *)message, STDERR);
	else
		perror(NULL);
}