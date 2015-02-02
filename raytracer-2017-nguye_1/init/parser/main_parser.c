/*
** main_parser.c for  in /home/lastru_g//svn/rt/parser
**
** Made by gael lastrucci
** Login   <lastru_g@epitech.net>
**
** Started on  Thu May 23 13:32:28 2013 gael lastrucci
** Last update Sun Jun  9 14:24:19 2013 jeremy cerini
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "raytracer.h"
#include "lib.h"
#include "init.h"
#include "utils.h"

t_tabs		*init_tabs()
{
  t_tabs	*tabs;

  if ((tabs = malloc(sizeof(*tabs))) == NULL)
    return (NULL);
  tabs->lineo[0] = NULL;
  tabs->linel[0] = NULL;
  return (tabs);
}

t_scene		*main_parser(char *fill_name)
{
  t_scene	*scene;
  int		fd;
  char		*buf;
  char		ok;
  t_tabs	*tabs;

  scene = NULL;
  ok = 1;
  if ((fd = open(fill_name, O_RDONLY)) < 0 ||
      (scene = creat_scene()) == NULL
      || (tabs = init_tabs()) == NULL)
    return (NULL);
  while ((buf = my_epure_str(get_next_line(fd))) != NULL
	 && (buf[0] == 0 || buf[0] == ';' || buf[0] == '#'))
    free(buf);
  while (ok == CONTINUE && buf != NULL)
    ok = get_next_obj(scene, &buf, fd, tabs);
  free(tabs);
  if (ok == EXIT_ERR || (scene = verif_final(scene)) == NULL ||
      scene->eye == NULL || scene->obj == NULL)
    {
      write(2, "ERROR N°305 some objets are missing.\n", 38);
      return (NULL);
    }
  return (scene);
}

char		get_next_obj(t_scene *scene, char **line, int fd, t_tabs *tabs)
{
  char		type;
  char		ret;
  t_light	*lumiere;
  t_obj		*obj;

  if (line == NULL || *line == NULL)
    return (EXIT);
  type = get_type(*line);
  if (type == spot)
    {
      if ((lumiere = creat_light()) == NULL)
	return (EXIT_ERR);
      if ((ret = set_light(fd, line, lumiere, tabs)) != EXIT_ERR)
	scene->light = add_light(scene->light, lumiere);
    }
  else if (type == erreur)
    ret = add_to_current(fd, scene, line, tabs);
  else
    {
      if ((obj = creat_obj(type)) == NULL)
	return (EXIT_ERR);
      if ((ret = set_object(fd, line, obj, tabs)) != EXIT_ERR)
	scene->obj = add_obj(scene->obj, obj);
    }
  return (ret);
}

int		size_min(char *str, char *buff)
{
  if (strlen(buff) > strlen(str))
    return (strlen(str));
  return (strlen(buff));
}

char		get_type(char *buff)
{
  char		*obj[7];
  int		i;

  obj[0] = SPHE;
  obj[1] = CYLI;
  obj[2] = PLAN;
  obj[3] = CONE;
  obj[4] = EYE;
  obj[5] = LIGT;
  obj[6] = NULL;
  i = 0;
  while (obj[i] != NULL && strncmp(obj[i], buff, size_min(buff, obj[i])) != 0)
    ++i;
  if (buff[0] == 0)
    i = 6;
  return (sphere + i);
}
