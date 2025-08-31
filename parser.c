#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "gnl/get_next_line.h"

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

void	read_file(int fd)
{
	int	i;
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		i = 0;
		while (str[i] == 32 || (str[i] > 6 && str[i] < 14))
			i++;
		if ((str[i] > 96 && str[i] < 123) || (str[i] > 64 && str[1] < 91))
		{
			if (str[i] == 'A')
				printf("Luz ambiente 👍\n");
			else if (str[i] == 'C')
				printf("Camera 👍\n");
			else if (str[i] == 'L')
				printf("Luz 👍\n");
			else if (str[i] == 's' && str[i + 1] == 'p')
				printf("Esfera 👍\n");
			else if (str[i] == 'p' && str[i + 1] == 'l')
				printf("Plano 👍\n");
			else if (str[i] == 'c' && str[i + 1] == 'y')
				printf("Cilindro 👍\n");
			else
				exit(printf("tem prefixo errado ai paizao"));
		}
		free(str);
		str = get_next_line(fd);
	}
}

void	parser_rt(char *file)
{
	int	fd;

	fd = verify_file(file);
	read_file(fd);
	close (fd);
}


int main(int ac, char **av)
{
	if (ac != 2)
		return (printf("ta errado isso ai"), 1);
	parser_rt(av[1]);
}