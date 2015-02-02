/*
** calc.h for raytracer in /home/guedj_m//project/igraph/raytracer-2017-nguye_1/calc
**
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
**
** Started on  Tue May 28 13:53:03 2013 maxime guedj
** Last update Sun Jun  9 17:00:36 2013 noel dovan
*/

#ifndef CALC_H_
# define CALC_H_

t_point		*get_norm(t_obj *obj);
double		calc_cos(t_obj *obj, t_point *vlight);

t_obj		*get_the_nearest(t_obj *obj);
void		get_the_distance(t_scene *scene, t_point *init_vect);
void		set_inter_point(t_point *eye, t_obj *obj, t_point *vect);
t_obj		*find_the_object(t_scene *scene, double x, double y);

int		get_clean_pixel(t_scene *scene, double x, double y);
int		get_pixel_color(t_scene *scene, double x, double y);

int		light_the_color(t_scene *scene, t_obj *n_obj, int color);
void		init_color(int color, int *o_rgb, int *r_rgb);
void		fill_l_rgb(int *l_rgb, t_light *tmp, t_obj *n_obj, int *o_rgb);
t_point		*get_vlight(t_obj *obj, t_light *light);
int		disturbance(t_obj *n_obj, int color);
double		get_coef(t_scene *scene, t_obj *obj, t_light *light);

void		set_new_eye(t_point *dest, t_obj *obj, t_point *pos);
void		set_new_eye_n(t_point *dest, t_obj *obj, t_obj *tmp,
			      t_point *pos);

int		check_limit(t_point *eye, t_point *vect, t_obj *obj);
int		check_shadow(t_scene *scene, t_obj *n_obj, t_point *vlight,
			     t_obj *tmp);
void		reset_tmp(t_point *tmp, t_obj *o_tmp, t_obj *n_obj);
void		double_rot(t_point *dest, t_obj *n_obj, t_obj *tmp);
int		return_n_free(int ret, t_point *p1, t_point *p2, t_point *p3);

t_point		*get_init_vect(double x, double y);
void		m_i_rot_mult(t_point *vect, t_obj *obj);
void		m_n_rot_mult(t_point *vect, t_obj *obj);
t_point		*c_n_rot_mult(t_point *vect, t_obj *obj);
t_point		*c_i_rot_mult(t_point *vect, t_obj *obj);

void		solve2(double a, double b, double c, t_obj *obj);

#endif
