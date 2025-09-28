#include "errors.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

char *readfile(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(ERROR_HEADER, STDOUT);
		perror(NULL);
	}
}