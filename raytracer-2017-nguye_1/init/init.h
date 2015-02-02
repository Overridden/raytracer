/*
** init.h for raytracer in /home/guedj_m//project/igraph/raytracer-2017-nguye_1/init
**
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
**
** Started on  Fri Jun  7 10:13:06 2013 maxime guedj
** Last update Sun Jun  9 14:13:10 2013 jeremy cerini
*/

#ifndef INIT_H_
# define INIT_H_

t_mlx		*init_mlx();

# define POS 1
# define TYPE_COLOR 2
# define ROT 4
# define COLOR 8
# define PARAM 16
# define LIMIT 32
# define TEXTURE 64
# define BRIGHT 128
# define COLOR_SEC 256
# define INTENSITY 512
# define NORMAL 1024

# define CONE "cone "
# define CYLI "cylinder "
# define PLAN "plane "
# define SPHE "sphere "
# define EYE "eye "
# define LIGT "light "

# define STR_POS "position "
# define STR_C_T "color_type "
# define STR_ROT "rotation "
# define STR_COLOR "color "
# define STR_PARAM "param "
# define STR_LIM "limit "
# define STR_TEX "texture "
# define STR_BRI "shine "
# define STR_C_N "color_annex "

# define EXIT_ERR -1
# define EXIT 0
# define CONTINUE 1

# define IS_MINUS(x) ((x == '-') ? 1 : 0)

typedef struct	s_tabs
{
  char		(*tabl[2])(t_light *objet, char *buff);
  char		*linel[3];
  char		(*tabo[9])(t_obj *objet, char *buff);
  char		*lineo[10];
}		t_tabs;

/*			in main_parser.c	*/
t_scene			*main_parser(char *);
char			get_next_obj(t_scene *scene, char **line,
				     int fd, t_tabs *tabs);
char			get_type(char *buff);
/**/
/*			in error_pars.c		*/
char			*error_open_pars(int);
char			*error_malloc_pars(int);
char			*error_read_pars(int);
char			*buf_to_long(int);
/**/
/*			in setscene.c		*/
char			set_object(int fd, char **current,
				   t_obj *objet, t_tabs *tabs);
char			set_light(int fd, char **current,
				  t_light *lumiere, t_tabs *tabs);
void			set_tab_light(t_tabs *tabs);
void			set_tab_obj(t_tabs *tabs);
char			add_to_current(int fd, t_scene *scene,
				       char **line, t_tabs *tabs);
/**/
/*			in pars_other.c		*/
char			get_sec_color(t_obj *objet, char *buff);
char			get_color_type(t_obj *objet, char *buff);
char			get_brightness(t_obj *objet, char *buff);
char			get_limit(t_obj *objet, char *buff);
/**/
/*			in pars_objs.c		*/
char			get_pos(t_obj *objet, char *buff);
char			get_param(t_obj *objet, char *buff);
char			get_color(t_obj *objet, char *buff);
char			get_rot(t_obj *objet, char *buff);
char			get_texture(t_obj *objet, char *buff);
/**/
/*			in pars_lights.c		*/
char			get_pos_l(t_light *objet, char *buff);
char			get_color_l(t_light *objet, char *buff);
char			get_param_l(t_light *objet, char *buff);
/**/
/*			in verif_final.c	*/
unsigned int		*creat_tab_verif();
void			verif_light(t_scene *, unsigned int *);
int			verid_eye(t_obj *, unsigned int *);
void			verif_obj(t_scene *, unsigned int *);
t_scene			*verif_final(t_scene *);
/**/
/*			in error_parser.c	*/
int			error_eyes(int);
/**/
/*			in delete_elem.c	*/
void			del_elem_light(t_scene *, t_light *);
void			del_elem_obj(t_scene *, t_obj *);
t_scene			*free_all_elem(t_scene *);
/**/
/*			in chek_eye.c		*/
void			eye_other_place(t_scene *scene, t_obj *eye);
void			eye_first_place(t_scene *scene);
int			check_eye(t_scene *);
/**/
/*			in ext_check.c		*/
char			verif_ext(t_obj *objet);

#endif
