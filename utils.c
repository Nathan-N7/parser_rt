#include "parser.h"


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

void	convert_vec(char *str, double *vec)
{
	char	**tok;
	int		i;

	tok = ft_split(str, ',');
	i = 0;
	while (tok[i])
		i++;
	if (i != 3)
		exit(printf("vetor invalido paizao\n"));
	vec[0] = ft_atof(tok[0]);
	vec[1] = ft_atof(tok[1]);
	vec[2] = ft_atof(tok[2]);
}

void	convert_color(char *str, int *color)
{
	char	**tok;
	int		i;

	tok = ft_split(str, ',');
	i = 0;
	while (tok[i])
		i++;
	if (i != 3)
		exit(printf("cor invalida paizao\n"));
	color[0] = ft_atoi(tok[0]);
	color[1] = ft_atoi(tok[1]);
	color[2] = ft_atoi(tok[2]);
	free_split(tok);
}