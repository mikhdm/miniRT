#include "canvas.h"
#include "utils.h"
#include "parsing/errors.h"
#include "parsing/parse.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

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

	/* TODO */
	/* MOCK DATA */

	t_screen		*screen;
	screen = malloc(sizeof(t_screen));
	screen->width = 1024;
	screen->height = 768;
	screen->title = "miniRT";

	data->screen = screen;

	t_camera		*cam;
	cam = malloc(sizeof(t_camera));
	cam->center.x = 5;
	cam->center.y = 10;
	cam->center.z = 20;
	cam->orient.x = -1/sqrt(6);
	cam->orient.y = -1/sqrt(6);
	cam->orient.z = -2/sqrt(6);
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
	ambience->intensity = 0.2;
	data->ambience = ambience;

	t_light			*light;

	light = malloc(sizeof(t_light));
	light->brightness = 1.0;
	light->color = 0xffff00;
	light->center = (t_vector3) {.x = 0, .y = 10, .z = 5};
	light->next = NULL;
	data->light = light;

	t_plane			*plane;
	plane = malloc(sizeof(t_plane));
	plane->center = (t_vector3) {.x = 0, .y = -1, .z = 0};
	plane->color = 0xffffff;
	plane->orient = (t_vector3) {.x = 0, .y = 1, .z = 0};

	t_figure		*figure2;
	figure2 = malloc(sizeof(t_figure));
	figure2->content = plane;
	figure2->label = LABEL_PLANE;
	figure2->next = NULL;

	t_sphere		*sphere;
	sphere = malloc(sizeof(t_sphere));
	sphere->center = (t_vector3) {.x = 0, .y = 0, .z = 2};
	sphere->color = 0xcc0000;
	sphere->diameter = 6;

	t_figure    *figure1;
	figure1 = malloc(sizeof(t_figure));
	figure1->content = sphere;
	figure1->label = LABEL_SPHERE;
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