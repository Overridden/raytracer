/*
** lib.h for lib in /home/dovan_n//svn/raytracer-2017-nguye_1/lib
**
** Made by noel dovan
** Login   <dovan_n@epitech.net>
**
** Started on  Wed May 29 13:55:14 2013 noel dovan
** Last update Fri Jun  7 10:42:35 2013 maxime guedj
*/

#ifndef LIB_H_
# define LIB_H_

# define BUFF 1000

typedef struct	s_gnl
{
  int		pos;
  int		size_all;
  char		*str;
}		t_gnl;

char		*get_next_line(const int fd);
char		*init_buff(char *buff, int *i, int *size_read, const int fd);
char		*init_other(int *pos, int *size_all, int size_read);
char		*my_clear(char *str, int size);
char		*my_realloc(char *str, int size);
int		check_to_ret(t_gnl all, char *buff, int *i);

int		my_putnbr(int nb);
int		my_putstr(char *str);
int		my_putchar(char c);

int		my_strlen(char *str);
int		str_contain(char *str, char c);

int		getnbr_base(char *str, char *base);

int		my_pow_it(int nb, int i);
double		square(double value);
double		convert_to_rad(int value);

char		*my_epure_str(char *str);

#endif
