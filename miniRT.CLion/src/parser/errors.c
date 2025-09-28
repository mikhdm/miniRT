#include "errors.h"
#include "libft.h"
#include <stdio.h>

void error(char const *message)
{
	ft_putstr_fd(ERROR_HEADER, STDOUT)
	if (message)
	{
		ft_putstr_fd(message, STDERR);
	}
}