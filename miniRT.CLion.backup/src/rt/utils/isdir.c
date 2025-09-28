#include <unistd.h>
#include "libft.h"

short isdir(int fildes)
{
	char    buff[1];
	ssize_t rval;

	rval = read(fildes, buff, 1);
	if (rval == -1)
	{
		close(fildes);
		return (TRUE);
	}
	return (FALSE);
}