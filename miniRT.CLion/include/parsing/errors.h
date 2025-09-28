#ifndef ERRORS_H
# define ERRORS_H

# define ERROR_HEADER   "ERROR\n"
# define ERROR_ERRNO    -1

typedef enum e_error
{
	ERROR_PATH_EMPTY = 0,
	ERROR_PATH_PARAM_EMPTY,
	ERROR_SCREENSHOT_PARAM_WRONG,
	ERROR_NUM_ARGS_WRONG,
	ERROR_DATA_RESOLUTION,
	ERROR_DATA_AMBIENCE
}   t_error;

void    ft_perror(unsigned code);

#endif