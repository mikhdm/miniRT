#include "canvas.h"
#include "utils.h"
#include "parsing/errors.h"
#include "parsing/parse.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

#include <math.h>

static t_data *build(int const fildes)
{
	t_data  *data;

	data = NULL;
	if (!alloca_to((void*)&data, sizeof(t_data)))
	{
		close(fildes);
		exit(ENOMEM);
	}

	char *line;

	line = NULL;
	while (get_next_line(fildes, &line) != SIG_EOF)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	close(fildes);
	/* MOCK DATA */

	t_screen		*screen;
	screen = malloc(sizeof(t_screen));
	screen->width = 1024;
	screen->height = 768;
	screen->title = "miniRT";

	data->screen = screen;

	t_camera		*cam;
	cam = malloc(sizeof(t_camera));
	cam->center.x = 0;
	cam->center.y = 2;
	cam->center.z = -10;
	cam->orient.x = 0;
	cam->orient.y = 0;
	cam->orient.z = 1;
	cam->fov = 90;

	t_viewport      *viewport;
	viewport = malloc(sizeof(t_viewport));
	*viewport = calc_viewport(data, cam);
	cam->viewport = viewport;
	cam->next = NULL;

	data->cam = cam;

	t_ambience		*ambience;

	ambience = malloc(sizeof(t_ambience));
	ambience->color = 0xffffff;
	ambience->intensity = 0.8;
	data->ambience = ambience;

	t_light			*light;

	light = malloc(sizeof(t_light));
	light->brightness = 1.0;
	light->color = 0xffffff;
	light->center = (t_vector3) {.x = 0, .y = 2, .z = 1.5};
	light->next = NULL;
	data->light = light;

	t_plane			*plane;
	plane = malloc(sizeof(t_plane));
	plane->center = (t_vector3) {.x = 0, .y = -2, .z = 0};
	plane->color = 0xffffff;
	plane->orient = (t_vector3) {.x = 0, .y = 1, .z = 0};

	t_figure		*figure2;
	figure2 = malloc(sizeof(t_figure));
	figure2->content = plane;
	figure2->label = LABEL_PLANE;
	figure2->next = NULL;

	t_cylinder      *cylinder;
	cylinder = malloc(sizeof(t_cylinder));
	cylinder->center = (t_vector3){.x = 0, .y = 1, .z = 4};
	cylinder->orient = (t_vector3){.x = 0, .y = 1, .z = 0};
	cylinder->color = 0xffff00;
	cylinder->diameter = 4.0;
	cylinder->height = 6.0;

	t_figure    *figure1;
	figure1 = malloc(sizeof(t_figure));
	figure1->content = cylinder;
	figure1->label = LABEL_CYLINDER;
	figure1->next = figure2;

	data->figures = figure1;
	data->mlx = NULL;
	data->window = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->bpp = 0;
	data->length = 0;
	data->endian = 0;

	/* END MOCK */

	return (data);
}

t_data *parse(char const *path)
{
	int     fd;
	t_data  *data;

	data = NULL;
	if (!path)
		ft_perror(ERROR_PATH_EMPTY);
	fd = open(path, O_RDONLY);
	if (isdir(fd) || (fd == -1))
	{
		ft_perror(ERROR_ERRNO);
		exit(errno);
	}
	data = build(fd);
	close(fd);
	return (data);
}

void cleanup(t_data *data)
{
	/* TODO cleanup all data */
	free(data);
}