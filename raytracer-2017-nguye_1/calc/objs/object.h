/*
** object.h for object in /home/dovan_n//svn/raytracer-2017-nguye_1/objs
**
** Made by noel dovan
** Login   <dovan_n@epitech.net>
**
** Started on  Mon May 27 17:35:54 2013 noel dovan
** Last update Sun Jun  9 16:32:01 2013 noel dovan
*/

#ifndef OBJECT_H_
# define OBJECT_H_

/* sphere.c */
double		sphere_c(t_point *eye, double par);
double		sphere_b(t_point *eye, t_point *vector);
double		sphere_a(t_point *vector);
void		obj_sphere(t_point *eye, t_point *vector, t_obj *obj);
void		sphere_norm(t_obj *obj, t_point *vector);

/* sphere_color.c */
int		sphere_color(t_obj *obj);
int		dam_sphere(t_obj *obj, double phi, double theta);
int		ray_sphere(t_obj *obj, double phi, double theta);
int		text_sphere(t_obj *obj, double phi, double theta);

/* cylinder.c */
double		cylinder_c(t_point *eye, double par);
double		cylinder_b(t_point *eye, t_point *vector);
double		cylinder_a(t_point *vector);
void		obj_cylinder(t_point *eye, t_point *vector, t_obj *obj);
void		cylinder_norm(t_obj *cylin, t_point *vect);

/* cylinder_color.c */
int		cylinder_color(t_obj *obj);
int		dam_cylinder(t_obj *obj, double theta, int damier_y);
int		ray_cylinder(t_obj *obj, double theta, int damier_y);
int		text_cylinder(t_obj *obj, double theta);

/* plane.c */
double		calcul_place(double eyez, double vectorz);
void		obj_plane(t_point *eye, t_point *vector, t_obj *obj);
void		plane_norm(t_obj *obj, t_point *vector);

/* plane_color.c */
int		plane_color(t_obj *obj);
int		dam_plane(t_obj *obj);
int		ray_plane(t_obj *obj);
int		text_plane(t_obj *obj);

/* cone.c */
double		cone_c(t_point *eye, double par);
double		cone_b(t_point *eye, t_point *vector, double par);
double		cone_a(t_point *vector, double par);
void		obj_cone(t_point *eye, t_point *vector, t_obj *obj);
void		cone_norm(t_obj *obj, t_point *vector);

/* texture.c */
int		texture_load(t_scene *scene, void *mlx_ptr);
int		get_color_from_img(int x, int y, void *img_ptr,
				   int sizeline_bpp[2]);
int		cone_color(t_obj *obj);
int		cylinder_color(t_obj *obj);
t_obj		*put_texture_data(t_obj *obj, void *mlx_ptr);

#endif
