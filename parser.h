#ifndef PARSER_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "gnl/get_next_line.h"

typedef struct s_ambient
{
    double intensity;
    int color[3];
} t_ambient;

typedef struct s_camera
{
    double pos[3];
    double orientation[3];
    double fov;
} t_camera;

typedef struct s_light
{
    double pos[3];
    double intensity;
    int color[3];
    struct s_light *next;
} t_light;

typedef struct s_object
{
    char type[3];
    double pos[3];
    double orientation[3];
    double radius;
    double height;
    int color[3];
    struct s_object *next;
} t_object;

typedef struct s_scene
{
    t_ambient ambient;
    t_camera camera;
    t_light *lights;
    t_object *objects;
} t_scene;

char	**ft_split(char const *str, char c);
double      ft_atof(char *str);
int	ft_atoi(const char *nptr);
int	ft_isprint(int c);
void	free_split(char **tok);
void	convert_vec(char *str, double *vec);
void	convert_color(char *str, int *color);
void	parse_light(char *str, t_scene *scene);
void	parse_camera(char *str, t_scene *scene);
void	creat_ambient(char *str, t_scene *scene);
void	parse_sphere(char *str, t_scene *scene);
void free_objects(t_object *obj);
void free_lights(t_light *light);

#endif