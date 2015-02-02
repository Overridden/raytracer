##
## Makefile for raytracer in /home/guedj_m//project/igraph/raytracer-2017-nguye_1
##
## Made by maxime guedj
## Login   <guedj_m@epitech.net>
##
## Started on  Mon May 27 16:18:52 2013 maxime guedj
## Last update Sun Jun  9 16:36:19 2013 noel dovan
##

NAME	= rt

SRCS	= main.c			\
	multithread.c			\
	init/init_mlx.c			\
	init/parser/main_parser.c	\
	init/parser/pars_lights.c	\
	init/parser/pars_other.c	\
	init/parser/pars_objs.c		\
	init/parser/setscene.c		\
	init/parser/check_eye.c		\
	init/parser/delete_elem_list.c	\
	init/parser/verif_final.c	\
	init/parser/error_parser.c	\
	init/parser/ext_check.c		\
	calc/vect_func.c		\
	calc/get_pixel_color.c		\
	calc/set_new_pos.c		\
	calc/cosinus.c			\
	calc/light.c			\
	calc/shadow.c			\
	calc/calc_inter.c		\
	calc/objs/sphere.c		\
	calc/objs/sphere_color.c	\
	calc/objs/cylinder.c		\
	calc/objs/cylinder_color.c	\
	calc/objs/plane.c		\
	calc/objs/plane_color.c		\
	calc/objs/cone.c		\
	calc/objs/texture.c		\
	calc/objs/get_color.c		\
	calc/solver/solver2.c		\
	utils/set_colors.c		\
	utils/event.c			\
	utils/obj_func.c		\
	utils/obj_list_func.c		\
	utils/light_func.c		\
	utils/light_list_func.c		\
	utils/point_func.c		\
	utils/scene_func.c		\
	utils/color.c			\
	utils/scene_dup.c		\
	lib/str_func.c			\
	lib/getnbr_base.c		\
	lib/math_func.c			\
	lib/my_epure_str.c		\
	lib/my_put.c			\
	lib/GNL/get_next_line.c		\
	lib/GNL/gnl_suppli.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -W -Wall -Werror -Wextra \
	-I. -Iutils/ -Iinit/ -Icalc/ -Icalc/objs -Ilib

CCLIB	= -lm -L/usr/lib64 -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11 \
	-lpthread

RM	= rm -f

$(NAME):	$(OBJS)
	cc -o $(NAME) $(OBJS) $(CCLIB)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: 	fclean $(NAME)
