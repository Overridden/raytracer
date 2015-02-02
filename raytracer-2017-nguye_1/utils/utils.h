/*
** utils.h for raytracer in /home/guedj_m//project/igraph/raytracer-2017-nguye_1/utils
**
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
**
** Started on  Mon May 27 16:13:16 2013 maxime guedj
** Last update Fri Jun  7 20:27:05 2013 maxime guedj
*/

#ifndef UTILS_H_
# define UTILS_H_

# define ESC 65307

t_scene		*scene_dup(t_scene *scene);
t_obj		*dup_obj(t_obj *cur);
t_scene		*scene_dup_light(t_scene *scene, t_scene *ret);
t_light		*dup_light(t_light *cur);

void		get_rgb(unsigned int color, int *dest);
void		add_color(int *dest, int *rgb, double coef);
void		mult_color(int *dest, double coef);
void		div_color(int *dest, int i);
unsigned int	c_color(int *rbg);

t_obj		*creat_obj(char type);
char		set_obj_pos(t_obj *obj, int x, int y, int z);
void		set_obj_rot(t_obj *obj , int x, int y, int z);
void		set_obj_n_rot(t_obj *obj, int x, int y, int z);
void		set_obj_param(t_obj *obj, int param);

t_light		*creat_light();
char		set_light_pos(t_light *light, int x, int y, int z);
void		set_light_color(t_light *light, int color);
void		free_light(t_light *light);

t_obj		*add_obj(t_obj *first, t_obj *elem);
void		free_obj(t_obj *obj);
void		free_all_obj(t_obj *list);

t_light		*add_light(t_light *first, t_light *elem);
void		free_all_light(t_light *list);

t_point		*creat_point(double x, double y, double z);
t_point		*dup_point(t_point *p);
void		cpy_point(t_point *src, t_point *dest);
void		free_point(t_point *p);

t_scene		*creat_scene();
void		free_all(t_scene *all);

int             set_color(unsigned int color, t_mlx *mlx, int x, int y);
int             gere_expose(t_mlx *mlx);
int             gere_key(int key, t_scene **scene);

#endif
