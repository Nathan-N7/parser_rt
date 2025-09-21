#include "parser.h"

void	parse_sphere(char *str, t_scene *scene)
{
	char		**tok;
	t_object	*obj;
	int			i;

	tok = ft_split(str, ' ');
	i = 0;
	while (tok[i])
		i++;
	if (i != 4)
    {
        free_split(tok);
		exit(printf("argumentos errados pra esfera paizao\n"));
    }
	obj = malloc(sizeof(t_object));
	if (!obj)
		exit(printf("malloc falhou paizao\n"));
	strlcpy(obj->type, "sp", 3);
	convert_vec(tok[1], obj->pos);
	obj->radius = ft_atof(tok[2]) / 2.0;
	convert_color(tok[3], obj->color);
	obj->next = scene->objects;
	scene->objects = obj;
	free_split(tok);
}