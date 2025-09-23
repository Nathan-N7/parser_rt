#include "parser.h"

void	creat_ambient(char *str, t_scene *scene)
{
	char	**tok;
	int		i;

	tok = ft_split(str, ' ');
	i = 0;
	while (tok[i])
		i++;
	if (i != 3)
	{
		free_split(tok);
		all_free(scene);
		exit(printf("argumentos errados pro ambient paizao\n"));
	}
	scene->ambient.intensity = ft_atof(tok[1]);
	convert_color(tok[2], scene->ambient.color);
	free_split(tok);
}

void	parse_camera(char *str, t_scene *scene)
{
	char	**tok;
	int		i;

	tok = ft_split(str, ' ');
	i = 0;
	while (tok[i])
		i++;
	if (i != 4)
	{
		free_split(tok);
		all_free(scene);
		exit(printf("argumentos errados pra camera paizao\n"));
	}
	convert_vec(tok[1], scene->camera.pos);
	convert_vec(tok[2], scene->camera.orientation);
	scene->camera.fov = ft_atof(tok[3]);
	free_split(tok);
}

void	parse_light(char *str, t_scene *scene)
{
	char	**tok;
	t_light	*light;
	int		i;

	tok = ft_split(str, ' ');
	i = 0;
	while (tok[i])
		i++;
	if (i != 4)
	{
		free_split(tok);
		all_free(scene);
		exit(printf("argumentos errados pra luz paizao\n"));
	}
	light = malloc(sizeof(t_light));
	if (!light)
		exit(printf("malloc falhou paizao\n"));
	convert_vec(tok[1], light->pos);
	light->intensity = ft_atof(tok[2]);
	convert_color(tok[3], light->color);
	light->next = scene->lights;
	scene->lights = light;
	free_split(tok);
}
