/*
** ext_check.c for img tceck ou especes in /home/cerini_j//current_project/raytracer-2017-nguye_1/parser
**
** Made by jeremy cerini
** Login   <cerini_j@epitech.net>
**
** Started on  Wed Jun  5 11:50:44 2013 jeremy cerini
** Last update Fri Jun  7 10:19:25 2013 maxime guedj
*/

#include <stdlib.h>
#include <string.h>
#include "raytracer.h"
#include "init.h"

char	verif_ext(t_obj *objet)
{
  if (objet->texture.texture_name != NULL &&
      strcmp(objet->texture.texture_name + strlen(objet->texture.texture_name)
	     - 4, ".xpm") != 0)
    return (EXIT);
  return (CONTINUE);
}
