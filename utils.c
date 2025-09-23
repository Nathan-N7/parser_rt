#include "parser.h"


int	check_commas(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	if (str[0] == ',' || str[ft_strlen(str) - 1] == ',')
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == ',' && str[i + 1] == ',')
			return (0);
		i++;
	}
	return (1);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

void	free_split(char **tok)
{
	int	i;

	if (!tok)
		return ;
	i = 0;
	while (tok[i])
		free(tok[i++]);
	free(tok);
}

int convert_vec(char *str, double *vec)
{
    char **tok;
    int i;

    if (!check_commas(str))
		return (printf("vetor invalido paizao\n"), 0);
    tok = ft_split(str, ',');
    i = 0;
    while (tok[i])
        i++;
    if (i != 3)
    {
        free_split(tok);
        return (printf("vetor invalido paizao\n"), 0);
    }
    vec[0] = ft_atof(tok[0]);
    vec[1] = ft_atof(tok[1]);
    vec[2] = ft_atof(tok[2]);
    free_split(tok);
    return (1);
}


int	convert_color(char *str, int *color)
{
	char	**tok;
	int		i;

    if (!check_commas(str))
		return (printf("cor invalida paizao\n"), 0);
    tok = ft_split(str, ',');
	i = 0;
	while (tok[i])
		i++;
	if (i != 3)
    {
        free_split(tok);
		return (printf("cor invalida paizao\n"), 0);
    }
	color[0] = ft_atoi(tok[0]);
	color[1] = ft_atoi(tok[1]);
	color[2] = ft_atoi(tok[2]);
	free_split(tok);
    return (1);
}

void free_lights(t_light *light)
{
    t_light *tmp;
    while (light)
    {
        tmp = light->next;
        free(light);
        light = tmp;
    }
}

void free_spheres(t_sphere *s)
{
    t_sphere *tmp;
    while (s)
    {
        tmp = s->next;
        free(s);
        s = tmp;
    }
}

void free_planes(t_plane *p)
{
    t_plane *tmp;
    while (p)
    {
        tmp = p->next;
        free(p);
        p = tmp;
    }
}

void	free_cylinders(t_cylinder *cy)
{
	t_cylinder *tmp;

	while (cy)
	{
		tmp = cy->next;
		free(cy);
		cy = tmp;
	}
}

void	all_free(t_scene *scene)
{
	free_spheres(scene->spheres);
    free_planes(scene->planes);
    free_lights(scene->lights);
	free_cylinders(scene->cylinders);
}

