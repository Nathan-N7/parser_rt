#include "parser.h"

int	verify_file(char *file)
{
	int	fd;
	int	i;
	int cmp;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("deu ruim no fd paizao");
		exit(-1);
	}
	i = strlen(file);
	i -= 3;
	cmp = strcmp(&file[i], ".rt");
	if (cmp != 0)
	{
		printf("o arquivo nao e .rt paizao");
		exit (-1);	
	}
	return (fd);
}

void	read_file(int fd, t_scene *scene)
{
	int		i;
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		i = 0;
		while (str[i] == 32 || (str[i] > 6 && str[i] < 14))
			i++;
		if (str[i] == '\0')
		{
			free(str);
			str = get_next_line(fd);
			continue ;
		}
		if (str[i] >= 32 && str[i] <= 126)
		{
			if (str[i] == 'A')
				creat_ambient(&str[i], scene);
			else if (str[i] == 'C')
				parse_camera(&str[i], scene);
			else if (str[i] == 'L')
				parse_light(&str[i], scene);
			else if (str[i] == 's' && str[i + 1] == 'p')
				parse_sphere(&str[i], scene);
			else if (str[i] == 'p' && str[i + 1] == 'l')
				printf("Plano 👍\n");
			else if (str[i] == 'c' && str[i + 1] == 'y')
				printf("Cilindro 👍\n");
			else
				exit(printf("tem prefixo errado ai paizao\n"));
		}
		free(str);
		str = get_next_line(fd);
	}
}

void	parser_rt(char *file, t_scene *scene)
{
	int	fd;

	fd = verify_file(file);
	scene->lights = NULL;
	scene->objects = NULL;
	read_file(fd, scene);
	close(fd);
}

int	main(int ac, char **av)
{
	t_scene	scene;

	if (ac != 2)
		return (printf("ta errado isso ai\n"), 1);
	parser_rt(av[1], &scene);
	printf("Sphere -> pos: %.2f, %.2f, %.2f | radius: %.2f | color: %d,%d,%d\n",
    scene.objects->pos[0],
    scene.objects->pos[1],
    scene.objects->pos[2],
    scene.objects->radius,
    scene.objects->color[0],
    scene.objects->color[1],
    scene.objects->color[2]);
}