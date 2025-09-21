#include "parser.h"

void parse_sphere(char *str, t_scene *scene)
{
    char      **tok;
    t_sphere  *sp;
    int       i;

    tok = ft_split(str, ' ');
    i = 0;
    while (tok[i])
        i++;
    if (i != 4)
    {
        free_split(tok);
        exit(printf("argumentos errados pra esfera paizao\n"));
    }
    sp = malloc(sizeof(t_sphere));
    if (!sp)
        exit(printf("malloc falhou paizao\n"));
    convert_vec(tok[1], sp->pos);
    sp->radius = ft_atof(tok[2]) / 2.0;
    convert_color(tok[3], sp->color);
    sp->next = scene->spheres;
    scene->spheres = sp;
    free_split(tok);
}


void parse_plane(char *str, t_scene *scene)
{
    char     **tok;
    t_plane  *pl;
    int       i;

    tok = ft_split(str, ' ');
    i = 0;
    while (tok[i])
        i++;
    if (i != 4)
    {
        free_split(tok);
        exit(printf("argumentos errados pro plano paizao\n"));
    }
    pl = malloc(sizeof(t_plane));
    if (!pl)
        exit(printf("malloc falhou paizao\n"));
    convert_vec(tok[1], pl->pos);
    convert_vec(tok[2], pl->orientation);
    convert_color(tok[3], pl->color);
    pl->next = scene->planes;
    scene->planes = pl;
    free_split(tok);
}

void parse_cylinder(char *str, t_scene *scene)
{
    char        **tok;
    t_cylinder  *cy;
    int         i;

    tok = ft_split(str, ' ');
    i = 0;
    while (tok[i])
        i++;
    if (i != 6)
    {
        free_split(tok);
        exit(printf("argumentos errados pro cilindro paizao\n"));
    }
    cy = malloc(sizeof(t_cylinder));
    if (!cy)
        exit(printf("malloc falhou paizao\n"));
    convert_vec(tok[1], cy->pos);
    convert_vec(tok[2], cy->orientation);
    cy->radius = ft_atof(tok[3]) / 2.0;
    cy->height = ft_atof(tok[4]);
    convert_color(tok[5], cy->color);
    cy->next = scene->cylinders;
    scene->cylinders = cy;
    free_split(tok);
}
