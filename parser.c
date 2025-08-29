#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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

void	parser_rt(char *file)
{
	int	fd;

	fd = verify_file(file);
	printf("deu certo paizao 👍: %d", fd);
	close (fd);
}


int main(int ac, char **av)
{
	if (ac != 2)
		printf("ta errado isso ai");
	parser_rt(av[1]);
}